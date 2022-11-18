#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"
#include "ts2006.h"

// FUNCION QUE IMPLEMENTA EL FUNCIONAMIENTO DE ANALIZADOR LÉXICO, SU FUNCIÓN ES LEER DESDE UN FP, HABIENDO
// LEIDO YA UN CARÁCTER Y GENERAR UN TOKEN O GENERAR UN ERROR

// INTERACCIÓN CON LA TABLA DE SÍMBOLOS GLOBAL
// - Crear las entradas en la tabla global si se
//   se encuentra un token identificador, a la vez
//   que recuperar su posición en la tabla para
//   generar el token correspondiente.
//
// Funciones necesarias:
//
// crear_entrada(int id_tabla, char *lexema)
//     -> 0 (correcto) || -1 (error)
//
// buscar_posicion_entrada(int id_tabla, char *lexema)
//     -> pos (existe) || 0 (no existe)

//* Ideas:
//* - an_lex deberá devolver el [FILE *] del fichero fuente
//! FILE *an_lex(FILE *fd_input_file, int id_tabla)

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
    // FILE *input_file = fopen(input_file, "r");
    FILE *fp2 = fopen(token_file, "a");
    FILE *fp3 = fopen(error_file, "w");

    if (/*input_file == NULL || */fp2 == NULL || fp3 == NULL)
        exit(1);

    int estado;
    int accion;
    int linea = 1;
    char leido = fgetc(input_file);
    while (!feof(input_file))
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
                        return input_file;
                    }
                    case K:
                    {
                        token->type = 0;
                        token->id = OP_MODULO;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                        return input_file;
                    }
                    //! ME HE QUEDADO AQUÍ
                    case L:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token9 = malloc(sizeof(token_lexema_t *));
                        token9->id = OP_MOD_ASIG;
                        token9->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token9->id, token9->lexema);
                        free(token9);
                        break;
                    }
                    case M:
                    {
                        token_lexema_t *token10 = malloc(sizeof(token_lexema_t *));
                        token10->id = OP_NEG;
                        token10->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token10->id, token10->lexema);
                        free(token10);
                        break;
                    }
                    case N:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token11 = malloc(sizeof(token_lexema_t *));
                        token11->id = OP_NEQ;
                        token11->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token11->id, token11->lexema);
                        free(token11);
                        break;
                    }
                    case O:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token1 = malloc(sizeof(token_lexema_t *));
                        token1->id = OP_ASIG;
                        token1->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token1->id, token1->lexema);
                        free(token1);
                        break;
                    }
                    case P:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token2 = malloc(sizeof(token_lexema_t *));
                        token2->id = PARENT_IZQ;
                        token2->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token2->id, token2->lexema);
                        free(token2);
                        break;
                    }
                    case Q:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token3 = malloc(sizeof(token_lexema_t *));
                        token3->id = PARENT_DCH;
                        token3->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token3->id, token3->lexema);
                        free(token3);
                        break;
                    }
                    case R:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token4 = malloc(sizeof(token_lexema_t *));
                        token4->id = LLAVE_IZQ;
                        token4->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token4->id, token4->lexema);
                        free(token4);
                        break;
                    }
                    case S:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token5 = malloc(sizeof(token_lexema_t *));
                        token5->id = LLAVE_DCH;
                        token5->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token5->id, token5->lexema);
                        free(token5);
                        break;
                    }
                    case T:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token6 = malloc(sizeof(token_lexema_t *));
                        token6->id = PUNTO_COMA;
                        token6->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token6->id, token6->lexema);
                        free(token6);
                        break;
                    }
                    case U:
                    {
                        leido = fgetc(input_file);
                        token_lexema_t *token7 = malloc(sizeof(token_lexema_t *));
                        token7->id = COMA;
                        token7->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token7->id, token7->lexema);
                        free(token7);
                        break;
                    }
                }
            }
        }
        free(lexema);
    }
    fclose(input_file);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
