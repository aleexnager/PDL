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
        break;
    }
    case 101:
    {
        pop_aux();
        break;
    }
    case 102:
    {
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
        pop_aux();
        break;
    }
    case 112:
    {
        pop_aux();
        break;
    }
    case 113:
    {
        pop_aux();
        break;
    }
    case 114:
    {
        pop_aux();
        break;
    }
    case 115:
    {
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
        break;
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
        break;
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
        break;
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
        for (i = 0; i < 3; ++i)
            pop_aux();
        break;
    }
    case 161:
    {
        pop_aux();
        break;
    }
    case 162:
    {
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
