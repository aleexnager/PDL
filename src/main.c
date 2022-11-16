#include <stdio.h>
#include "header.h"
#include "ts2006.h"

int id_tabla_global;

int main(int argc, char *argv[])
{
    if (argc != 2)
        fprintf(stderr, "Mal número de argumentos, se esperaba 1 argumento.\n");

    #if 0
    // Deberíamos empezar por crear la tabla de símbolos global
    id_tabla_global = crear_tabla();
    #endif

    #if 0
    // Para el el analizador léxico pueda modificar la tabla hay
    // que pasar como argumento a su función el id de la tabla
    an_lex(argv[1], id_tabla_global);
    #endif
    an_lex(argv[1]);

    #if 0
    // Una vez terminan los tres módulos del procesador
    // se destruye la tabla global
    destruir_tabla(id_tabla_global);
    #endif
    return 0;
}
