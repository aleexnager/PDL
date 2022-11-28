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
    FILE *parse = fopen("./data/output/parse.txt", "w");
    FILE *fp_error = fopen("./data/output/error.txt", "a");
    int aux;
    fprintf(parse, "Descendente ");
    int linea = 1;
    char buf[1024];
    int *res = (int *) malloc(16*sizeof(int));
    token_t *token = (token_t *) malloc(sizeof(token_t));
    fp = an_lex(fp, id_tabla, token, &linea, buf);
    push(_$);
    push(_P);

    // ALGORITMO
    int simb, n_tokens = 1;
    while ((simb = peek()) != _$)
    {
        if (es_terminal(simb))
        {
            if (simb == token->id)
            {
                printf("Son iguales!!\n");
                pop();
                fp = an_lex(fp, id_tabla, token, &linea, buf);
                printf("%d: \n", token->id);
                printf("n_tokens leidos: %d\n", n_tokens);
                ++n_tokens;
            }
            else
            {
                //! gen_error()
                gen_error_sintactico(fp_error, linea);
                fprintf(stderr, "hola soy mr.error1 en la linea %d\n", linea);
                pop();
                fp = an_lex(fp, id_tabla, token, &linea, buf);
                continue;
            }
        }
        else
        {
            printf("token: %d\n", token->id);
            if ((res = tabla_LL1(simb, token->id, &aux)) != NULL)
            {
                // extraer simb de la pila y meter res en la pila
                fprintf(parse, "%d ", aux);
                print();
                pop();
                int i = 0;
                while (res[i] != -1)
                {
                    printf("%d\n", res[i]);
                    push(res[i]);
                    ++i;
                    printf("i: %d\n", i);
                }
                printf("SE HAN PUSHEADO LOS CONSECUENTES\n");
                print();
            }
            else
            {
                //! gen_error()
                gen_error_sintactico(fp_error, linea);
                fprintf(stderr, "hola soy mr.error2 en la linea %d\n", linea);
                pop();
                continue;
            }
        }
    }
    return 0;
}
