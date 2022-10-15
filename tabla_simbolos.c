#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// PRE: se pasa el nombre de la variable
// TODO: se busca el lexema en la tabla de símbolos
// POST: devuelve el indice de la tabla de símbolos si se encuentra (result >= 0)
//       o -1 si no se encuentra.

int buscar_ts (const char* lexema, int top_ts, item_ts_t tabla_simb []) {
    int i;
    int resultado = -1;
    for (i = 0; resultado == -1 && i < top_ts; ++i) {
        if (strcmp(tabla_simb[i].lexema, lexema) == 0) {
            resultado = i;
        }
    }
    return resultado;
}

// PRE: se pasan todos los argumentos necesarios para crear un token item_ts_t
// TODO: crear un struct item_ts_t e insertarlo en la tabla de símbolos
// POST: devuelve el índice de la tabla de símbolos en la que se ha insertado

int insertar_ts (int top_ts, const char* lexema, int tipo_var, int desp, item_ts_t tabla_simb []) {
    tabla_simb[top_ts].lexema = (char *)malloc(sizeof(char *));
    strcpy(tabla_simb[top_ts].lexema, lexema);
    tabla_simb[top_ts].tipo_var = tipo_var;
    tabla_simb[top_ts].desp = desp;
    ++top_ts;
    return top_ts;
}

FILE *imprimir_ts(FILE* fp4, item_ts_t tabla_simb[], int pos_ts, int num_tabla) {
    if (pos_ts==0) fprintf(fp4, "#%d:\n", num_tabla);
    fprintf(fp4, "*\'%s\'\n+tipo:\'%d\'\n+despl:%d\n",
            tabla_simb[pos_ts].lexema,
            tabla_simb[pos_ts].tipo_var,
            tabla_simb[pos_ts].desp);
    return fp4;
}