#include "header.h"

// Devolvemos un array de enteros, que en realidad
// son los códigos de los tokens, para luego
// poder apilarlos en el analizador

// Devolverá NULL en caso de que de error
// y así se podrá generar error desde el
// analizador

int es_terminal(int simb)
{
    if (simb < 25)
        return TRUE;
    else
        return FALSE;
}

//* La variale regla nos permite guardar en la dirección de memoria a la que apunta regla
//* la regla que se ha aplicado, para posteriormente generar el parse

int *tabla_LL1(int s, int token, int *regla)
{
    static int lambda[1] = {-1};
    switch (s)
    {
    case _P_PRIMA:
    {
        if (token == FOR || token == FUNCTION || token == ID || token == IF || token == INPUT || token == LET || token == PRINT || token == RETURN || token == _FIN_CADENA)
        {
            *regla = 1;
            static int res[4] = {101, _P, 100, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _P:
    {
        if (token == FOR || token == ID || token == IF || token == INPUT || token == LET || token == PRINT || token == RETURN)
        {
            *regla = 2;
            static int res[3] = {_P, _B, -1};
            return res;
        }
        else if (token == FUNCTION)
        {
            *regla = 3;
            static int res[3] = {_P, _F, -1};
            return res;
        }
        else if (token == _FIN_CADENA)
        {
            *regla = 4;
            return lambda;
        }
        else
        {
            return NULL;
        }
    }
    case _B:
    {
        if (token == FOR)
        {
            *regla = 7;
            static int res[14] = {107, LLAVE_DCH, _C, 106, LLAVE_IZQ, PARENT_DCH, _M, PUNTO_COMA, _E, PUNTO_COMA, _M, PARENT_IZQ, FOR, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 8;
            static int res[4] = {109, _S, 108, -1};
            return res;
        }
        else if (token == IF)
        {
            *regla = 5;
            static int res[7] = {102, _S, PARENT_DCH, _E, PARENT_IZQ, IF, -1};
            return res;
        }
        else if (token == INPUT)
        {
            *regla = 8;
            static int res[4] = {109, _S, 108, -1};
            return res;
        }
        else if (token == LET)
        {
            *regla = 6;
            static int res[8] = {105, PUNTO_COMA, _T, 104, ID, 103, LET, -1};
            return res;
        }
        else if (token == PRINT)
        {
            *regla = 8;
            static int res[4] = {109, _S, 108, -1};
            return res;
        }
        else if (token == RETURN)
        {
            *regla = 8;
            static int res[4] = {109, _S, 108, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _M:
    {
        if (token == PARENT_DCH)
        {
            *regla = 10;
            static int res[2] = {111, -1};
            return res;
        }
        else if (token == PUNTO_COMA)
        {
            *regla = 10;
            static int res[2] = {111, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 9;
            static int res[5] = {110, _E, _N, ID, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _N:
    {
        if (token == OP_MOD_ASIG)
        {
            *regla = 11;
            static int res[3] = {112, OP_MOD_ASIG, -1};
            return res;
        }
        else if (token == OP_ASIG)
        {
            *regla = 12;
            static int res[3] = {113, OP_ASIG, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _T:
    {
        if (token == BOOLEAN)
        {
            *regla = 14;
            static int res[3] = {115, BOOLEAN, -1};
            return res;
        }
        else if (token == INT)
        {
            *regla = 13;
            static int res[3] = {114, INT, -1};
            return res;
        }
        else if (token == STRING)
        {
            *regla = 15;
            static int res[3] = {116, STRING, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _S:
    {
        if (token == ID)
        {
            *regla = 19;
            static int res[5] = {121, _W, 120, ID, -1};
            return res;
        }
        else if (token == INPUT)
        {
            *regla = 17;
            static int res[5] = {118, PUNTO_COMA, ID, INPUT, -1};
            return res;
        }
        else if (token == PRINT)
        {
            *regla = 16;
            static int res[5] = {117, PUNTO_COMA, _E, PRINT, -1};
            return res;
        }
        else if (token == RETURN)
        {
            *regla = 18;
            static int res[5] = {119, PUNTO_COMA, _X, RETURN, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _W:
    {
        if (token == OP_MOD_ASIG)
        {
            *regla = 20;
            static int res[5] = {122, PUNTO_COMA, _E, _N, -1};
            return res;
        }
        else if (token == PARENT_IZQ)
        {
            *regla = 21;
            static int res[7] = {124, PUNTO_COMA, PARENT_DCH, _L, 123, PARENT_IZQ, -1};
            return res;
        }
        else if (token == OP_ASIG)
        {
            *regla = 20;
            static int res[5] = {122, PUNTO_COMA, _E, _N, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _L:
    {
        if (token == OP_NEG)
        {
            *regla = 22;
            static int res[6] = {127, _Q, 126, _E, 125, -1};
            return res;
        }
        else if (token == PARENT_IZQ)
        {
            *regla = 22;
            static int res[6] = {127, _Q, 126, _E, 125, -1};
            return res;
        }
        else if (token == PARENT_DCH)
        {
            *regla = 23;
            return lambda;
        }
        else if (token == CADENA)
        {
            *regla = 22;
            static int res[6] = {127, _Q, 126, _E, 125, -1};
            return res;
        }
        else if (token == CTE_ENTERA)
        {
            *regla = 22;
            static int res[6] = {127, _Q, 126, _E, 125, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 22;
            static int res[6] = {127, _Q, 126, _E, 125, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _Q:
    {
        if (token == PARENT_DCH)
        {
            *regla = 25;
            static int res[2] = {131, -1};
            return res;
        }
        else if (token == COMA)
        {
            *regla = 24;
            static int res[7] = {130, _Q, 129, _E, 128, COMA, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _X:
    {
        if (token == OP_NEG)
        {
            *regla = 26;
            static int res[3] = {132, _E, -1};
            return res;
        }
        else if (token == PARENT_IZQ)
        {
            *regla = 26;
            static int res[3] = {132, _E, -1};
            return res;
        }
        else if (token == PUNTO_COMA)
        {
            *regla = 27;
            static int res[2] = {133, -1};
            return res;
        }
        else if (token == CADENA)
        {
            *regla = 26;
            static int res[3] = {132, _E, -1};
            return res;
        }
        else if (token == CTE_ENTERA)
        {
            *regla = 26;
            static int res[3] = {132, _E, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 26;
            static int res[3] = {132, _E, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _F:
    {
        if (token == FUNCTION)
        {
            *regla = 28;
            static int res[17] = {140, LLAVE_DCH, 139, _C, 138, LLAVE_IZQ, PARENT_DCH, _A, 137, PARENT_IZQ, 136, _H, 135, ID, 134, FUNCTION, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _H:
    {
        if (token == PARENT_IZQ)
        {
            *regla = 30;
            static int res[2] = {142, -1};
            return res;
        }
        else if (token == BOOLEAN)
        {
            *regla = 29;
            static int res[3] = {141, _T, -1};
            return res;
        }
        else if (token == INT)
        {
            *regla = 29;
            static int res[3] = {141, _T, -1};
            return res;
        }
        else if (token == STRING)
        {
            *regla = 29;
            static int res[3] = {141, _T, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _A:
    {
        if (token == PARENT_DCH)
        {
            *regla = 32;
            return lambda;
        }
        else if (token == BOOLEAN)
        {
            *regla = 31;
            static int res[6] = {144, _K, 14, ID, _T, -1};
            return res;
        }
        else if (token == INT)
        {
            *regla = 31;
            static int res[6] = {144, _K, 143, ID, _T, -1};
            return res;
        }
        else if (token == STRING)
        {
            *regla = 31;
            static int res[6] = {144, _K, 143, ID, _T, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _K:
    {
        if (token == PARENT_DCH)
        {
            *regla = 34;
            return lambda;
        }
        else if (token == COMA)
        {
            *regla = 33;
            static int res[7] = {146, _K, 145, ID, _T, COMA, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _C:
    {
        if (token == FOR)
        {
            *regla = 35;
            static int res[6] = {149, _C, 148, _B, 147, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 35;
            static int res[6] = {149, _C, 148, _B, 147, -1};
            return res;
        }
        else if (token == IF)
        {
            *regla = 35;
            static int res[6] = {149, _C, 148, _B, 147, -1};
            return res;
        }
        else if (token == INPUT)
        {
            *regla = 35;
            static int res[6] = {149, _C, 148, _B, 147, -1};
            return res;
        }
        else if (token == LET)
        {
            *regla = 35;
            static int res[6] = {149, _C, 148, _B, 147, -1};
            return res;
        }
        else if (token == PRINT)
        {
            *regla = 35;
            static int res[6] = {149, _C, 148, _B, 147, -1};
            return res;
        }
        else if (token == RETURN)
        {
            *regla = 35;
            static int res[6] = {149, _C, 148, _B, 147, -1};
            return res;
        }
        else if (token == LLAVE_DCH)
        {
            *regla = 36;
            return lambda;
        }
        else
        {
            return NULL;
        }
    }
    case _E:
    {
        if (token == OP_NEG)
        {
            *regla = 37;
            static int res[5] = {151, _Y, 150, _R, -1};
            return res;
        }
        else if (token == PARENT_IZQ)
        {
            *regla = 37;
            static int res[5] = {151, _Y, 150, _R, -1};
            return res;
        }
        else if (token == CADENA)
        {
            *regla = 37;
            static int res[5] = {151, _Y, 150, _R, -1};
            return res;
        }
        else if (token == CTE_ENTERA)
        {
            *regla = 37;
            static int res[5] = {151, _Y, 150, _R, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 37;
            static int res[5] = {151, _Y, 150, _R, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _Y:
    {
        if (token == OP_NEQ)
        {
            *regla = 38;
            static int res[6] = {153, _Y, 152, _R, OP_NEQ, -1};
            return res;
        }
        else if (token == PARENT_DCH)
        {
            *regla = 39;
            return lambda;
        }
        else if (token == COMA)
        {
            *regla = 39;
            return lambda;
        }
        else if (token == PUNTO_COMA)
        {
            *regla = 39;
            return lambda;
        }
        else
        {
            return NULL;
        }
    }
    case _R:
    {
        if (token == OP_NEG)
        {
            *regla = 40;
            static int res[5] = {155, _Z, 154, _U, -1};
            return res;
        }
        else if (token == PARENT_IZQ)
        {
            *regla = 40;
            static int res[5] = {155, _Z, 154, _U, -1};
            return res;
        }
        else if (token == CADENA)
        {
            *regla = 40;
            static int res[5] = {155, _Z, 154, _U, -1};
            return res;
        }
        else if (token == CTE_ENTERA)
        {
            *regla = 40;
            static int res[5] = {155, _Z, 154, _U, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 40;
            static int res[5] = {155, _Z, 154, _U, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _Z:
    {
        if (token == OP_NEQ)
        {
            *regla = 42;
            return lambda;
        }
        else if (token == OP_MODULO)
        {
            *regla = 41;
            static int res[5] = {157, _Z, _U, OP_MODULO, -1};
            return res;
        }
        else if (token == PARENT_DCH)
        {
            *regla = 42;
            return lambda;
        }
        else if (token == COMA)
        {
            *regla = 42;
            return lambda;
        }
        else if (token == PUNTO_COMA)
        {
            *regla = 42;
            return lambda;
        }
        else
        {
            return NULL;
        }
    }
    case _U:
    {
        if (token == OP_NEG)
        {
            *regla = 43;
            static int res[4] = {158, _V, OP_NEG, -1};
            return res;
        }
        else if (token == PARENT_IZQ)
        {
            *regla = 44;
            static int res[3] = {159, _V, -1};
            return res;
        }
        else if (token == CADENA)
        {
            *regla = 44;
            static int res[3] = {159, _V, -1};
            return res;
        }
        else if (token == CTE_ENTERA)
        {
            *regla = 44;
            static int res[3] = {159, _V, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 44;
            static int res[3] = {159, _V, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _V:
    {
        if (token == PARENT_IZQ)
        {
            *regla = 46;
            static int res[5] = {162, PARENT_DCH, _E, PARENT_IZQ, -1};
            return res;
        }
        else if (token == CADENA)
        {
            *regla = 48;
            static int res[3] = {164, CADENA, -1};
            return res;
        }
        else if (token == CTE_ENTERA)
        {
            *regla = 47;
            static int res[3] = {163, CTE_ENTERA, -1};
            return res;
        }
        else if (token == ID)
        {
            *regla = 45;
            static int res[5] = {161, _J, 160, ID, -1};
            return res;
        }
        else
        {
            return NULL;
        }
    }
    case _J:
    {
        if (token == OP_NEQ)
        {
            *regla = 50;
            return lambda;
        }
        else if (token == OP_MODULO)
        {
            *regla = 50;
            return lambda;
        }
        else if (token == PARENT_IZQ)
        {
            *regla = 49;
            static int res[6] = {166, PARENT_DCH, _L, 165, PARENT_IZQ, -1};
            return res;
        }
        else if (token == PARENT_DCH)
        {
            *regla = 50;
            return lambda;
        }
        else if (token == COMA)
        {
            *regla = 50;
            return lambda;
        }
        else if (token == PUNTO_COMA)
        {
            *regla = 50;
            return lambda;
        }
        else
        {
            return NULL;
        }
    }
    default:
    {
        return NULL;
    }
    }
}
