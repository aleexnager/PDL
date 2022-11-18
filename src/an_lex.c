#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"
#include "ts2006.h"

// FUNCION QUE IMPLEMENTA EL FUNCIONAMIENTO DE ANALIZADOR LÉXICO, SU FUNCIÓN ES LEER DESDE UN FP, HABIENDO
// LEIDO YA UN CARÁCTER Y GENERAR UN TOKEN O GENERAR UN ERROR

//* Ideas:
//* - an_lex deberá devolver el [FILE *] del fichero fuente
//* - cuando se transiciona con otro carácter, hay que mover hacia atrás
//*   el file pointer, para que cuando vuelva a entrar en el método se
//*   encuentre con el mismo carácter, ya que al principio del método
//*   siempre leemos.
//* - fseek(input_file, -1, SEEK_CUR);

/*
    EJEMPLO:
    let a int = 457;

    Cuando encuentre el token let, tiene que leer el siguiente carácter, entonces cuando
    vuelva a entrar en el método, lo primero que hace es leer el siguiente. Este caso está
    cubierto.

    Siguiendo la misma lógica, cuando se transiciona con otro carácter, por ejemplo en 457;
    Cuando lee el ; genera el token 457, pero tiene que volver a entrar al método con el ;
    Sin embargo, como ya lo ha leído antes, el puntero estará apuntando al carácter siguiente
    a ;

    Por ello, usamos fseek(input_file, -1, SEEK_CUR) retrocedemos el puntero para que cuando lea
    vuelva a encontrarse el ;

    Espero que se entienda :)
*/

//! FILE *an_lex(FILE *fd_input_file, int id_tabla, token_t *token)

//? PARAMS:
//? - FILE *fd_input_file: puntero al fichero fuente desde el que empezará a leer
//? - int id_tabla: id de la tabla de símbolos a rellenar
//? - token

//? RETURN:
//? - FILE *: Devuelve el fd_input_file, modificado, para volver a llamar

char *token_file = "./data/output/token.txt";
char *ts_file = "./data/output/ts.txt";
char *error_file = "./data/output/error.txt";

