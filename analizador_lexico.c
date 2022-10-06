#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"

transicion_t gen_transicion(int estado, int accion) {
    transicion_t t = {estado, accion};
    return t;
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
    if (c == '/')               return 0;
    if (c == '\'')              return 1;
    if (isdigit(c))             return 2; // Es un digito {0-9}
    if (isalpha(c))             return 3; // Es una letra {A-Z} U {a-z}
    if (c == '_')               return 4;
    if (c == '%')               return 5;
    if (c == '!')               return 6;
    if (c == '=')               return 7;
    if (escaracterespecial(c))  return 8; // Es un caracter especial {(,),{,},[,]}
    if (c == '\n')              return 9;
    if (esdel(c))               return 10; // Es un delimitador
    if (esc1(c))                return 11; // Es un caracter perteneciente al conjunto c1: c - {\n}
    if (esc2(c))                return 12; // Es un caracter perteneciente al conjunto c2: c - {\'}
    return -1;
}

int mt_afd_estado(int estado_actual, char c) {
    int sig_estado;
    switch (estado_actual) {
    case 0:
        if (c == '/')               sig_estado = 1; break;
        if (c == '\'')              sig_estado = 3; break;
        if (isdigit(c))             sig_estado = 4; break;
        if (isalpha(c) || c == '_') sig_estado = 5; break;
        if (c == '%')               sig_estado = 6; break;
        if (c == '!')               sig_estado = 8; break;
        if (c == '=')               sig_estado = 108; break;
        if (escaracterespecial(c))  sig_estado = 109; break;
        if (esdel(c) || c == '\n')  sig_estado = 0; break;
        sig_estado = -1; break;
    case 1:
        if (c == '/')               sig_estado = 2; break;
        sig_estado = -1; break;
    case 2:
        if (esc1(c))                sig_estado = 2; break;
        if (c == '\n')              sig_estado = 0; break;
        sig_estado = -1; break;
    case 3:
        if (esc2(c))                sig_estado = 3; break;
        if (c == '\'')              sig_estado = 101; break;
        sig_estado = -1; break;
    case 4:
        if (isdigit(c)) {
            sig_estado = 4; break;
        } else {
            sig_estado = 102; break;
        }
        sig_estado = -1; break;
    case 5:
        if (isalpha(c) || isdigit(c) || c == '_') {
            sig_estado = 5; break;
        } else {
            sig_estado = 103; break;
        }
        sig_estado = -1; break;
    case 6:
        if (c == '=') {
            sig_estado = 7; break;
        } else {
            sig_estado = 104; break;
        }
        sig_estado = -1; break;
    case 7:
        sig_estado = 105; break;
    case 8:
        if (c == '=') {
            sig_estado = 9; break;
        } else {
            sig_estado = 106; break;
        }
        sig_estado = -1; break;
    case 9:
        sig_estado = 107; break;
    }
    return sig_estado;
}

/* char mt_afd_accion(int estado_actual, char car) {
char accion;
    switch (estado_actual) {
    case 0:
        if (c == '/')               return 1;
        if (c == '\'')              return 1;
        if (isdigit(c))             return 2; // Es un digito {0-9}
        if (isalpha(c))             return 3; // Es una letra {A-Z} U {a-z}
        if (c == '_')               return 4;
        if (c == '%')               return 5;
        if (c == '!')               return 6;
        if (c == '=')               return 7;
        if (escaracterespecial(c))  return 8; // Es un caracter especial {(,),{,},[,]}
        if (c == '\n')              return 9;
        if (esdel(c))               return 10; // Es un delimitador
        if (esc1(c))                return 11; // Es un caracter perteneciente al conjunto c1: c - {\n}
        if (esc2(c))
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    }
    return accion;
} */

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
