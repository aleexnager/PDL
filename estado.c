#include <ctype.h>
#include "header.h"

int mt_afd_estado(int estado_actual, char c) {
    int sig_estado;
    switch (estado_actual) {
    case 0:
        if (c == '/') {
            sig_estado = 1;
            break;
        }
        if (c == '\'') {
            sig_estado = 3;
            break;
        }
        if (isdigit(c)) {
            sig_estado = 4;
            break;
        }
        if (isalpha(c) || c == '_') {
            sig_estado = 5;
            break;
        }
        if (c == '%') {
            sig_estado = 6;
            break;
        }
        if (c == '!') {
            sig_estado = 7;
            break;
        }
        if (c == '=') {
            sig_estado = 108;
            break;
        }
        if (c == '(') {
            sig_estado = 109;
            break;
        }
        if (c == ')') {
            sig_estado = 110;
            break;
        }
        if (c == '{') {
            sig_estado = 111;
            break;
        }
        if (c == '}') {
            sig_estado = 112;
            break;
        }
        if (c == ';') {
            sig_estado = 113;
            break;
        }
        if (c == ',') {
            sig_estado = 114;
            break;
        }
        if (esdel(c) || c == '\n') {
            sig_estado = 0;
            break;
        }
        sig_estado = -1; break;
    case 1:
        if (c == '/') {
            sig_estado = 2;
            break;
        }
        sig_estado = -1; break;
    case 2:
        if (esc1(c)) {
            sig_estado = 2;
            break;
        }
        if (c == '\n') {
            sig_estado = 0;
            break;
        }
        sig_estado = -1; break;
    case 3:
        if (esc2(c)) {
            sig_estado = 3;
            break;
        }
        if (c == '\'') {
            sig_estado = 101;
            break;
        }
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
            sig_estado = 105; break;
        } else {
            sig_estado = 104; break;
        }
        sig_estado = -1; break;
    case 7:
        if (c == '=') {
            sig_estado = 107; break;
        } else {
            sig_estado = 106; break;
        }
        sig_estado = -1; break;
    }
    return sig_estado;
}
