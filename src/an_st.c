#include <stdio.h>
#include "header.h"
#include "ts2006.h"
#include "lifo.h"
#include "lifo_aux.h"

// Funciones push(char c), pop(void), peek(void) y print(void)
// provienen de la librería lifo.h. Modelan una estructura de datos
// LIFO para implementar la pila de trabajo del analiador sintáctico.

// La librería lifo.h representa la pila P (sintáctico)
// La librería lifo_aux.h representa la pila AUX (semántico)

int an_st(FILE *input_file, int id_tabla)
{
    FILE *fp = input_file;
    FILE *parse = fopen("./data/output/parse.txt", "w");
    FILE *fp_error = fopen("./data/output/error.txt", "a");
    int regla, i, despl, zona_decl, linea = 1;
    char buf[1024];
    int *res = (int *)malloc(16 * sizeof(int));
    token_t *token = (token_t *)malloc(sizeof(token_t));
    token->lexema = (char *)malloc(64 * sizeof(char));
    token_t *simb = (token_t *)malloc(sizeof(token_t));
    token_t *aux;

    fprintf(parse, "Descendente ");
    memset(buf, 0, 1024);
    fp = an_lex(fp, id_tabla, token, &linea, buf);

    token_t *fin_cadena = (token_t *)malloc(sizeof(token_t));
    fin_cadena->id = _FIN_CADENA;
    push(fin_cadena);

    token_t *programa = (token_t *)malloc(sizeof(token_t));
    programa->id = _P_PRIMA;
    push(programa);

    while ((simb = peek())->id != _FIN_CADENA)
    {
        if (es_terminal(simb->id))
        {
            if (simb->id == token->id)
            {
                aux = (token_t *)malloc(sizeof(token_t));
                aux = pop();

                if (aux->id == ID)
                    strcpy(aux->lexema, token->lexema);

                push_aux(aux);
                token->lexema = malloc(64);
                fp = an_lex(fp, id_tabla, token, &linea, buf);
            }
            else
            {
                gen_error_sintactico(fp_error, linea, token);
                break;
            }
        }
        else if (es_regla_semantica(simb->id))
        {
            ejecutar_regla_semantica(id_tabla, simb->id, &despl, &zona_decl);
            pop();
        }
        else
        {
            if ((res = tabla_LL1(simb->id, token->id, &regla)) != NULL)
            {
                fprintf(parse, "%d ", regla);
                push_aux(pop());
                i = 0;
                while (res[i] != -1)
                {
                    aux = (token_t *)malloc(sizeof(token_t));
                    aux->lexema = malloc(64);
                    aux->id = res[i];
                    push(aux);
                    ++i;
                }
            }
            else
            {
                gen_error_sintactico(fp_error, linea, token);
                break;
            }
        }
    }

    if (size_aux() == 1 && peek_aux()->id == _P)
        return 0;
    else
        return -1;
}
