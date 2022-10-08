#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"

// FUNCIONES PARA DETERMINAR DE QUE TIPO ES EL CARÁCTER QUE SE HA LEÍDO

int escaracterespecial(char c) {
    if (c == '(' ||
        c == ')' ||
        c == '{' ||
        c == '}' ||
        c == ',' ||
        c == ';'  ) {

        return 1;
    } else {
        return 0;
    }
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

// FIN DE LAS FUNCIONES DE CARÁCTER

// FUNCIONES QUE A PARTIR DE UN ESTADO ACTUAL Y UN CARÁCTER LEÍDO, PERMITE DEVOLVER
// EL ESTADO SIGUIENTE AL QUE SE DEBE TRANSITAR

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
        if (c == '(')               sig_estado = 109; break;
        if (c == ')')               sig_estado = 110; break;
        if (c == '{')               sig_estado = 111; break;
        if (c == '}')               sig_estado = 112; break;
        if (c == ';')               sig_estado = 113; break;
        if (c == ',')               sig_estado = 114; break;
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

int mt_afd_accion(int estado_actual, char c) {
    int sig_accion;
    switch (estado_actual) {
    case 0:
        if (c == '/')               sig_accion = A; break;
        if (c == '%')               sig_accion = A; break;
        if (c == '!')               sig_accion = A; break;
        if (esdel(c) || c == '\n')  sig_accion = A; break;
        if (c == '\'')              sig_accion = B; break;
        if (isdigit(c))             sig_accion = E; break;
        if (isalpha(c) || c == '_') sig_accion = H; break;
        if (c == '=')               sig_accion = O; break;
        if (c == '(')               sig_accion = P; break;
        if (c == ')')               sig_accion = Q; break;
        if (c == '{')               sig_accion = R; break;
        if (c == '}')               sig_accion = S; break;
        if (c == ';')               sig_accion = T; break;
        if (c == ',')               sig_accion = U; break;
        sig_accion = 50; break;
    case 1:
        if (c == '/')               sig_accion = A; break;
        sig_accion = 51; break;
    case 2:
        if (esc1(c) || c == '\n')   sig_accion = A; break;
        sig_accion = 52; break;
    case 3:
        if (esc2(c))                sig_accion = C; break;
        if (c == '\'')              sig_accion = D; break;
        sig_accion = 53; break;
    case 4:
        if (isdigit(c)) {
            sig_accion = F; break;
        } else {
            sig_accion = G; break;
        }
        sig_accion = 54; break;
    case 5:
        if (isalpha(c) || isdigit(c) || c == '_') {
            sig_accion = I; break;
        } else {
            sig_accion = J; break;
        }
        sig_accion = 55; break;
    case 6:
        if (c == '=') {
            sig_accion = A; break;
        } else {
            sig_accion = K; break;
        }
        sig_accion = 56; break;
    case 7:
        sig_accion = L; break;
    case 8:
        if (c == '=') {
            sig_accion = A; break;
        } else {
            sig_accion = M; break;
        }
        sig_accion = 57; break;
    case 9:
        sig_accion = N; break;
    }
    return sig_accion;
}

// FUNCION QUE PERMITE GENERAR UN ERROR DEPENDIENDO DE UN PARÁMETRO DE ENTRADA QUE ES
// EL CÓDIGO DE ERROR

void gen_error(int cod_error) {
    switch (cod_error) {
        case 50:
        break;
        case 51:
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
}

int gen_pal_res(char* lexema) {
    
}

// FUNCION QUE IMPLEMENTA EL FUNCIONAMIENTO DE ANALIZADOR LÉXICO, SU FUNCIÓN ES LEER DESDE UN FP, HABIENDO
// LEIDO YA UN CARÁCTER Y GENERAR UN TOKEN O GENERAR UN ERROR

void analizador_lexico(FILE *fp, char c) {
    int estado = 0;
    int accion;
    char leido = c;
    char* lexema;
    int valor;
    while (estado < 10)
    {
        estado = mt_afd_estado(estado, leido);
        accion = mt_afd_accion(estado, leido);

        if (estado == -1) gen_error(accion);

        switch (accion) {
            case A:
                c = fgetc(fp); break;
            case B:
                c = fgetc(fp);
                break;
            case C:
                lexema = strncat(lexema, &c, 1);
                c = fgetc(fp);
                break;
            case D:
                if (strlen(lexema) < 65) {
                    gen_token(CADENA, lexema); break;
                } else {
                    gen_error(59);
                }
            case E:
                valor = c - '0';
                c = fgetc(fp);
                break;
            case F:
                valor += c - '0';
            case G:
                if (valor > -32768 && valor < 32768) {
                    gen_token(CTE_ENTERA, valor);
                } else {
                    gen_error(60);
                }
            case H:
                lexema = strncat(lexema, &c, 1);
                c = fgetc(fp);
                break;
            case I:
                lexema = strncat(lexema, &c, 1);
                c = fgetc(fp);
                break;
            case J:
                /* if (lexema.palRes()) {
                    gen_token(lexema, -);
                } else if ( (pos = lexema.enTS()) ) {
                    gen_token(ID, pos);
                } else {
                    pos = lexema.insertar();
                    gen_token(ID, pos);
                } */
            case K:
                gen_token(OP_MODULO, NULL);
            case L:
                gen_token(OP_MOD_ASIG, NULL);
            case M:
                gen_token(OP_NEG, NULL);
            case N:
                gen_token(OP_NEQ, NULL);
            case O:
                c = fgetc(fp);
                gen_token(OP_ASIG, NULL);
                break;
            case P:
                c = fgetc(fp);
                gen_token(PARENT_IZQ, NULL);
                break;
            case Q:
                c = fgetc(fp);
                gen_token(PARENT_DCH, NULL);
                break;
            case R:
                c = fgetc(fp);
                gen_token(LLAVE_IZQ, NULL);
                break;
            case S:
                c = fgetc(fp);
                gen_token(LLAVE_DCH, NULL);
                break;
            case T:
                c = fgetc(fp);
                gen_token(PUNTO_COMA, NULL);
                break;
            case U:
                c = fgetc(fp);
                gen_token(COMA, NULL);
                break;
        }
    }
}

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) exit(1);

    analizador_lexico(fp, fgetc(fp)); 

    return 0;
}
