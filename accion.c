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
        sig_accion = 51; break;
    case 2:
        if (esc1(c) || c == '\n') {
            sig_accion = A;
            break;
        }
        sig_accion = 52; break;
    case 3:
        if (esc2(c)) {
            sig_accion = C;
            break;
        }
        if (c == '\'') {
            sig_accion = D; break;
        }
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
