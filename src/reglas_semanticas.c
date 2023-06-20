#include "header.h"
#include "lifo.h"
#include "lifo_aux.h"
#include "ts2006.h"
#include <string.h>

char *ts_file_2 = "./data/output/ts.txt";
char *ts_file_aux_2 = "./data/output/ts_aux.txt";

int es_regla_semantica(int n_regla)
{
    if (n_regla >= 100)
        return TRUE;
    else
        return FALSE;
}

void ejecutar_regla_semantica(int id_tabla, int *id_tabla_aux, int n_regla, int *despl, int *despl_aux, int *zona_decl, FILE *fp_error)
{
    int id_tabla_actual;
    int i;

    if (*id_tabla_aux > -1)
        id_tabla_actual = *id_tabla_aux;
    else
        id_tabla_actual = id_tabla;

    char *tipo = (char *)malloc(64 * sizeof(char));
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
        if (strcmp(get_aux_top()->next->next->data->lexema, "logico") == 0)
            strcpy(get_aux_top()->next->next->next->next->next->data->lexema, get_aux_top()->data->lexema);
        else
        {
            gen_error_semantico(fp_error, 0, NULL);
            exit(1);
            strcpy(get_aux_top()->next->next->next->next->next->data->lexema, "tipo_error");
        }

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
        tipo = get_aux_top()->next->data->lexema;
        if (asignar_tipo_entrada(id_tabla_actual, get_aux_top()->next->next->data->lexema, tipo) == 0)
        {
            if (*id_tabla_aux > -1)
            {
                crear_atributo_entero(id_tabla_actual, get_aux_top()->next->next->data->lexema, "despl", *despl_aux);
            }
            else
            {
                crear_atributo_entero(id_tabla_actual, get_aux_top()->next->next->data->lexema, "despl", *despl);
            }
            if (strcmp(tipo, "cadena") == 0)
            {
                if (*id_tabla_aux > -1)
                {
                    escribir_tabla(id_tabla_actual, ts_file_aux_2);
                    *despl_aux += 64;
                }
                else
                {
                    escribir_tabla(id_tabla_actual, ts_file_2);
                    *despl += 64;
                }
            }
            else
            {
                if (*id_tabla_aux > -1)
                {
                    escribir_tabla(id_tabla_actual, ts_file_aux_2);
                    *despl_aux += 1;
                }
                else
                {
                    escribir_tabla(id_tabla_actual, ts_file_2);
                    *despl += 1;
                }
            }

            strcpy(get_aux_top()->next->next->next->next->data->lexema, "tipo_ok");
        }
        else
        {
            strcpy(get_aux_top()->next->next->next->next->data->lexema, "tipo_error");
        }

        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 106:
    {
        if (strcmp(get_top()->next->next->next->next->next->next->data->lexema, "logico") == 0 && strcmp(get_top()->next->next->next->next->next->next->next->next->data->lexema, "entero") == 0 && strcmp(get_top()->next->next->next->next->data->lexema, "entero") == 0)
            strcpy(get_aux_top()->next->next->next->next->next->next->next->next->next->next->next->data->lexema, get_top()->next->data->lexema);

        for (i = 0; i < 11; ++i)
            pop_aux();

        break;
    }
    case 107:
    {
        strcpy(get_top()->data->lexema, /*get_aux_top()->data->lexema*/ "vacio");
        break;
    }
    case 108:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 109:
    {

        tipo = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->next->data->lexema);
        if (strcmp(tipo, "entero") == 0 && strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->data->lexema, "entero") == 0)
            strcpy(get_aux_top()->next->next->next->data->lexema, "entero");
        else
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 110:
    {
        strcpy(get_aux_top()->next->data->lexema, "tipo_ok"); // ns si lambda esta en la pila
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
        strcpy(get_aux_top()->next->data->lexema, "entero");
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
        if (strcmp(get_aux_top()->next->data->lexema, "entero") == 0 || strcmp(get_aux_top()->next->next->data->lexema, "cadena") == 0)
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        else
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
        }
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 117:
    {
        if (strcmp(consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->data->lexema), "cadena") == 0 || strcmp(consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->data->lexema), "entero") == 0)
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        else if (strcmp(consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->data->lexema), "logico") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            gen_error_semantico(fp_error, 0, NULL);
            exit(1);
        }
        else
        {
            asignar_tipo_entrada(id_tabla_actual, get_aux_top()->next->data->lexema, "entero");
        }

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 118:
    {
        if (existe_tabla(2) == 1)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            gen_error_semantico(fp_error, 0, NULL);
            exit(1);
        }
        else if (strcmp(get_aux_top()->next->data->lexema, "tipo_error") != 0)
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
    case 119:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema); // los que no sean id.pos a lexema2
        break;
    }
    case 120:
    {
        strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->data->lexema);
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 121:
    {
        if (strcmp(get_aux_top()->next->next->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->data->lexema, "entero") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        }
        else if (strcmp(consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->next->next->data->lexema2), get_aux_top()->next->data->lexema) == 0)
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
    case 122:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema2);

        break;
    }
    case 123:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->next->data->lexema);

        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 124:
    {
        get_top()->data->valor = 1;

        break;
    }
    case 125:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        get_top()->data->valor = get_aux_top()->data->valor;

        break;
    }
    case 126:
    {
        char consulta[64];
        sprintf(consulta, "TipoParam%d", get_aux_top()->next->data->valor);
        // TODO: je ne sais pas
        if (strcmp(get_aux_top()->next->data->lexema, consultar_valor_atributo_cadena(id_tabla_actual, get_aux_top()->next->next->data->lexema2, consulta)) == 0 && strcmp(get_aux_top()->data->lexema, "tipo_ok") == 0)
        {
            strcpy(get_aux_top()->next->data->lexema, "tipo_ok");
        }
        else
        {
            strcpy(get_aux_top()->next->data->lexema, "tipo_error");
            // TODO: error
        }

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 127:
    {
        get_top()->data->valor = get_aux_top()->data->valor++;

        break;
    }
    case 128:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        get_top()->data->valor = get_aux_top()->data->valor;
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);

        break;
    }
    case 129:
    {
        char consulta[64];
        sprintf(consulta, "TipoParam%d", get_aux_top()->next->data->valor);
        if (strcmp(get_aux_top()->next->data->lexema, consultar_valor_atributo_cadena(id_tabla_actual, get_aux_top()->next->next->data->lexema2, consulta)) == 0 && strcmp(get_aux_top()->data->lexema, "tipo_ok") == 0)
        {
            strcpy(get_aux_top()->next->next->data->lexema, "tipo_ok");
        }
        else
        {
            strcpy(get_aux_top()->next->next->data->lexema, "tipo_error");
        }

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 130:
    {
        strcpy(get_aux_top()->next->data->lexema, "tipo_ok");

        break;
    }
    case 131:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();

        break;
    }
    case 132:
    {
        strcpy(get_aux_top()->next->data->lexema, "tipo_ok");

        break;
    }
    case 133:
    {
        *zona_decl = TRUE;
        break;
    }
    case 134:
    {
        asignar_tipo_entrada(id_tabla, get_aux_top()->data->lexema, "funcion");
        escribir_tabla(id_tabla, ts_file_2);
        *id_tabla_aux = crear_tabla();
        *despl_aux = 0;
        break;
    }
    case 135:
    {
        crear_atributo_cadena(id_tabla, get_aux_top()->next->data->lexema, "TipoRetorno", get_aux_top()->data->lexema);
        escribir_tabla(id_tabla, ts_file_2);
        break;
    }
    case 136:
    {
        get_top()->data->valor = 1;
        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->data->lexema);
        crear_atributo_entero(id_tabla, get_top()->data->lexema2, "NumParams", 0);
        break;
    }
    case 137:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->next->next->next->data->lexema);

        break;
    }
    case 138:
    {
        destruir_tabla(*id_tabla_aux);
        *id_tabla_aux = -1;
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
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 141:
    {
        strcpy(get_aux_top()->next->data->lexema, "vacio");
        break;
    }
    case 142:
    {
        char *nombre = malloc(32);
        sprintf(nombre, "TipoParam%d", get_aux_top()->next->next->data->valor);
        asignar_tipo_entrada(*id_tabla_aux, get_aux_top()->data->lexema, get_aux_top()->next->data->lexema);
        crear_atributo_entero(*id_tabla_aux, get_aux_top()->data->lexema, "despl", *despl_aux);
        crear_atributo_cadena(id_tabla, get_aux_top()->next->next->data->lexema2, nombre, get_aux_top()->next->data->lexema);
        asignar_valor_atributo_entero(id_tabla, get_aux_top()->next->next->data->lexema2, "NumParams", get_aux_top()->next->next->data->valor);
        escribir_tabla(id_tabla, ts_file_2);
        escribir_tabla(*id_tabla_aux, ts_file_aux_2);

        if (strcmp(get_aux_top()->next->data->lexema, "cadena") == 0)
            *despl_aux += 64;
        else
            *despl_aux += 1;

        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->data->lexema2);
        get_top()->data->valor = get_aux_top()->next->next->data->valor + 1;

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
        char *nombre = malloc(32);
        sprintf(nombre, "TipoParam%d", get_aux_top()->next->next->next->data->valor);
        asignar_tipo_entrada(*id_tabla_aux, get_aux_top()->data->lexema, get_aux_top()->next->data->lexema);
        crear_atributo_entero(*id_tabla_aux, get_aux_top()->data->lexema, "despl", *despl_aux);
        crear_atributo_cadena(id_tabla, get_aux_top()->next->next->next->data->lexema2, nombre, get_aux_top()->next->data->lexema);
        asignar_valor_atributo_entero(id_tabla, get_aux_top()->next->next->next->data->lexema2, "NumParams", get_aux_top()->next->next->next->data->valor);
        escribir_tabla(id_tabla, ts_file_2);
        escribir_tabla(*id_tabla_aux, ts_file_aux_2);

        if (strcmp(get_aux_top()->next->data->lexema, "cadena") == 0)
            *despl_aux += 64;
        else
            *despl_aux += 1;

        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->next->data->lexema2);
        get_top()->data->valor = get_aux_top()->next->next->next->data->valor + 1;
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
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 147:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);
        break;
    }
    case 148:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 149:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 150:
    {
        if (strcmp(get_aux_top()->data->lexema, "logico") == 0)
            strcpy(get_aux_top()->next->next->data->lexema, "logico");
        else
            strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->next->data->lexema);

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 151:
    {
        if (strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->next->data->lexema, "entero") == 0)
            strcpy(get_top()->data->lexema, "logico");
        else
            strcpy(get_top()->data->lexema, "tipo_error");

        break;
    }
    case 152:
    {
        strcpy(get_aux_top()->next->next->next->next->data->lexema, get_aux_top()->next->data->lexema);

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 153:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 154:
    {
        if (strcmp(get_aux_top()->data->lexema, "entero") == 0)
            strcpy(get_aux_top()->next->next->data->lexema, "entero");
        else
            strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->data->lexema);

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 155:
    {
        if (strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->next->data->lexema, "entero"))
            strcpy(get_top()->data->lexema, "entero");
        else
            strcpy(get_top()->data->lexema, "entero");

        break;
    }
    case 156:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->data->lexema);
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 157:
    {
        if (strcmp(get_aux_top()->data->lexema, "logico") == 0)
            strcpy(get_aux_top()->next->next->data->lexema, "logico");
        else
            strcpy(get_aux_top()->next->next->data->lexema, "tipo_error");

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 158:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 159:
    {
        char *tipo_entrada;
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema);
        if ((tipo_entrada = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->data->lexema)) == NULL)
            strcpy(get_top()->data->lexema, "entero");
        else
        {
            strcpy(get_top()->data->lexema, tipo_entrada);
        }

        break;
    }
    case 160:
    {
        char *tipo_entrada_2;
        if ((tipo_entrada_2 = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->data->lexema2)) == NULL)
            strcpy(get_aux_top()->next->next->data->lexema, "entero");
        else
            strcpy(get_aux_top()->next->next->data->lexema, tipo_entrada_2);

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 161:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->data->lexema);
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 162:
    {
        strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 163:
    {
        strcpy(get_aux_top()->next->data->lexema, "cadena");
        pop_aux();
        break;
    }
    case 164:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);
        break;
    }
    case 165:
    {
        if (strcmp(get_aux_top()->next->data->lexema, "tipo_ok") == 0)
            strcpy(get_aux_top()->next->next->next->data->lexema, consultar_valor_atributo_cadena(id_tabla_actual, get_aux_top()->next->next->next->data->lexema2, "TipoRetorno"));
        else
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");

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
