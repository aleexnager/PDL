#include <stdio.h>
#include <stdlib.h>
#include "header.h"

FILE* gen_error(FILE* fp, int cod_error, int linea, char c) {
    if (fp == NULL) exit(1);
    switch (cod_error) {
    case 50:
        fprintf(fp, "Error Léxico. Línea %d: Este carácter no es aceptado por la gramática del lenguaje \'%c\'.\n", linea, c);
        break;
    case 51:
        fprintf(fp, "Error Léxico. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", linea, c);
        break;
    case 52:
        fprintf(fp, "Error Léxico. Línea %d: Carácter \'%c\' no esperado, se esperaba un carácter ascii.\n", linea, c);
        break;
    }
    return fp;
}

FILE* gen_error_int(FILE* fp, int linea, int c) {
        fprintf(fp, "Error Léxico. Línea %d: El int \'%d\' tiene un valor que se sale del rango representable [-32767, 32767].\n", linea, c);
        return fp;
}

FILE* gen_error_string(FILE* fp, int linea, char* c) {
        fprintf(fp, "Error Léxico. Línea %d: La longitud del String \'%s\' supera el límite permitido de 64 carácteres.\n", linea, c);
        return fp;
}