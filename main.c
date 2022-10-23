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

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL) exit(1);

    int estado;
    int accion;
    int linea = 1;
    char leido = fgetc(fp1);
    while (!feof(fp1))
    {
        estado = 0;
        char* lexema = (char *) malloc(65 * sizeof(char));
        memset(lexema, 0, sizeof(char*));
        int valor;
        while (estado < 10)
        {
            accion = mt_afd_accion(estado, leido);
            estado = mt_afd_estado(estado, leido);

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
                        leido = fgetc(fp1);
                        break;
                    }
                    case C:
                    {
                        //int len = strlen(lexema);
                        if (strlen(lexema) >= 64) {
                            lexema = (char *) realloc(lexema, strlen(lexema) + (64 * sizeof(char)));
                        }
                        lexema = strncat(lexema, &leido, 1);
                        leido = fgetc(fp1);
                        break;
                    }
                    case D:
                    {
                        if (strlen(lexema) < 65) {
                            token_lexema_t* token = malloc(sizeof(token_lexema_t *));
                            token->id = CADENA;
                            token->lexema = lexema;
                            fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                            free(token);
                        } else {
                            fp3 = gen_error_string(fp3, linea, lexema);
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
                            free(token);
                        } else {
                            fp3 = gen_error_int(fp3, linea, valor);
                        }
                        break;
                    }
                    case H:
                    {
                        lexema = strncat(lexema, &leido, 1);
                        leido = fgetc(fp1);
                        break;
                    }
                    case I:
                    {
                        if (strlen(lexema) >= 64) { /*como solo una de cada 64 veces como mucho nos metemos en esta condicion, es mas eficiente 
                                                      no usar una variable auxiliar para almacenar el length de lexema cada una de las iteraciones
						      . lo he vuelto a pensar y no se si es verdad esto, lo unico que hace es hacer 1 operacion mas
						      cada iteracion pero no crea espacio para una variable cada una de las veces asi que no se 
						      que es mejor, queda mas bonito como antes pero weno*/
                            lexema = (char *) realloc(lexema, strlen(lexema) + (64 * sizeof(char)));
                        }
                        lexema = strncat(lexema, &leido, 1);
                        leido = fgetc(fp1);
                        break;
                    }
                    case J:
                    {
                        int pos_ts;
                        int id_pal_res = es_pal_res(lexema);

                        if (id_pal_res > -1) {
                            token_lexema_t* token_pal_res = malloc(sizeof(token_lexema_t *));
                            token_pal_res->id = id_pal_res;
                            token_pal_res->lexema = "";
                            fprintf(fp2, "<%d, %s>\n", token_pal_res->id, token_pal_res->lexema);
                            free(token_pal_res);
                        } else if ( (pos_ts = buscar_ts(lexema, top_ts, tabla_simb)) > -1) { /* he cambiado aqui a top_ts */
                            /* Si está en la ts gen token (ID, pos_ts) */
                            token_valor_t* token_valor_1 = malloc(sizeof(token_valor_t *));
                            token_valor_1->id = ID;
                            token_valor_1->valor = pos_ts;
                            fprintf(fp2, "<%d, %d>\n", token_valor_1->id, token_valor_1->valor);    
                            free(token_valor_1);    
                        } else {
                            /* si no está en la ts insertar() y gen token (ID, pos_ts) */
                            top_ts = insertar_ts(top_ts, lexema, 0, 0, tabla_simb);
                            pos_ts = top_ts - 1;
                            token_valor_t* token_valor_2 = malloc(sizeof(token_valor_t *));
                            token_valor_2->id = ID;
                            token_valor_2->valor = pos_ts;
                            fprintf(fp2, "<%d, %d>\n", token_valor_2->id, token_valor_2->valor);
                            fp4 = imprimir_ts(fp4, tabla_simb, pos_ts, 0);
                            free(token_valor_2);
                        }
                        break;
                    }
                    case K:
                    {
                        token_lexema_t* token8 = malloc(sizeof(token_lexema_t *));
                        token8->id = OP_MODULO;
                        token8->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token8->id, token8->lexema);
                        free(token8);
                        break;
                    }
                    case L:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token9 = malloc(sizeof(token_lexema_t *));
                        token9->id = OP_MOD_ASIG;
                        token9->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token9->id, token9->lexema);
                        free(token9);
                        break;
                    }
                    case M:
                    {
                        token_lexema_t* token10 = malloc(sizeof(token_lexema_t *));
                        token10->id = OP_NEG;
                        token10->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token10->id, token10->lexema);
                        free(token10);
                        break;
                    }
                    case N:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token11 = malloc(sizeof(token_lexema_t *));
                        token11->id = OP_NEQ;
                        token11->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token11->id, token11->lexema);
                        free(token11);
                        break;
                    }
                    case O:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token1 = malloc(sizeof(token_lexema_t *));
                        token1->id = OP_ASIG;
                        token1->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token1->id, token1->lexema);
                        free(token1);
                        break;
                    }
                    case P:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token2 = malloc(sizeof(token_lexema_t *));
                        token2->id = PARENT_IZQ;
                        token2->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token2->id, token2->lexema);
                        free(token2);
                        break;
                    }
                    case Q:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token3 = malloc(sizeof(token_lexema_t *));
                        token3->id = PARENT_DCH;
                        token3->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token3->id, token3->lexema);
                        free(token3);
                        break;
                    }
                    case R:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token4 = malloc(sizeof(token_lexema_t *));
                        token4->id = LLAVE_IZQ;
                        token4->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token4->id, token4->lexema);
                        free(token4);
                        break;
                    }
                    case S:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token5 = malloc(sizeof(token_lexema_t *));
                        token5->id = LLAVE_DCH;
                        token5->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token5->id, token5->lexema);
                        free(token5);
                        break;
                    }
                    case T:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token6 = malloc(sizeof(token_lexema_t *));
                        token6->id = PUNTO_COMA;
                        token6->lexema = "";
                        fprintf(fp2, "<%d, %s>\n", token6->id, token6->lexema);
                        free(token6);
                        break;
                    }
                    case U:
                    {
                        leido = fgetc(fp1);
                        token_lexema_t* token7 = malloc(sizeof(token_lexema_t *));
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
    free(tabla_simb);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    return 0;
}
