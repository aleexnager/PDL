#include <stdio.h>
#include <unistd.h>
#include "header.h"
#include "ts2006.h"
#include "lifo.h"

int id_tabla_global;
const char *token_file_path = "./data/output/token.txt";
const char *error_file_path = "./data/output/error.txt";
const char *ts_file_path = "./data/output/ts.txt";
const char *aux_ts_file_path = "./data/output/ts_aux.txt";

int main(int argc, char *argv[])
{
    if (argc != 2)
        fprintf(stderr, "Mal número de argumentos, se esperaba 1 argumento.\n");

    id_tabla_global = crear_tabla();
    FILE *fp = fopen(argv[1], "r");

    remove(token_file_path);
    remove(error_file_path);
    remove(ts_file_path);
    remove(aux_ts_file_path);

    an_st(fp, id_tabla_global);
    destruir_tabla(id_tabla_global);
    return 0;
}
