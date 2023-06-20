#include "header.h"
#include "lifo.h"
#include "lifo_aux.h"
#include "ts2006.h"
#include <string.h>

int es_regla_semantica(int n_regla)
{
    if (n_regla >= 100)
        return TRUE;
    else
        return FALSE;
}

void ejecutar_regla_semantica(int id_tabla, int n_regla, int *despl, int *zona_decl)
{
    int i;
    switch (n_regla)
    {
    case 100:
    {
        *despl = 0;
        break;
    }
    case 101:
    {
        pop_aux();
        break;
    }
    case 102:
    {
        /*if (strcmp(get_aux_top()->next->next->data->lexema, "logico") == TRUE)
            strcpy(get_aux_top()->next->next->next->next->next->data->lexema, "logico");
        else
            // gen error
            strcpy(get_aux_top()->next->next->next->next->next->data->lexema, "tipo_error");
*/
        for (i = 0; i < 5; ++i)
            pop_aux();

        break;
    }
    case 103:
    {
        *zona_decl = TRUE;
        break;
    }
    case 104:
    {
        *zona_decl = FALSE;
        break;
    }
    case 105:
    {
        printf("%s\n", get_aux_top()->next->next->data->lexema);
        printf("%d\n", asignar_tipo_entrada(id_tabla, get_aux_top()->next->next->data->lexema, get_aux_top()->next->data->lexema));
        if (1)
            strcpy(get_aux_top()->next->next->next->next->data->lexema, "tipo_ok");
        else
            strcpy(get_aux_top()->next->next->next->next->data->lexema, "tipo_error");

        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 106:
    {
        for (i = 0; i < 11; ++i)
            pop_aux();

        break;
    }
    case 107:
    {
        break;
    }
    case 108:
    {
        pop_aux();
        break;
    }
    case 109:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 110:
    {
        break;
    }
    case 111:
    {
        strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 112:
    {
        strcpy(get_aux_top()->next->data->lexema, "tipo_ok");
        pop_aux();
        break;
    }
    case 113:
    {
        // strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 114:
    {
        strcpy(get_aux_top()->next->data->lexema, "logico");
        pop_aux();
        break;
    }
    case 115:
    {
        strcpy(get_aux_top()->next->data->lexema, "cadena");
        pop_aux();
        break;
    }
    case 116:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 117:
    {
        char *aux = consultar_tipo_entrada(id_tabla, get_aux_top()->next->data->lexema);
        printf("%s\n", aux);
        if (strcmp(aux, "cadena") == TRUE || strcmp(aux, "entero") == TRUE)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        }
        else
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
        }

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 118:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 119:
    {
    }
    case 120:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 121:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 122:
    {
    }
    case 123:
    {
        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 124:
    {
        break;
    }
    case 125:
    {
        break;
    }
    case 126:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 127:
    {
        break;
    }
    case 128:
    {
        break;
    }
    case 129:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 130:
    {
        break;
    }
    case 131:
    {
        pop_aux();
        break;
    }
    case 132:
    {
        break;
    }
    case 134:
    {
        break;
    }
    case 135:
    {
        break;
    }
    case 136:
    {
        break;
    }
    case 137:
    {
        break;
    }
    case 138:
    {
        break;
    }
    case 139:
    {
        for (i = 0; i < 9; ++i)
            pop_aux();

        break;
    }
    case 140:
    {
        pop_aux();
        break;
    }
    case 141:
    {
        break;
    }
    case 142:
    {
        break;
    }
    case 143:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 144:
    {
    }
    case 145:
    {
        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 146:
    {
        break;
    }
    case 147:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 148:
    {
        break;
    }
    case 149:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 150:
    {
        break;
    }
    case 151:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 152:
    {
        break;
    }
    case 153:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 154:
    {
        break;
    }
    case 155:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 156:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 157:
    {
        pop_aux();
        break;
    }
    case 158:
    {
        break;
    }
    case 159:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 160:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->data->lexema);
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 161:
    {
        strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 162:
    {
        strcpy(get_aux_top()->next->data->lexema, "cadena");
        pop_aux();
        break;
    }
    case 163:
    {
        break;
    }
    case 164:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    default:
    {
        break;
    }
    }
}
