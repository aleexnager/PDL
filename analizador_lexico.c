#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"

int isespecialchar(char c) {
    if (c == '(' ||
        c == ')' ||
        c == '{' ||
        c == '}' ||
        c == '[' ||
        c == ']'   )
    return 1;
    return 0;
}

int isc1(char c) {
    if (isascii(c) && c != '\n') return 1;
    return 0;
}

int isc2(char c) {
    if (isascii(c) && c != '\'') return 1;
    return 0;
}

int fila_matriz (char c) {
    if (c == '/')           return 0;
    if (c == '\'')          return 1;
    if (isdigit(c))         return 2; // Es un digito {0-9}
    if (isalpha(c))         return 3; // Es una letra {A-Z} U {a-z}
    if (c == '_')           return 4;
    if (c == '%')           return 5;
    if (c == '!')           return 6;
    if (c == '=')           return 7;
    if (isespecialchar(c))  return 8; // Es un caracter especial {(,),{,},[,]}
    if (isspace(c))         return 9; // Es un delimitador
    if (isc1(c))            return 10; // Es un caracter perteneciente al conjunto c1: c - {\n}
    if (c == '\n')          return 11;
    if (isc2(c))            return 12; // Es un caracter perteneciente al conjunto c2: c - {\'}
    if (c == ';')           return 13;
    return -1;
}

int main(int argc, char const *argv[])
{
    int estado = 0;
    char leido;
    while (estado < 10)
    {
        leido = fgetc(stdin);

    }
    return 0;
}
