#include <stdio.h>
#include <stdlib.h>
#include "header.h"

FILE* gen_error(FILE* fp, int cod_error, int linea, char c) {
    if (fp == NULL) exit(1);
    switch (cod_error) {
    case 50:
        fprintf(fp, "Error Léxico. Linea %d: Se esperaba otro caracter diferente a \'%c\'.\n", linea, c);
        break;
    case 51:
        fprintf(fp, "Error Léxico. Linea %d: Se esperaba \'/\' y no \'%c\'.\n", linea, c);
        break;
   case 52:
        fprintf(fp, "Error Léxico. Linea %d: Carácter sin representación ASCII, se esperaba un carácter ASCII.\n", linea);
        break;
    case 53:
        fprintf(fp, "Error Léxico. Linea %d: Carácter \'%c\' no esperado, se esperaba un carácter ascii.", linea, c);
        break;
    case 54:
        fprintf(fp, "Error Léxico. Linea %d: Carácter \'%c\' no esperado, se esperaba un carácter ascii.", linea, c);
        break;
    case 55:
        fprintf(fp, "Error Léxico. Linea %d: Carácter \'%c\' no esperado, se esperaba un carácter ascii.", linea, c);
        break;
    case 56:
        fprintf(fp, "Error Léxico. Linea %d: Carácter \'%c\' no esperado, se esperaba un carácter ascii.", linea, c);
        break;
    case 57:
        fprintf(fp, "Error Léxico. Linea %d: Carácter \'%c\' no esperado, se esperaba un carácter ascii.", linea, c);
        break;
    case 58:
        fprintf(fp, "Error Léxico. Linea %d: Carácter \'%c\' no esperado, se esperaba un carácter ascii.", linea, c);
        break;
    }
    return fp;
}
