#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"

// FUNCION QUE IMPLEMENTA EL FUNCIONAMIENTO DE ANALIZADOR LÉXICO, SU FUNCIÓN ES LEER DESDE UN FP, HABIENDO
// LEIDO YA UN CARÁCTER Y GENERAR UN TOKEN O GENERAR UN ERROR

int main(int argc, char const *argv[])
{
    int top_ts = 0;
    item_ts_t* tabla_simb = malloc(TAM_TS * sizeof(item_ts_t));

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen("token.txt", "w");
    FILE *fp3 = fopen("error.txt", "w");
    FILE *fp4 = fopen("tabla_simbolos.txt", "w");

    if (fp1 == NULL) exit(1);

    int estado;
    int accion;
    int linea = 1;
    char leido = fgetc(fp1);
    while (!feof(fp1))
    {
        estado = 0;
        char* lexema = malloc(sizeof(char*));
        memset(lexema, 0, sizeof(char*));
        int valor;
        while (estado < 10)
        {
            accion = mt_afd_accion(estado, leido);
            fprintf(stderr, "La siguiente acción es %d\n", accion);
            estado = mt_afd_estado(estado, leido);
            fprintf(stderr, "El siguiente estado es %d\n", estado);

            if (estado == -1) {
                // Estado es -1 y acción 1, se ha leído un EOF
                // por tanto, se entra al if de estado pero no llama
                // a la función de generar error
                if (accion >= 50) {
                    fp3 = gen_error(fp3, accion, linea, leido);
                }
                leido = fgetc(fp1);
                estado = 0;
                break;
            } else {
                switch (accion) {
                    case A:
                    {
                        if (leido == '\n') ++linea;
                        leido = fgetc(fp1);
                        break;
                    }
                    case B:
                    {
                        fprintf(stderr, "Se ha llegado a B\n");
                        leido = fgetc(fp1);
                        break;
                    }
                    case C:
                    {
                        fprintf(stderr, "Se ha llegado a C\n");
                        lexema = strncat(lexema, &leido, 1);
                        leido = fgetc(fp1);
                        break;
                    }
                    case D:
                    {
                        fprintf(stderr, "Se ha llegado a D\n");
                        if (strlen(lexema) < 65) {
                            token_lexema_t* token = malloc(sizeof(token_lexema_t *));
                            token->id = CADENA;
                            token->lexema = lexema;
                            // strcpy(token->lexema, lexema);
                            fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                            fprintf(stderr, "La linea es %d\n", linea);
                        } else {
                            fp3 = gen_error(fp3, 59, linea, leido);
                        }
                        leido = fgetc(fp1);
                        break;
                    }
                    case E:
                    {
                        valor = leido - '0';
                        leido = fgetc(fp1);
                        break;
                    }
                    case F:
                    {
                        valor = (valor * 10) + (leido - '0');
                        leido = fgetc(fp1);
                        break;
                    }
                    case G:
                    {
                        if (valor > -32768 && valor < 32768) {
                            token_valor_t* token = malloc(sizeof(token_valor_t *));
                            token->id = CTE_ENTERA;
                            token->valor = valor;
                            fprintf(fp2, "<%d, %d>\n", token->id, token->valor);
                            fprintf(stderr, "La linea es %d\n", linea);
                        } else {
                            fp3 = gen_error(fp3, 60, linea, leido);
                        }
                        break;
                    }
                    case H:
                    {
                        lexema = strncat(lexema, &leido, 1);
                        fprintf(stderr, "%s\n", lexema);
                        leido = fgetc(fp1);
                        break;
                    }
                    case I:
                    {
                        lexema = strncat(lexema, &leido, 1);
                        fprintf(stderr, "%s\n", lexema);
                        leido = fgetc(fp1);
                        break;
                    }
                    case J:
                    {
                        int pos_ts;
                        int id_pal_res = es_pal_res(lexema);

                        if (id_pal_res > -1) {
                            /* Si es palabra reservada
                            gen token (ID)*/
                            token_lexema_t* token_pal_res = malloc(sizeof(token_lexema_t *));
                            token_pal_res->id = id_pal_res;
                            token_pal_res->lexema = "";
                            fprintf(fp2, "<%d, %s>\n", token_pal_res->id, token_pal_res->lexema);
                            fprintf(stderr, "La linea es %d\n", linea);
                        } else if ( (pos_ts = buscar_ts(lexema, top_ts, tabla_simb)) > -1) { /* he cambiado aqui a top_ts */
                            /* Si está en la ts gen token (ID, pos_ts) */
                            token_valor_t* token_valor_1 = malloc(sizeof(token_valor_t *));
                            token_valor_1->id = ID;
                            token_valor_1->valor = pos_ts;
                            fprintf(fp2, "<%d, %d>\n", token_valor_1->id, token_valor_1->valor);        
                        } else {
                            /* si no está en la ts insertar() y gen token (ID, pos_ts) */
                            top_ts = insertar_ts(top_ts, lexema, 0, 0, tabla_simb);
                            pos_ts = top_ts - 1;
                            token_valor_t* token_valor_2 = malloc(sizeof(token_valor_t *));
                            token_valor_2->id = ID;
                            token_valor_2->valor = pos_ts;

                            fprintf(fp2, "<%d, %d>\n", token_valor_2->id, token_valor_2->valor);
                           // fprintf(fp4, "<%d, %d>\n", token_valor_2->id, token_valor_2->valor);  
                            imprimir_ts(fp4, tabla_simb, pos_ts, 0);

                        }
                        break;
                    }
                    case K:
                    {
                        token_lexema_t* token8 = malloc(sizeof(token_lexema_t *));
                        token8->id = OP_MODULO;
                        token8->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token8->id, token8->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case L:
                    {
                        token_lexema_t* token9 = malloc(sizeof(token_lexema_t *));
                        token9->id = OP_MOD_ASIG;
                        token9->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token9->id, token9->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case M:
                    {
                        token_lexema_t* token10 = malloc(sizeof(token_lexema_t *));
                        token10->id = OP_NEG;
                        token10->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token10->id, token10->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case N:
                    {
                        token_lexema_t* token11 = malloc(sizeof(token_lexema_t *));
                        token11->id = OP_NEQ;
                        token11->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token11->id, token11->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case O:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token1 = malloc(sizeof(token_lexema_t *));
                        token1->id = OP_ASIG;
                        token1->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token1->id, token1->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case P:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token2 = malloc(sizeof(token_lexema_t *));
                        token2->id = PARENT_IZQ;
                        token2->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token2->id, token2->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case Q:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token3 = malloc(sizeof(token_lexema_t *));
                        token3->id = PARENT_DCH;
                        token3->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token3->id, token3->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case R:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token4 = malloc(sizeof(token_lexema_t *));
                        token4->id = LLAVE_IZQ;
                        token4->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token4->id, token4->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case S:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token5 = malloc(sizeof(token_lexema_t *));
                        token5->id = LLAVE_DCH;
                        token5->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token5->id, token5->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case T:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token6 = malloc(sizeof(token_lexema_t *));
                        token6->id = PUNTO_COMA;
                        token6->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token6->id, token6->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                    case U:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token7 = malloc(sizeof(token_lexema_t *));
                        token7->id = COMA;
                        token7->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token7->id, token7->lexema);
                        fprintf(stderr, "La linea es %d\n", linea);
                        break;
                    }
                }
            }
        }
        free(lexema);
    }
    free(tabla_simb);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    return 0;
}