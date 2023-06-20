#include "header.h"
#include "lifo.h"
#include "lifo_aux.h"

int es_regla_semantica(int n_regla)
{
    if (n_regla >= 100)
        return TRUE;
    else
        return FALSE;
}

void ejecutar_regla_semantica(int n_regla, int *despl, int *zona_decl)
{
    int i;
    switch (n_regla)
    {
    case 100:
    {
        *despl = 0;
    }
    case 101:
    {
        pop_aux();
    }
    case 102:
    {
        for (i = 0; i < 5; ++i)
            pop_aux();
    }
    case 103:
    {
        *zona_decl = TRUE;
    }
    case 104:
    {
        *zona_decl = FALSE;
    }
    case 105:
    {
        for (i = 0; i < 4; ++i)
            pop_aux();
    }
    case 106:
    {
        for (i = 0; i < 11; ++i)
            pop_aux();
    }
    case 107:
    {
    }
    case 108:
    {
        pop_aux();
    }
    case 109:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 110:
    {
    }
    case 111:
    {
        pop_aux();
    }
    case 112:
    {
        pop_aux();
    }
    case 113:
    {
        pop_aux();
    }
    case 114:
    {
        pop_aux();
    }
    case 115:
    {
        pop_aux();
    }
    case 116:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 117:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 118:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 119:
    {
    }
    case 120:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();
    }
    case 121:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();
    }
    case 122:
    {
    }
    case 123:
    {
        for (i = 0; i < 4; ++i)
            pop_aux();
    }
    case 124:
    {
    }
    case 125:
    {
    }
    case 126:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();
    }
    case 127:
    {
    }
    case 128:
    {
    }
    case 129:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 130:
    {
    }
    case 131:
    {
        pop_aux();
    }
    case 132:
    {
    }
    case 134:
    {
    }
    case 135:
    {
    }
    case 136:
    {
    }
    case 137:
    {
    }
    case 138:
    {
    }
    case 139:
    {
        for (i = 0; i < 9; ++i)
            pop_aux();
    }
    case 140:
    {
        pop_aux();
    }
    case 141:
    {
    }
    case 142:
    {
    }
    case 143:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 144:
    {
    }
    case 145:
    {
        for (i = 0; i < 4; ++i)
            pop_aux();
    }
    case 146:
    {
    }
    case 147:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();
    }
    case 148:
    {
    }
    case 149:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();
    }
    case 150:
    {
    }
    case 151:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 152:
    {
    }
    case 153:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();
    }
    case 154:
    {
    }
    case 155:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 156:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();
    }
    case 157:
    {
        pop_aux();
    }
    case 158:
    {
    }
    case 159:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();
    }
    case 160:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    case 161:
    {
        pop_aux();
    }
    case 162:
    {
        pop_aux();
    }
    case 163:
    {
    }
    case 164:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();
    }
    default:
    {
    }
    }
}
