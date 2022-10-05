#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"

transicion_t ** ini_mat() {
    transicion_t **m_trans = (transicion_t **) malloc(FILAS_M * sizeof(transicion_t *));
    int i;
    for(i = 0; i < FILAS_M; i++) m_trans[i] = (transicion_t *) malloc(COLUMNAS_M * sizeof(transicion_t));
    return m_trans;
}

transicion_t gen_transicion(int estado, int accion) {
    transicion_t t = {estado, accion};
    return t;
}

void gen_m_trans(transicion_t **m_trans) {
    m_trans[0][0] = gen_transicion(1, NULL);
}

int escaracterespecial(char c) {
    if (c == '(' ||
        c == ')' ||
        c == '{' ||
        c == '}' ||
        c == ',' ||
        c == ';'  )
    return 1;
    return 0;
}

int esc1(char c) {
    if (isascii(c) && c != '\n') return 1;
    return 0;
}

int esc2(char c) {
    if (isascii(c) && c != '\'') return 1;
    return 0;
}

int esdel(char c) {
    if (isspace(c) && c != '\n') return 1;
    return 0;
}

int col_matriz (char c) {
    if (c == '/')           return 0;
    if (c == '\'')          return 1;
    if (isdigit(c))         return 2; // Es un digito {0-9}
    if (isalpha(c))         return 3; // Es una letra {A-Z} U {a-z}
    if (c == '_')           return 4;
    if (c == '%')           return 5;
    if (c == '!')           return 6;
    if (c == '=')           return 7;
    if (escaracterespecial(c))  return 8; // Es un caracter especial {(,),{,},[,]}
    if (c == '\n')          return 9;
    if (esdel(c))           return 10; // Es un delimitador
    if (esc1(c))            return 11; // Es un caracter perteneciente al conjunto c1: c - {\n}
    if (esc2(c))            return 12; // Es un caracter perteneciente al conjunto c2: c - {\'}
    return -1;
}

void analizador_lexico(transicion_t **m_trans, FILE *fp, char c) {
    int estado = 0;
    char leido = c;
    while (estado < 10)
    {
        
    }
}

int main(int argc, char const *argv[])
{
    transicion_t **m_trans = ini_mat();
    return 0;
}
