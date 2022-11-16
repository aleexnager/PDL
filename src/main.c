#include <stdio.h>
#include "header.h"
#include "ts2006.h"

int id_tabla_global;

int main(int argc, char *argv[])
{
    if (argc != 2)
        fprintf(stderr, "Mal número de argumentos, se esperaba 1 argumento.\n");

    id_tabla_global = crear_tabla();

    an_lex(argv[1], id_tabla_global);



    destruir_tabla(id_tabla_global);
    return 0;
}
