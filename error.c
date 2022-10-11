#include <stdio.h>
#include <stdlib.h>
#include "header.h"

FILE* gen_error(FILE* fp, int cod_error, int linea, char c) {
    if (fp == NULL) exit(1);
    switch (cod_error) {
    case 50:
        fprintf(fp, "Linea %d: Se esperaba otro caracter diferente a \'%c\'\n", linea, c);
        break;
    case 51:
        fprintf(fp, "Linea %d: Se esperaba \'/\' y no \'%c\'\n", linea, c);
        break;
   case 52:
        break;
    case 53:
        break;
    case 54:
        break;
    case 55:
        break;
    case 56:
        break;
    case 57:
        break;
    case 58:
        break;
    }
    return fp;
}