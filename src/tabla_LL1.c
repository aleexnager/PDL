#include "header.h"

// Devolvemos un array de enteros, que en realidad
// son los códigos de los tokens, para luego
// poder apilarlos en el analizador

// Devolverá NULL en caso de que de error
// y así se podrá generar error desde el
// analizador

int *tabla_LL1(int s, int token)
{
    switch (s)
    {
        case _P:
        {
            if (token == FOR)
            {
                int res[3] = { _B, _P, -1 };
                return res;
            }
            else if (token == FUNCTION)
            {
                
            }
            else if (token == ID)
            {

            }
            else if (token == IF)
            {

            }
            else if (token == INPUT)
            {

            }
            else if (token == LET)
            {

            }
            else if (token == PRINT)
            {

            }
            else if (token == RETURN)
            {
                
            }
            else if (token == _EOF)
            {

            }
            else
            {
                return NULL;
            }
        }
        case _B:
        {

        }
        case _T:
        {

        }
        case _S:
        {

        }
        case _W:
        {

        }
        case _L:
        {

        }
        case _Q:
        {

        }
        case _X:
        {

        }
        case _F:
        {

        }
        case _H:
        {

        }
        case _A:
        {

        }
        case _K:
        {

        }
        case _C:
        {

        }
        case _E:
        {

        }
        case _Y:
        {

        }
        case _R:
        {

        }
        case _Z:
        {

        }
        case _U:
        {

        }
        case _V:
        {

        }
        case _J:
        {

        }
        default:
        {
            //! gen_error()
        }
    }
    return 0;
}
