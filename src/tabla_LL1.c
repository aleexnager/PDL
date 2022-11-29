#include "header.h"

// Devolvemos un array de enteros, que en realidad
// son los códigos de los tokens, para luego
// poder apilarlos en el analizador

// Devolverá NULL en caso de que de error
// y así se podrá generar error desde el
// analizador

int es_terminal(int simb)
{
    if (simb == _P || simb == _B || simb == _T || simb == _S || simb == _W ||
        simb == _L || simb == _Q || simb == _X || simb == _F || simb == _H ||
        simb == _A || simb == _K || simb == _C || simb == _E || simb == _Y ||
        simb == _R || simb == _Z || simb == _U || simb == _V || simb == _J ||
        simb == _N)
        return 0;
    else
        return 1;
}

//* La variale regla nos permite guardar en la dirección de memoria a la que apunta regla
//* la regla que se ha aplicado, para posteriormente generar el parse

int *tabla_LL1(int s, int token, int *regla)
{
    static int lambda[1] = { -1 };
    switch (s)
    {
        case _P:
        {
            if (token == FOR)
            {
                *regla = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == FUNCTION)
            {
                *regla = 2;
                static int res[3] = { _P, _F, -1 };
                return res;
            }
            else if (token == ID)
            {
                *regla = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == IF)
            {
                *regla = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *regla = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == LET)
            {
                *regla = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *regla = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *regla = 1;
                static int res[3] = { _P, _B, -1 };
                return res;               
            }
            else if (token == _$)
            {
                *regla = 3;
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
                *regla = 6;
                static int res[13] = { LLAVE_DCH, _C, LLAVE_IZQ, PARENT_DCH, _E, _N, ID, PUNTO_COMA, _E, _S, PARENT_IZQ, FOR, -1 };
                return res;
            }
            else if (token == ID)
            {
                *regla = 7;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == IF)
            {
                *regla = 4;
                static int res[6] = { _S, PARENT_DCH, _E, PARENT_IZQ, IF, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *regla = 7;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == LET)
            {
                *regla = 5;
                static int res[5] = { PUNTO_COMA, _T, ID, LET, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *regla = 7;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *regla = 7;
                static int res[2] = { _S, -1 };
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
                *regla = 8;
                static int res[2] = { OP_MOD_ASIG, -1 };
                return res;
            }
            else if (token == OP_ASIG)
            {
                *regla = 9;
                static int res[2] = { OP_ASIG, -1 };
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
                *regla = 11;
                static int res[2] = { BOOLEAN, -1 };
                return res;              
            }
            else if (token == INT)
            {
                *regla = 10;
                static int res[2] = { INT, -1 };
                return res;
            }
            else if (token == STRING)
            {
                *regla = 12;
                static int res[2] = { STRING, -1 };
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
                *regla = 16;
                static int res[3] = { _W, ID, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *regla = 14;
                static int res[4] = { PUNTO_COMA, ID, INPUT, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *regla = 13;
                static int res[4] = { PUNTO_COMA, _E, PRINT, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *regla = 15;
                static int res[4] = { PUNTO_COMA, _X, RETURN, -1 };
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
                *regla = 18;
                static int res[5] = { PUNTO_COMA, _E, OP_MOD_ASIG, -1 };
                return res;
            }
            else if (token == OP_ASIG)
            {
                *regla = 17;
                static int res[4] = { PUNTO_COMA, _E, OP_ASIG, -1 };
                return res;                
            }
            else if (token == PARENT_IZQ)
            {
                *regla = 19;
                static int res[5] = { PUNTO_COMA, PARENT_DCH, _L, PARENT_IZQ, -1 };
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
                *regla = 20;
                static int res[3] = { _Q, _E, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *regla = 20;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == PARENT_DCH)
            {
                *regla = 21;
                return lambda;         
            }
            else if (token == CADENA)
            {
                *regla = 20;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == CTE_ENTERA)
            {
                *regla = 20;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == ID)
            {
                *regla = 20;
                static int res[3] = { _Q, _E, -1 };
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
                *regla = 23;
                return lambda;
            }
            else if (token == COMA)
            {
                *regla = 22;
                static int res[4] = { _Q, _E, COMA, -1 };
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
                *regla = 24;
                static int res[2] = { _E, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *regla = 24;
                static int res[2] = { _E, -1 };
                return res;
            }
	        else if (token == PUNTO_COMA)
            {
                *regla = 25;
                return lambda;
            }
	        else if (token == CADENA)
            {
                *regla = 24;
                static int res[2] = { _E, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *regla = 24;
                static int res[2] = { _E, -1 };
                return res;
            }
	        else if (token == ID)
            {
                *regla = 24;
                static int res[2] = { _E, -1 };
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
                *regla = 26;
                static int res[10] = { LLAVE_DCH, _C, LLAVE_IZQ, PARENT_DCH, _A, PARENT_IZQ, _H, ID, FUNCTION, -1 };
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
                *regla = 28;
                return lambda;
            }
            else if (token == BOOLEAN)
            {
                *regla = 27;
                static int res[2] = { _T, -1 };
                return res;
            }
	        else if (token == INT)
            {
                *regla = 27;
                static int res[2] = { _T, -1 };
                return res;
            }
	        else if (token == STRING)
            {
                *regla = 27;
                static int res[2] = { _T, -1 };
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
                *regla = 30;
                return lambda;
            }
            else if (token == BOOLEAN)
            {
                *regla = 29;
                static int res[4] = { _K, ID, _T, -1 };
                return res;
            }
	        else if (token == INT)
            {
                *regla = 29;
                static int res[4] = { _K, ID, _T, -1 };
                return res;
            }
	        else if (token == STRING)
            {
                *regla = 29;
                static int res[4] = { _K, ID, _T, -1 };
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
                *regla = 32;
                return lambda;
            }
            else if (token == COMA)
            {
                *regla = 31;
                static int res[5] = { _K, ID, _T, COMA, -1 };
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
                *regla = 33;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == ID)
            {
                *regla = 33;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == IF)
            {
                *regla = 33;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *regla = 33;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == LET)
            {
                *regla = 33;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *regla = 33;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *regla = 33;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == LLAVE_DCH)
            {
                *regla = 34;
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
                *regla = 35;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *regla = 35;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *regla = 35;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *regla = 35;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == ID)
            {
                *regla = 35;
                static int res[3] = { _Y, _R, -1 };
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
                *regla = 36;
                static int res[4] = { _Y, _R, OP_NEQ, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *regla = 37;
                return lambda;
            }
            else if (token == COMA)
            {
                *regla = 37;
                return lambda;
            }
            else if (token == PUNTO_COMA)
            {
                *regla = 37;
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
                *regla = 38;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *regla = 38;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *regla = 38;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *regla = 38;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == ID)
            {
                *regla = 38;
                static int res[3] = { _Z, _U, -1 };
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
                *regla = 40;
               	return lambda;
            }
            else if (token == OP_MODULO)
            {
                *regla = 39;
                static int res[4] = { _Z, _U, OP_MODULO, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *regla = 40;
                return lambda;
            }
	        else if (token == COMA)
            {
                *regla = 40;
                return lambda;
            }
            else if (token == PUNTO_COMA)
            {
                *regla = 40;
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
                *regla = 41;
                static int res[3] = { _V, OP_NEG, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *regla = 42;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *regla = 42;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *regla = 42;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == ID)
            {
                *regla = 42;
                static int res[2] = { _V, -1 };
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
                *regla = 44;
                static int res[4] = { PARENT_DCH, _E, PARENT_IZQ, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *regla = 46;
                static int res[2] = { CADENA, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *regla = 45;
                static int res[2] = { CTE_ENTERA, -1 };
                return res;
            }
            else if (token == ID)
            {
                *regla = 43;
                static int res[3] = { _J, ID, -1 };
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
                *regla = 48;
                return lambda;
            }
            else if (token == OP_MODULO)
            {
                *regla = 48;
                return lambda;
            }
            else if (token == PARENT_IZQ)
            {
                *regla = 47;
                static int res[4] = { PARENT_DCH, _L, PARENT_IZQ, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *regla = 48;
                return lambda;
            }
            else if (token == COMA)
            {
                *regla = 48;
                return lambda;
	        }
	        else if (token == PUNTO_COMA)
            {
                *regla = 48;
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
    return 0;
}
