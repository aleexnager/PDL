#include "header.h"
#include "lifo.h"
#include "lifo_aux.h"

void reglas_semanticas(int n_regla, int *despl, int *zona_decl)
{
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
        // B.tipo := if E.tipo = logico then S.tipo else tipo_error; Pop(5)
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
        /* B.tipo := if AnadirTipo(id.pos, T.tipo) then
                     tipo_ok
                     else tipo_error; Pop(11)
        */
    }
    case 106:
    {
        /* B.tipo := if E.tipo = logico then
                     C.tipo
                     else tipo_error; Pop(11)
        */
    }
    case 107:
    {
    }
    case 108:
    {
    }
    case 109:
    {
    }
    case 110:
    {
    }
    case 111:
    {
    }
    case 112:
    {
    }
    case 113:
    {
    }
    case 114:
    {
    }
    case 115:
    {
    }
    case 116:
    {
    }
    case 117:
    {
    }
    case 118:
    {
    }
    case 119:
    {
    }
    case 120:
    {
    }
    case 121:
    {
    }
    case 122:
    {
    }
    case 123:
    {
    }
    case 124:
    {
    }
    case 125:
    {
    }
    case 126:
    {
    }
    case 127:
    {
    }
    case 128:
    {
    }
    case 129:
    {
    }
    case 130:
    {
    }
    case 131:
    {
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
    }
    case 140:
    {
    }
    case 141:
    {
    }
    case 142:
    {
    }
    case 143:
    {
    }
    case 144:
    {
    }
    case 145:
    {
    }
    case 146:
    {
    }
    case 147:
    {
    }
    case 148:
    {
    }
    case 149:
    {
    }
    case 150:
    {
    }
    case 151:
    {
    }
    case 152:
    {
    }
    case 153:
    {
    }
    case 154:
    {
    }
    case 155:
    {
    }
    case 156:
    {
    }
    case 157:
    {
    }
    case 158:
    {
    }
    case 159:
    {
    }
    case 160:
    {
    }
    case 161:
    {
    }
    case 162:
    {
    }
    case 163:
    {
    }
    case 164:
    {
    }
    default:
    {
    }
    }
}
