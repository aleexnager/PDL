#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// PRE: se pasa el nombre de la variable
// TODO: se busca el lexema en la tabla de símbolos
// POST: devuelve el indice de la tabla de símbolos si se encuentra (result >= 0)
//       o -1 si no se encuentra.

int buscar_ts (const char* lexema, item_ts_t* tabla_simb []) {
    int i;
    int resultado = -1;
    for (i = 0; resultado == -1 && i < TAM_TS; ++i) {
        if (!strcmp(tabla_simb[i]->lexema, lexema)) {
            resultado = i;
        }
    }
    return resultado;
}

// PRE: se pasan todos los argumentos necesarios para crear un token item_ts_t
// TODO: crear un struct item_ts_t e insertarlo en la tabla de símbolos
// POST: devuelve el índice de la tabla de símbolos en la que se ha insertado

int insertar_ts (int* top_ts, int* suma_desp, const char* lexema, int tipo_var, int desp, int num_param, int tipo_dev, const char* etiq, int tam, item_ts_t* tabla_simb []) {
    item_ts_t* item = (item_ts_t *) malloc(sizeof(item_ts_t *));
    strcpy(item->lexema, lexema);
    item->tipo_var = tipo_var;
    item->desp = *suma_desp;
    item->num_param = num_param;
    item->tipo_dev = tipo_dev;
    item->etiq = etiq;

    tabla_simb[*top_ts] = item;

    ++(*top_ts);
    (*suma_desp) += tam;

    return (*top_ts) - 1;
}
