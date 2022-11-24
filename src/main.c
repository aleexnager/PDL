#include <stdio.h>
#include <unistd.h>
#include "header.h"
#include "ts2006.h"
#include "lifo.h"

int id_tabla_global;
const char *token_file_path = "./data/output/token.txt";
const char *error_file_path = "./data/output/error.txt";

int main(int argc, char *argv[])
{
    if (argc != 2)
        fprintf(stderr, "Mal número de argumentos, se esperaba 1 argumento.\n");

    id_tabla_global = crear_tabla();
    token_t *token = (token_t *) malloc(sizeof(token_t));
    int linea = 1;
    char buf[1024];
    int index = 0;

    FILE *fp = fopen(argv[1], "r");
    // Necesario para truncar el fichero tokens
    truncate(token_file_path, 0);
    truncate(error_file_path, 0);
    
   /*while(fp != NULL)
        fp = an_lex(fp, id_tabla_global, token, &linea, buf, &index);
*/
    an_st(NULL);
    destruir_tabla(id_tabla_global);
    return 0;
}
