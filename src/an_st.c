#include <stdio.h>
#include "header.h"
#include "ts2006.h"
#include "lifo.h"

// Funciones push(char c), pop(void), peek(void) y print(void)
// provienen de la librería lifo.h. Modelan una estructura de datos
// LIFO para implementar la pila de trabajo del analiador sintáctico.

int an_st(char *cadena)
{
    // PSEUDOCÓDIGO PARA EL ALGORITMO
    // INICIALMENTE:
    // - La pila tiene '$' (fin de fichero) y 'P' (axioma de la gramñatica)
    // - La cadena
    push(_$);
    push(_P);
    return 0;
}
