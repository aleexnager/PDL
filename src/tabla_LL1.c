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
                *aux = 0;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == FUNCTION)
            {
                *aux = 0;
                static int res[3] = { _P, _F, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 0;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == IF)
            {
                *aux = 0;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *aux = 0;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == LET)
            {
                *aux = 0;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *aux = 0;
                static int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *aux = 0;
                static int res[3] = { _P, _B, -1 };
                return res;               
            }
            else if (token == _$)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[13] = { LLAVE_DCH, _C, LLAVE_IZQ, PARENT_DCH, _E, _N, ID, PUNTO_COMA, _E, _S, PARENT_IZQ, FOR, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 0;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == IF)
            {
                *aux = 0;
                static int res[6] = { _S, PARENT_DCH, _E, PARENT_IZQ, IF, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *aux = 0;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == LET)
            {
                *aux = 0;
                static int res[5] = { PUNTO_COMA, _T, ID, LET, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *aux = 0;
                static int res[2] = { _S, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[2] = { OP_MOD_ASIG, -1 };
                return res;
            }
            else if (token == OP_ASIG)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[2] = { BOOLEAN, -1 };
                return res;              
            }
            else if (token == INT)
            {
                *aux = 0;
                static int res[2] = { INT, -1 };
                return res;
            }
            else if (token == STRING)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[3] = { _W, ID, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *aux = 0;
                static int res[4] = { PUNTO_COMA, ID, INPUT, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *aux = 0;
                static int res[4] = { PUNTO_COMA, _E, PRINT, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[5] = { PUNTO_COMA, _E, OP_MOD_ASIG, -1 };
                return res;
            }
            else if (token == OP_ASIG)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[3] = { _Q, _E, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 0;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == PARENT_DCH)
            {
                *aux = 0;
                return lambda;         
            }
            else if (token == CADENA)
            {
                *aux = 0;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 0;
                static int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == ID)
            {
                *aux = 0;
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
                *aux = 0;
                return lambda;
            }
            else if (token == COMA)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[2] = { _E, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 0;
                static int res[2] = { _E, -1 };
                return res;
            }
	        else if (token == PUNTO_COMA)
            {
                *aux = 0;
                return lambda;
            }
	        else if (token == CADENA)
            {
                *aux = 0;
                static int res[2] = { _E, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 0;
                static int res[2] = { _E, -1 };
                return res;
            }
	        else if (token == ID)
            {
                *aux = 0;
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
                *aux = 0;
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
                *aux = 0;
                return lambda;
            }
            else if (token == BOOLEAN)
            {
                *aux = 0;
                static int res[2] = { _T, -1 };
                return res;
            }
	        else if (token == INT)
            {
                *aux = 0;
                static int res[2] = { _T, -1 };
                return res;
            }
	        else if (token == STRING)
            {
                *aux = 0;
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
                *aux = 0;
                return lambda;
            }
            else if (token == BOOLEAN)
            {
                *aux = 0;
                static int res[4] = { _K, ID, _T, -1 };
                return res;
            }
	        else if (token == INT)
            {
                *aux = 0;
                static int res[4] = { _K, ID, _T, -1 };
                return res;
            }
	        else if (token == STRING)
            {
                *aux = 0;
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
                *aux = 0;
                return lambda;
            }
            else if (token == COMA)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 0;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == IF)
            {
                *aux = 0;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                *aux = 0;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == LET)
            {
                *aux = 0;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                *aux = 0;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                *aux = 0;
                static int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == LLAVE_DCH)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 0;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *aux = 0;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 0;
                static int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[4] = { _Y, _R, OP_NEQ, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *aux = 0;
                return lambda;
            }
            else if (token == COMA)
            {
                *aux = 0;
                return lambda;
            }
            else if (token == PUNTO_COMA)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 0;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *aux = 0;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 0;
                static int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 0;
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
                *aux = 0;
               	return lambda;
            }
            else if (token == OP_MODULO)
            {
                *aux = 0;
                static int res[4] = { _Z, _U, OP_MODULO, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *aux = 0;
                return lambda;
            }
	        else if (token == COMA)
            {
                *aux = 0;
                return lambda;
            }
            else if (token == PUNTO_COMA)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[3] = { _V, OP_NEG, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 0;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *aux = 0;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 0;
                static int res[2] = { _V, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 0;
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
                *aux = 0;
                static int res[4] = { PARENT_DCH, _E, PARENT_IZQ, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                *aux = 0;
                static int res[2] = { CADENA, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                *aux = 0;
                static int res[2] = { CTE_ENTERA, -1 };
                return res;
            }
            else if (token == ID)
            {
                *aux = 0;
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
                *aux = 0;
                return lambda;
            }
            else if (token == OP_MODULO)
            {
                *aux = 0;
                return lambda;
            }
            else if (token == PARENT_IZQ)
            {
                *aux = 0;
                static int res[4] = { PARENT_DCH, _L, PARENT_IZQ, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                *aux = 0;
                return lambda;
            }
            else if (token == COMA)
            {
                *aux = 0;
                return lambda;
	        }
	        else if (token == PUNTO_COMA)
            {
                *aux = 0;
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
