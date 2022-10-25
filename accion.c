#include <ctype.h>
#include "header.h"

int mt_afd_accion(int estado_actual, char c) {
    int sig_accion;
    switch (estado_actual) {
    case 0:
        if (c == '/' || c == '%' || c == '!' || esdel(c) || c == '\n' || c == EOF) {
            sig_accion = A;
            break;   
        }
        if (c == '\'') {
            sig_accion = B;
            break;
        }
        if (isdigit(c)) {
            sig_accion = E;
            break;
        }
        if (isalpha(c) || c == '_') {
            sig_accion = H;
            break;
        }
        if (c == '=') {
            sig_accion = O;
            break;
        }
        if (c == '(') {
            sig_accion = P;
            break;
        }
        if (c == ')') {
            sig_accion = Q;
            break;
        }
        if (c == '{') {
            sig_accion = R;
            break;   
        }
        if (c == '}') {
            sig_accion = S;
            break;
        }
        if (c == ';') {
            sig_accion = T;
            break;
        }
        if (c == ',') {
            sig_accion = U;
            break;
        }
        sig_accion = 50; break;
    case 1:
        if (c == '/') {
            sig_accion = A;
            break;
        }
        if (c == '%') {
            sig_accion = 51;
            break;
        }
        if (c == '!') {
            sig_accion = 52;
            break;
        }
        if (c == '=') {
            sig_accion = 53;
            break;
        }
        if (c == '(') {
            sig_accion = 54;
            break;
        }
        if (c == ')') {
            sig_accion = 55;
            break;
        }
        if (c == '{') {
            sig_accion = 56;
            break;
        }
        if (c == '}') {
            sig_accion = 57;
            break;
        }
        if (c == ';') {
            sig_accion = 58;
            break;
        }
        if (c == ',') {
            sig_accion = 59;
            break;
        }
        if (esdel(c) || c == '\n') {
            sig_accion = 60;
            break;
        }
        if (c == '\'') {
            sig_accion = 61;
            break;
        }
        if (isalpha(c)) {
            sig_accion = 62;
            break;
        }
        if (isdigit(c)) {
            sig_accion = 63;
            break;
        }
        if (c == '_') {
            sig_accion = 64;
            break;
        }
        if (isascii(c)) {
            sig_accion = 65;
            break;
        }
    case 2:
        if (isascii(c)) {
            sig_accion = A;
            break;
        }
    case 3:
        if (esc2(c)) {
            sig_accion = C;
            break;
        }
        if (c == '\'') {
            sig_accion = D;
            break;
        }
    case 4:
        if (isdigit(c)) {
            sig_accion = F; break;
        } else if (isspace(c) || c == ';') {
            sig_accion = G; break;
        }
    case 5:
        if (isalpha(c) || isdigit(c) || c == '_') {
            sig_accion = I; break;
        } else {
            sig_accion = J; break;
        }
    case 6:
        if (c == '=') {
            sig_accion = L; break;
        } else {
            sig_accion = K; break;
        }
    case 7:
        if (c == '=') {
            sig_accion = N; break;
        } else {
            sig_accion = M; break;
        }
    }
    return sig_accion;
}