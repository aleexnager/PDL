#include <stdio.h>
#include "header.h"
#include "ts2006.h"
#include "lifo.h"

// Funciones push(char c), pop(void), peek(void) y print(void)
// provienen de la librería lifo.h. Modelan una estructura de datos
// LIFO para implementar la pila de trabajo del analiador sintáctico.

int an_st(FILE *input_file, int id_tabla)
{
    // PSEUDOCÓDIGO PARA EL ALGORITMO
    // INICIALMENTE:
    // - La pila tiene '$' (fin de fichero) y 'P' (axioma de la gramñatica)
    // - La cadena
    FILE *fp = input_file;
    int linea = 1;
    char buf[1024];
    int index = 0;
    int *res;
    token_t *token = (token_t *) malloc(sizeof(token_t));
    fp = an_lex(fp, id_tabla, token, &linea, buf, &index);
    push(_$);
    push(_P);

    // ALGORITMO
    int simb;
    while ((simb = peek()) != _$)
    {
        if (es_terminal(simb))
        {
            if (simb == token->id)
            {
                // extraer simb de la pila y pedir token
            }
            else
            {
                //! gen_error()
            }
        }
        else
        {
            if ((res = tabla_LL1(simb, token->id)) != NULL)
            {
                // extraer simb de la pila y meter res en la pila
            }
            else
            {
                //! gen_error()
            }
        }
    }
    return 0;
}
