#include <stdio.h>
#include "header.h"
#include "ts2006.h"
#include "lifo.h"

// Funciones push(char c), pop(void), peek(void) y print(void)
// provienen de la librería lifo.h. Modelan una estructura de datos
// LIFO para implementar la pila de trabajo del analiador sintáctico.

int an_st(FILE *input_file, int id_tabla)
{
    FILE *fp = input_file;
    FILE *parse = fopen("./data/output/parse.txt", "w");
    FILE *fp_error = fopen("./data/output/error.txt", "a");
    int regla, simb, i, linea = 1;
    char buf[1024];
    int *res = (int *) malloc(16*sizeof(int));
    token_t *token = (token_t *) malloc(sizeof(token_t));

    fprintf(parse, "Descendente ");
    memset(buf, 0, 1024);
    fp = an_lex(fp, id_tabla, token, &linea, buf);

    push(_$);
    push(_P);

    while ((simb = peek()) != _$)
    {
        if (es_terminal(simb))
        {
            if (simb == token->id)
            {
                pop();
                fp = an_lex(fp, id_tabla, token, &linea, buf);
            }
            else
            {
                gen_error_sintactico(100, fp_error, linea, token->id, -1);
                break;
            }
        }
        else
        {
            if ((res = tabla_LL1(simb, token->id, &regla)) != NULL)
            {
                // extraer simb de la pila y meter res en la pila
                fprintf(parse, "%d ", regla);
                pop();
                i = 0;
                while (res[i] != -1)
                {
                    push(res[i]);
                    ++i;
                }
            }
            else
            {
                gen_error_sintactico(101, fp_error, linea, token->id, simb);
                break;
            }
        }
    }
    return 0;
}
