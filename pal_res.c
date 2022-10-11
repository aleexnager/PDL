#include <stdlib.h>
#include <string.h>
#include "header.h"

int es_pal_res(const char* lexema) {
    if (strcmp(lexema, "boolean")) {
        return BOOLEAN;
    } else if (strcmp(lexema, "for")) {
        return FOR;
    } else {
        return -1;
    }
    /* Se sigue la cadena de ifs para comprobar
       si es o no una palabra reservada */
}
