#include <stdio.h>
#include <stdlib.h>
#include "header.h"

FILE* gen_error(FILE* fp, int cod_error, int linea, char c) {
    if (fp == NULL) exit(1);
    switch (cod_error) {
    case 50:
        fprintf(fp, "Error Léxico %d. Línea %d: Este carácter no es aceptado por la gramática del lenguaje \'%c\'.\n", cod_error, linea, c);
        break;
    case 51:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 52:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 53:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 54:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 55:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 56:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 57:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 58:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 59:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 60:
        fprintf(fp, "Error Léxico %d. Línea %d: No se acepta un delimitador. Se esperada el carácter \'/\'.\n", cod_error, linea);
        break;
    case 61:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 62:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 63:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 64:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 65:
        fprintf(fp, "Error Léxico %d. Línea %d: Carácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n", cod_error, linea, c);
        break;
    case 66:
        fprintf(fp, "Error Léxico %d. Línea %d: Este carácter no es aceptado por la gramática del lenguaje \'%c\'.\n", cod_error, linea, c);
        break;
    case 67:
        fprintf(fp, "Error Léxico %d. Línea %d: Este carácter no es aceptado por la gramática del lenguaje \'%c\'.\n", cod_error, linea, c);
        break;
    case 68:
        fprintf(fp, "Error Léxico %d. Línea %d: Este carácter no es aceptado por la gramática del lenguaje \'%c\'.\n", cod_error, linea, c);
        break;
    case 69:
        fprintf(fp, "Error Léxico %d. Línea %d: Este carácter no es aceptado por la gramática del lenguaje \'%c\'.\n", cod_error, linea, c);
        break;
    case 70:
        fprintf(fp, "Error Léxico %d. Línea %d: Este carácter no es aceptado por la gramática del lenguaje \'%c\'.\n", cod_error, linea, c);
        break;
    case 71:
        fprintf(fp, "Error Léxico %d. Línea %d: Este carácter no es aceptado por la gramática del lenguaje \'%c\'.\n", cod_error, linea, c);
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