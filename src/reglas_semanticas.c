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
            strcpy(get_aux_top()->next->next->next->next->next->data->lexema, "tipo_error");
            printf("Error1");
            gen_error_semantico(fp_error, 0, NULL);
            exit(1);
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
        strcpy(get_top()->data->lexema, "vacio");
        break;
    }
    case 107:
    {
        if (strcmp(get_aux_top()->next->next->next->next->next->next->data->lexema, "logico") == 0 && strcmp(get_aux_top()->next->next->next->next->next->next->next->next->data->lexema, "tipo_ok") == 0 && strcmp(get_aux_top()->next->next->next->next->data->lexema, "tipo_ok") == 0)
            strcpy(get_aux_top()->next->next->next->next->next->next->next->next->next->next->next->data->lexema, get_top()->next->data->lexema);

        for (i = 0; i < 11; ++i)
            pop_aux();

        break;
    }
    case 108:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 109:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 110:
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
    case 111:
    {
        strcpy(get_aux_top()->data->lexema, "tipo_ok");
        break;
    }
    case 112:
    {
        strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 113:
    {
        strcpy(get_aux_top()->next->data->lexema, "tipo_ok");
        pop_aux();
        break;
    }
    case 114:
    {
        strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 115:
    {
        strcpy(get_aux_top()->next->data->lexema, "logico");
        pop_aux();
        break;
    }
    case 116:
    {
        strcpy(get_aux_top()->next->data->lexema, "cadena");
        pop_aux();
        break;
    }
    case 117:
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
    case 118:
    {
        char *tipo = (char *)malloc(32 * sizeof(char));
        if ((tipo = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->data->lexema)) == NULL)
        {
            crear_entrada(id_tabla, get_aux_top()->next->data->lexema);
            asignar_tipo_entrada(id_tabla, get_aux_top()->next->data->lexema, "entero");
            crear_atributo_entero(id_tabla, get_aux_top()->next->data->lexema, "despl", *despl);
            *despl += 1;
            escribir_tabla(id_tabla, ts_file_2);
        }
        else if (strcmp(tipo, "cadena") == 0 || strcmp(tipo, "entero") == 0)
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        else if (strcmp(tipo, "logico") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            printf("Error2");
            gen_error_semantico(fp_error, 0, NULL);
            exit(1);
        }
        else
        {
        }

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 119:
    {
        if (existe_tabla(2) == 1)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            printf("Error3");
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
    case 120:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema); // los que no sean id.pos a lexema2
        break;
    }
    case 121:
    {
        strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->data->lexema);
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 122:
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
    case 123:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema2);

        break;
    }
    case 124:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->next->data->lexema);

        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 125:
    {
        get_top()->data->valor = 1;

        break;
    }
    case 126:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        get_top()->data->valor = get_aux_top()->data->valor;

        break;
    }
    case 127:
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
    case 128:
    {
        get_top()->data->valor = get_aux_top()->data->valor++;

        break;
    }
    case 129:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        get_top()->data->valor = get_aux_top()->data->valor;
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);

        break;
    }
    case 130:
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
    case 131:
    {
        strcpy(get_aux_top()->next->data->lexema, "tipo_ok");

        break;
    }
    case 132:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();

        break;
    }
    case 133:
    {
        strcpy(get_aux_top()->next->data->lexema, "tipo_ok");

        break;
    }
    case 134:
    {
        *zona_decl = TRUE;
        break;
    }
    case 135:
    {
        asignar_tipo_entrada(id_tabla, get_aux_top()->data->lexema, "funcion");
        escribir_tabla(id_tabla, ts_file_2);
        *id_tabla_aux = crear_tabla();
        *despl_aux = 0;
        break;
    }
    case 136:
    {
        crear_atributo_cadena(id_tabla, get_aux_top()->next->data->lexema, "TipoRetorno", get_aux_top()->data->lexema);
        escribir_tabla(id_tabla, ts_file_2);
        break;
    }
    case 137:
    {
        get_top()->data->valor = 1;
        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->data->lexema);
        crear_atributo_entero(id_tabla, get_top()->data->lexema2, "NumParams", 0);
        break;
    }
    case 138:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->next->next->next->data->lexema);

        break;
    }
    case 139:
    {
        destruir_tabla(*id_tabla_aux);
        *id_tabla_aux = -1;
        break;
    }
    case 140:
    {
        for (i = 0; i < 9; ++i)
            pop_aux();

        break;
    }
    case 141:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 142:
    {
        strcpy(get_aux_top()->next->data->lexema, "vacio");
        break;
    }
    case 143:
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
    case 144:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 145:
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
    case 146:
    {
        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 147:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 148:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);
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
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 151:
    {
        if (strcmp(get_aux_top()->data->lexema, "logico") == 0)
            strcpy(get_aux_top()->next->next->data->lexema, "logico");
        else
            strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->next->data->lexema);

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 152:
    {
        if (strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->next->data->lexema, "entero") == 0)
            strcpy(get_top()->data->lexema, "logico");
        else
            strcpy(get_top()->data->lexema, "tipo_error");

        break;
    }
    case 153:
    {
        strcpy(get_aux_top()->next->next->next->next->data->lexema, get_aux_top()->next->data->lexema);

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 154:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 155:
    {
        if (strcmp(get_aux_top()->data->lexema, "entero") == 0)
            strcpy(get_aux_top()->next->next->data->lexema, "entero");
        else
            strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->data->lexema);

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 156:
    {
        if (strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->next->data->lexema, "entero"))
            strcpy(get_top()->data->lexema, "entero");
        else
            strcpy(get_top()->data->lexema, "entero");

        break;
    }
    case 157:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->data->lexema);
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 158:
    {
        if (strcmp(get_aux_top()->data->lexema, "logico") == 0)
            strcpy(get_aux_top()->next->next->data->lexema, "logico");
        else
            strcpy(get_aux_top()->next->next->data->lexema, "tipo_error");

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 159:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 160:
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
    case 161:
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
    case 162:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->data->lexema);
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 163:
    {
        strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 164:
    {
        strcpy(get_aux_top()->next->data->lexema, "cadena");
        pop_aux();
        break;
    }
    case 165:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);
        break;
    }
    case 166:
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
