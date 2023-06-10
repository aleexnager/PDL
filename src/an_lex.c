#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"
#include "ts2006.h"

char *token_file = "./data/output/token.txt";
char *ts_file = "./data/output/ts.txt";
char *error_file = "./data/output/error.txt";

FILE *an_lex(FILE *input_file, int id_tabla, token_t *token, int *linea, char *buf)
{
    FILE *fp2 = fopen(token_file, "a");
    FILE *fp3 = fopen(error_file, "a");

    if (fp2 == NULL || fp3 == NULL)
        exit(1);

    int estado, accion, i = 0;
    char leido = fgetc(input_file);
    buf[i] = leido;
    ++i;
    if (!feof(input_file))
    {
        estado = 0;
        char *lexema = (char *)malloc(65 * sizeof(char));
        memset(lexema, 0, 65);
        int valor;
        int lexema_length;
        while (estado < 10)
        {
            accion = mt_afd_accion(estado, leido);
            estado = mt_afd_estado(estado, leido);

            if (estado == -1)
            {
                if (accion >= 50)
                {
                    fp3 = gen_error(fp3, accion, *linea, leido, buf);
                    leido = fgetc(input_file);
                    buf[i] = leido;
                    ++i;
                    estado = 0;
                }
                else
                {
                    token->id = _FIN_CADENA;
                    token->lexema = NULL;
                    token->valor = -1;
                    return NULL;
                }
            }
            else
            {
                switch (accion)
                {
                case A:
                {
                    if (leido == '\n')
                    {
                        *linea = *linea + 1;
                        leido = fgetc(input_file);
                        buf[i] = leido;
                        ++i;
                    }
                    else
                    {
                        leido = fgetc(input_file);
                        buf[i] = leido;
                        ++i;
                    }
                    break;
                }
                case B:
                {
                    lexema_length = 0;
                    leido = fgetc(input_file);
                    buf[i] = leido;
                    ++i;
                    break;
                }
                case C:
                {
                    if (lexema_length >= 64)
                        lexema = (char *)realloc(lexema, lexema_length + (64 * sizeof(char)));

                    strncat(lexema, &leido, 1);
                    lexema_length++;
                    leido = fgetc(input_file);
                    buf[i] = leido;
                    ++i;
                    break;
                }
                case D:
                {
                    if (lexema_length < 65)
                    {
                        token->id = CADENA;
                        token->lexema = lexema;
                        token->valor = -1;
                        fprintf(fp2, "<%d, \'%s\'>\n", token->id, token->lexema);
                    }
                    else
                    {
                        fp3 = gen_error_string(fp3, *linea, lexema, buf);
                    }
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case E:
                {
                    valor = leido - '0';
                    leido = fgetc(input_file);
                    buf[i] = leido;
                    ++i;
                    break;
                }
                case F:
                {
                    valor = (valor * 10) + (leido - '0');
                    leido = fgetc(input_file);
                    buf[i] = leido;
                    ++i;
                    break;
                }
                case G:
                {
                    if (valor < 32768)
                    {
                        token->id = CTE_ENTERA;
                        token->valor = valor;
                        token->lexema = NULL;
                        fprintf(fp2, "<%d, %d>\n", token->id, token->valor);
                    }
                    else
                    {
                        fp3 = gen_error_int(fp3, *linea, valor, buf);
                    }
                    memset(buf, 0, 1024);
                    fseek(input_file, -1, SEEK_CUR);
                    return input_file;
                }
                case H:
                {
                    strncat(lexema, &leido, 1);
                    leido = fgetc(input_file);
                    buf[i] = leido;
                    ++i;
                    break;
                }
                case I:
                {
                    if (lexema_length >= 64)
                    {
                        lexema = (char *)realloc(lexema, lexema_length + (64 * sizeof(char)));
                    }
                    strncat(lexema, &leido, 1);
                    lexema_length++;
                    leido = fgetc(input_file);
                    buf[i] = leido;
                    ++i;
                    break;
                }
                case J:
                {
                    int pos_ts;
                    int id_pal_res = es_pal_res(lexema);

                    if (id_pal_res > -1)
                    {
                        /* Si es palabra reservada gen token (lexema, -) */
                        token->id = id_pal_res;
                        token->lexema = "";
                        token->valor = -1;
                        fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    }
                    else if ((pos_ts = buscar_posicion_entrada(id_tabla, lexema)) != 0)
                    {
                        /* Si está en la ts gen token (ID, pos_ts) */
                        token->id = ID;
                        token->valor = pos_ts;
                        token->lexema = lexema;
                        fprintf(fp2, "<%d, %d>\n", token->id, token->valor);
                    }
                    else
                    {
                        /* si no está en la ts insertar() y gen token (ID, pos_ts) */
                        crear_entrada(id_tabla, lexema);
                        token->id = ID;
                        token->valor = buscar_posicion_entrada(id_tabla, lexema);
                        token->lexema = lexema;
                        fprintf(fp2, "<%d, %d>\n", token->id, token->valor);
                        escribir_tabla(id_tabla, ts_file);
                    }
                    memset(buf, 0, 1024);
                    fseek(input_file, -1, SEEK_CUR);
                    return input_file;
                }
                case K:
                {
                    token->id = OP_MODULO;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    fseek(input_file, -1, SEEK_CUR);
                    return input_file;
                }
                case L:
                {
                    token->id = OP_MOD_ASIG;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case M:
                {
                    token->id = OP_NEG;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    fseek(input_file, -1, SEEK_CUR);
                    return input_file;
                }
                case N:
                {
                    token->id = OP_NEQ;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case O:
                {
                    token->id = OP_ASIG;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case P:
                {
                    token->id = PARENT_IZQ;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case Q:
                {
                    token->id = PARENT_DCH;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case R:
                {
                    token->id = LLAVE_IZQ;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case S:
                {
                    token->id = LLAVE_DCH;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case T:
                {
                    token->id = PUNTO_COMA;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                case U:
                {
                    token->id = COMA;
                    token->lexema = "";
                    token->valor = -1;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                    memset(buf, 0, 1024);
                    return input_file;
                }
                }
            }
        }
        free(lexema);
        fclose(fp2);
        fclose(fp3);
    }
    else
    {
        //* Se genera el indicador de que ha terminado el fichero
        token->id = _FIN_CADENA;
        token->lexema = NULL;
        token->valor = -1;
        fclose(input_file);
        fclose(fp2);
        fclose(fp3);
        return NULL;
    }
    return 0;
}
