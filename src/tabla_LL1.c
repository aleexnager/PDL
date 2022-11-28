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

//* La variale aux nos permite guardar en la dirección de memoria a la que apunta aux
//* la regla que se ha aplicado, para posteriormente generar el parse

int *tabla_LL1(int s, int token, int *aux)
{
    static int lambda[1] = { -1 };
    switch (s)
    {
        case _P:
        {
            if (token == FOR)
            {
                *aux = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == FUNCTION)
            {
                *aux = 2;
                static int res[3] = { _P, _F, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == IF)
            {
                *aux = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *aux = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == LET)
            {
                *aux = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *aux = 1;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *aux = 1;
                static int res[3] = { _P, _B, -1 };
                return res;               
            }
            else if (token == _$)
            {
                *aux = 3;
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
                *aux = 6;
                static int res[13] = { LLAVE_DCH, _C, LLAVE_IZQ, PARENT_DCH, _E, _N, ID, PUNTO_COMA, _E, _S, PARENT_IZQ, FOR, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 7;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == IF)
            {
                *aux = 4;
                static int res[6] = { _S, PARENT_DCH, _E, PARENT_IZQ, IF, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *aux = 7;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == LET)
            {
                *aux = 5;
                static int res[5] = { PUNTO_COMA, _T, ID, LET, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *aux = 7;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *aux = 7;
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
                *aux = 8;
                static int res[2] = { OP_MOD_ASIG, -1 };
                return res;
            }
            else if (token == OP_ASIG)
            {
                *aux = 9;
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
                *aux = 11;
                static int res[2] = { BOOLEAN, -1 };
                return res;              
            }
            else if (token == INT)
            {
                *aux = 10;
                static int res[2] = { INT, -1 };
                return res;
            }
            else if (token == STRING)
            {
                *aux = 12;
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
                *aux = 16;
                static int res[3] = { _W, ID, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *aux = 14;
                static int res[4] = { PUNTO_COMA, ID, INPUT, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *aux = 13;
                static int res[4] = { PUNTO_COMA, _E, PRINT, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *aux = 15;
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
                *aux = 18;
                static int res[5] = { PUNTO_COMA, _E, OP_MOD_ASIG, -1 };
                return res;
            }
            else if (token == OP_ASIG)
            {
                *aux = 17;
                static int res[4] = { PUNTO_COMA, _E, OP_ASIG, -1 };
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
                *aux = 19;
                static int res[3] = { _Q, _E, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 19;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == PARENT_DCH)
            {
                *aux = 20;
                return lambda;         
            }
            else if (token == CADENA)
            {
                *aux = 19;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 19;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == ID)
            {
                *aux = 19;
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
                *aux = 22;
                return lambda;
            }
            else if (token == COMA)
            {
                *aux = 21;
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
                *aux = 23;
                static int res[2] = { _E, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 23;
                static int res[2] = { _E, -1 };
                return res;
            }
	        else if (token == PUNTO_COMA)
            {
                *aux = 24;
                return lambda;
            }
	        else if (token == CADENA)
            {
                *aux = 23;
                static int res[2] = { _E, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 23;
                static int res[2] = { _E, -1 };
                return res;
            }
	        else if (token == ID)
            {
                *aux = 23;
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
                *aux = 25;
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
                *aux = 27;
                return lambda;
            }
            else if (token == BOOLEAN)
            {
                *aux = 26;
                static int res[2] = { _T, -1 };
                return res;
            }
	        else if (token == INT)
            {
                *aux = 26;
                static int res[2] = { _T, -1 };
                return res;
            }
	        else if (token == STRING)
            {
                *aux = 26;
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
                *aux = 29;
                return lambda;
            }
            else if (token == BOOLEAN)
            {
                *aux = 28;
                static int res[4] = { _K, ID, _T, -1 };
                return res;
            }
	        else if (token == INT)
            {
                *aux = 28;
                static int res[4] = { _K, ID, _T, -1 };
                return res;
            }
	        else if (token == STRING)
            {
                *aux = 28;
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
                *aux = 31;
                return lambda;
            }
            else if (token == COMA)
            {
                *aux = 30;
                static int res[5] = { K, ID, _T, COMA, -1 };
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
                *aux = 32;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 32;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == IF)
            {
                *aux = 32;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *aux = 32;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == LET)
            {
                *aux = 32;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *aux = 32;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *aux = 32;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == LLAVE_DCH)
            {
                *aux = 33;
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
                *aux = 34;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 34;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *aux = 34;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 34;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 34;
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
                *aux = 35;
                static int res[4] = { _Y, _R, OP_NEQ, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *aux = 36;
                return lambda;
            }
            else if (token == COMA)
            {
                *aux = 36;
                return lambda;
            }
            else if (token == PUNTO_COMA)
            {
                *aux = 36;
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
                *aux = 37;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 37;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *aux = 37;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 37;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 37;
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
                *aux = 39;
               	return lambda;
            }
            else if (token == OP_MODULO)
            {
                *aux = 38;
                static int res[4] = { _Z, _U, OP_MODULO, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *aux = 39;
                return lambda;
            }
	        else if (token == COMA)
            {
                *aux = 39;
                return lambda;
            }
            else if (token == PUNTO_COMA)
            {
                *aux = 39;
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
                *aux = 40;
                static int res[3] = { _V, OP_NEG, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 41;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *aux = 41;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 41;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 41;
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
                *aux = 43;
                static int res[4] = { PARENT_DCH, _E, PARENT_IZQ, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *aux = 45;
                static int res[2] = { CADENA, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 44;
                static int res[2] = { CTE_ENTERA, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 42;
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
                *aux = 47;
                return lambda;
            }
            else if (token == OP_MODULO)
            {
                *aux = 47;
                return lambda;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 46;
                static int res[4] = { PARENT_DCH, _L, PARENT_IZQ, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *aux = 47;
                return lambda;
            }
            else if (token == COMA)
            {
                *aux = 47;
                return lambda;
	        }
	        else if (token == PUNTO_COMA)
            {
                *aux = 47;
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
