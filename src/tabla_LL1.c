#include "header.h"

// Devolvemos un array de enteros, que en realidad
// son los códigos de los tokens, para luego
// poder apilarlos en el analizador

// Devolverá NULL en caso de que de error
// y así se podrá generar error desde el
// analizador

// Devolvemos los símbolos del consecuente en orden
// inverso, además ponemos un -1 en el final del array
// para poder iterar con facilidad en la función del analizador
// sintáctico
//
// Ejemplo:
//   int c;
// - while ((c = res[i]) != -1)
//   {
//       push(c);
//       ++i;
//   }

int *tabla_LL1(int s, int token)
{
    switch (s)
    {
        case _P:
        {
            if (token == FOR)
            {
                int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == FUNCTION)
            {
                int res[3] = { _P, _F, -1 };
                return res;
            }
            else if (token == ID)
            {
                int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == IF)
            {
                int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == LET)
            {
                int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                int res[3] = { _P, _B, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                int res[3] = { _P, _B, -1 };
                return res;               
            }
            else if (token == _$)
            {
                // return lambda;
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
                int res[12] = { LLAVE_DCH, _S, LLAVE_IZQ, PARENT_DCH, _S, PUNTO_COMA, _E, PUNTO_COMA, _S, PARENT_IZQ, FOR, -1 };
                return res;
            }
            else if (token == ID)
            {
                int res[2] = { _S, -1 };
                return res;
            }
            else if (token == IF)
            {
                int res[6] = { _S, PARENT_DCH, _E, PARENT_IZQ, IF, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                int res[2] = { _S, -1 };
                return res;
            }
            else if (token == LET)
            {
                int res[5] = { PUNTO_COMA, _T, ID, LET, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                int res[2] = { _S, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                int res[2] = { _S, -1 };
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
                int res[2] = { BOOLEAN, -1 };
                return res;              
            }
            else if (token == INT)
            {
                int res[2] = { INT, -1 };
                return res;
            }
            else if (token == STRING)
            {
                int res[2] = { STRING, -1 };
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
                int res[3] = { _W, ID, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                int res[4] = { PUNTO_COMA, ID, INPUT, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                int res[4] = { PUNTO_COMA, _E, PRINT, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                int res[4] = { PUNTO_COMA, _X, RETURN, -1 };
                return res;
            }
            else
            {
                return NULL;
            }
        }
        case _W:
        {
            if (token == OP_MODULO)
            {
                int res[5] = { PUNTO_COMA, _E, OP_MOD_ASIG, -1 };
                return res;
            }
            else if (token == OP_ASIG)
            {
                int res[4] = { PUNTO_COMA, _E, OP_ASIG, -1 };
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
                int res[3] = { _Q, _E, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == PARENT_DCH)
            {
                // return lambda               
            }
            else if (token == CADENA)
            {
                int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == CTE_ENTERA)
            {
                int res[3] = { _Q, _E, -1 };
                return res;                
            }
            else if (token == ID)
            {
                int res[3] = { _Q, _E, -1 };
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
                // return lambda
            }
            else if (token == COMA)
            {
                int res[4] = { _Q, _E, COMA, -1 };
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
                int res[2] = { _E, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                int res[2] = { _E, -1 };
                return res;
            }
	        else if (token == PUNTO_COMA)
            {
                // retrun lambda;
            }
	        else if (token == CADENA)
            {
                int res[2] = { _E, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                int res[2] = { _E, -1 };
                return res;
            }
	        else if (token == ID)
            {
                int res[2] = { _E, -1 };
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
                int res[10] = { LLAVE_DCH, _C, LLAVE_IZQ, PARENT_DCH, _A, PARENT_IZQ, _H, ID, FUNCTION, -1 };
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
                // retrun lambda;
            }
            else if (token == BOOLEAN)
            {
                int res[2] = { _T, -1 };
                return res;
            }
	        else if (token == INT)
            {
                int res[2] = { _T, -1 };
                return res;
            }
	        else if (token == STRING)
            {
                int res[2] = { _T, -1 };
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
                // retrun lambda;
            }
            else if (token == BOOLEAN)
            {
                int res[4] = { _K, ID, _T, -1 };
                return res;
            }
	        else if (token == INT)
            {
                int res[4] = { _K, ID, _T, -1 };
                return res;
            }
	        else if (token == STRING)
            {
                int res[4] = { _K, ID, _T, -1 };
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
                // retrun lambda;
            }
            else if (token == COMA)
            {
                int res[5] = { K, ID, _T, COMA, -1 };
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
                int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == ID)
            {
                int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == IF)
            {
                int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == INPUT)
            {
                int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == LET)
            {
                int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == PRINT)
            {
                int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == RETURN)
            {
                int res[3] = { _C, _B, -1 };
                return res;
            }
            else if (token == LLAVE_DCH)
            {
                // return lambda;
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
                int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                int res[3] = { _Y, _R, -1 };
                return res;
            }
            else if (token == ID)
            {
                int res[3] = { _Y, _R, -1 };
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
                int res[4] = { _Y, _R, OP_NEQ, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                // retrun lambda;
            }
            else if (token == COMA)
            {
                // retrun lambda;
            }
            else if (token == PUNTO_COMA)
            {
                // retrun lambda;
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
                int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                int res[3] = { _Z, _U, -1 };
                return res;
            }
            else if (token == ID)
            {
                int res[3] = { _Z, _U, -1 };
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
               	// retrun lambda;
            }
            else if (token == OP_MODULO)
            {
                int res[4] = { _Z, _U, OP_MODULO, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                // retrun lambda;
            }
	        else if (token == COMA)
            {
                // retrun lambda;
            }
            else if (token == PUNTO_COMA)
            {
                // retrun lambda;
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
                int res[3] = { _V, OP_NEG, -1 };
                return res;
            }
            else if (token == PARENT_IZQ)
            {
                int res[2] = { _V, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                int res[2] = { _V, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                int res[2] = { _V, -1 };
                return res;
            }
            else if (token == ID)
            {
                int res[2] = { _V, -1 };
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
                int res[4] = { PARENT_DCH, _E, PARENT_IZQ, -1 };
                return res;
            }
            else if (token == CADENA)
            {
                int res[2] = { CADENA, -1 };
                return res;
            }
            else if (token == CTE_ENTERA)
            {
                int res[2] = { CTE_ENTERA, -1 };
                return res;
            }
            else if (token == ID)
            {
                int res[3] = { _J, ID, -1 };
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
                // retrun lambda;
            }
            else if (token == OP_MODULO)
            {
                // retrun lambda;
            }
            else if (token == PARENT_IZQ)
            {
                int res[4] = { PARENT_DCH, _L, PARENT_IZQ, -1 };
                return res;
            }
            else if (token == PARENT_DCH)
            {
                // retrun lambda;
            }
            else if (token == COMA)
            {
                // retrun lambda;
	        }
	        else if (token == PUNTO_COMA)
            {
                // retrun lambda;
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
