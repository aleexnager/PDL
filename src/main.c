#include <stdio.h>
#include "header.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        fprintf(stderr, "Mal número de argumentos, se esperaba 1 argumento.\n");

    an_lex(argv[1]);
    return 0;
}