FILE *an_lex(FILE *input_file, int id_tabla, token_t *token)
{
    FILE *fp2 = fopen(token_file, "a");
    FILE *fp3 = fopen(error_file, "w");

    if (fp2 == NULL || fp3 == NULL)
        exit(1);

    int estado;
    int accion;
    int linea = 1;
    char leido = fgetc(input_file);
    if (!feof(input_file))
    {
        estado = 0;
        char *lexema = (char *) malloc(65 * sizeof(char));
        memset(lexema, 0, 65);
        char *buf_linea = (char *) malloc(1024 * sizeof(char));
        memset(buf_linea, 0, 1024);
        int valor;
        int lexema_length;
        while (estado < 10)
        {
            accion = mt_afd_accion(estado, leido);
            estado = mt_afd_estado(estado, leido);

            if (estado == -1) {
                // Estado es -1 y acción 1, se ha leído un EOF
                // por tanto, se entra al if de estado pero no llama
                // a la función de generar error
                if (accion >= 50) {
                    fp3 = gen_error(fp3, accion, linea, leido, buf_linea);
                    fseek(input_file, -1, SEEK_CUR);
                    return input_file;
                }
                leido = fgetc(input_file);
                strncat(buf_linea, &leido, 1);
                estado = 0;
                break;
            } else {
                switch (accion) {
                    case A:
                    {
                        if (leido == '\n') {
                            ++linea;
                            memset(buf_linea, 0, 1024);
                            leido = fgetc(input_file);
                        } else {
                            leido = fgetc(input_file);
                            strncat(buf_linea, &leido, 1);
                        }
                        break;
                    }
                    case B:
                    {
                        lexema_length = 0;
                        leido = fgetc(input_file);
                        strncat(buf_linea, &leido, 1);
                        break;
                    }
                    case C:
                    {
                        if (lexema_length >= 64)
                            lexema = (char *) realloc(lexema, lexema_length + (64 * sizeof(char)));

                        strncat(lexema, &leido, 1);
                        lexema_length++;
                        leido = fgetc(input_file);
                        strncat(buf_linea, &leido, 1);
                        break;
                    }
                    case D:
                    {
                        if (lexema_length < 65) {
                            token->type = 0;
                            token->id = CADENA;
                            token->lexema = lexema;
                            token->valor = -1;
                            fprintf(fp2, "<%d, \'%s\'>\n", token->id, token->lexema);
                        } else {
                            fp3 = gen_error_string(fp3, linea, lexema, buf_linea);
                        }
                        strncat(buf_linea, &leido, 1);
                        return input_file;
                    }
                    case E:
                    {
                        valor = leido - '0';
                        leido = fgetc(input_file);
                        strncat(buf_linea, &leido, 1);
                        break;
                    }
                    case F:
                    {
                        valor = (valor * 10) + (leido - '0');
                        leido = fgetc(input_file);
                        strncat(buf_linea, &leido, 1);
                        break;
                    }
                    case G:
                    {
                        if (valor < 32768) {
                            token->type = 1;
                            token->id = CTE_ENTERA;
                            token->valor = valor;
                            token->lexema = NULL;
                            fprintf(fp2, "<%d, %d>\n", token->id, token->valor);
                        } else {
                            fp3 = gen_error_int(fp3, linea, valor, buf_linea);
                        }
                        fseek(input_file, -1, SEEK_CUR);
                        return input_file;
                    }
                    case H:
                    {
                        strncat(lexema, &leido, 1);
                        leido = fgetc(input_file);
                        strncat(buf_linea, &leido, 1);
                        break;
                    }
                    case I:
                    {
                        if (lexema_length >= 64) {
                            lexema = (char *) realloc(lexema, lexema_length + (64 * sizeof(char)));
                        }
                        strncat(lexema, &leido, 1);
                        lexema_length++;
                        leido = fgetc(input_file);
                        strncat(buf_linea, &leido, 1);
                        break;
                    }
                    case J:
                    {
                        int pos_ts;
                        int id_pal_res = es_pal_res(lexema);

                        if (id_pal_res > -1) {
                            /* Si es palabra reservada gen token (lexema, -) */
                            token->type = 0;
                            token->id = id_pal_res;
                            token->lexema = "";
                            token->valor = -1;
                            fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        } else if ( (pos_ts = buscar_posicion_entrada(id_tabla, lexema)) != 0) {
                            /* Si está en la ts gen token (ID, pos_ts) */
                            token->type = 1;
                            token->id = ID;
                            token->valor = pos_ts;
                            token->lexema = NULL;
                            fprintf(fp2, "<%d, %d>\n", token->id, token->valor);    
                        } else {
                            /* si no está en la ts insertar() y gen token (ID, pos_ts) */
                            crear_entrada(id_tabla, lexema);
                            token->type = 1;
                            token->id = ID;
                            token->valor = buscar_posicion_entrada(id_tabla, lexema);
                            token->lexema = NULL;
                            fprintf(fp2, "<%d, %d>\n", token->id, token->valor);
                            escribir_tabla(id_tabla, ts_file);
                        }
                        fseek(input_file, -1, SEEK_CUR);
                        return input_file;
                    }
                    case K:
                    {
                        token->type = 0;
                        token->id = OP_MODULO;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        fseek(input_file, -1, SEEK_CUR);
                        return input_file;
                    }
                    case L:
                    {
                        leido = fgetc(input_file);
                        token->type = 0;
                        token->id = OP_MOD_ASIG;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    case M:
                    {
                        token->type = 0;
                        token->id = OP_NEG;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        fseek(input_file, -1, SEEK_CUR);
                        return input_file;
                    }
                    case N:
                    {
                        token->type = 0;
                        token->id = OP_NEQ;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    case O:
                    {
                        token->type = 0;
                        token->id = OP_ASIG;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    case P:
                    {
                        token->type = 0;
                        token->id = PARENT_IZQ;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    case Q:
                    {
                        token->type = 0;
                        token->id = PARENT_DCH;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    case R:
                    {
                        token->type = 0;
                        token->id = LLAVE_IZQ;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    case S:
                    {
                        token->type = 0;
                        token->id = LLAVE_DCH;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    case T:
                    {
                        token->type = 0;
                        token->id = PUNTO_COMA;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    case U:
                    {
                        token->type = 0;
                        token->id = COMA;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                }
            }
        }
        free(lexema);
        fclose(fp2);
        fclose(fp3);
    } else {
        fclose(input_file);
        fclose(fp2);
        fclose(fp3);
        return NULL;
    }
    return 0;
}
