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

void ejecutar_regla_semantica(int id_tabla, int *id_tabla_aux, int n_regla, int *despl, int *despl_aux, int *zona_decl, int linea, FILE *fp_error)
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
        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->next->next->data->lexema2);
        break;
    }
    case 103:
    {
        if (strcmp(get_aux_top()->next->next->data->lexema, "logico") == 0)
            strcpy(get_aux_top()->next->next->next->next->next->data->lexema, get_aux_top()->data->lexema);
        else
        {
            strcpy(get_aux_top()->next->next->next->next->next->data->lexema, "tipo_error");
            gen_error_semantico(fp_error, 200, linea, "El fragmento de código encerrado entre los paréntesis de una sentencia \'if\' debe ser de tipo \'logico\'.");
            exit(1);
        }

        for (i = 0; i < 5; ++i)
            pop_aux();

        break;
    }
    case 104:
    {
        *zona_decl = TRUE;
        break;
    }
    case 105:
    {
        *zona_decl = FALSE;
        break;
    }
    case 106:
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
    case 107:
    {
        strcpy(get_top()->data->lexema, "vacio");
        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->next->next->next->next->next->next->next->data->lexema2);
        break;
    }
    case 108:
    {
        if (strcmp(get_aux_top()->next->next->next->next->next->next->data->lexema, "logico") == 0 && strcmp(get_aux_top()->next->next->next->next->next->next->next->next->data->lexema, "tipo_ok") == 0 && strcmp(get_aux_top()->next->next->next->next->data->lexema, "tipo_ok") == 0)
            strcpy(get_aux_top()->next->next->next->next->next->next->next->next->next->next->next->data->lexema, get_top()->next->data->lexema);

        for (i = 0; i < 11; ++i)
            pop_aux();

        break;
    }
    case 109:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema2);
        break;
    }
    case 110:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 111:
    {

        if ((tipo = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->next->data->lexema)) == NULL)
        {
            if ((tipo = consultar_tipo_entrada(id_tabla, get_aux_top()->next->next->data->lexema)) == NULL)
            {
                strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
                char explicacion[256];
                sprintf(explicacion, "La variable \'%s\' no está definida en el programa.", get_aux_top()->next->next->data->lexema);
                gen_error_semantico(fp_error, 211, linea, explicacion);
                exit(1);
            }
            else if (strcmp(tipo, "entero") == 0 && strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->data->lexema, "entero") == 0)
            {
                strcpy(get_aux_top()->next->next->next->data->lexema, "entero");
            }
            else
            {
                strcpy(get_aux_top()->next->next->next->data->lexema, tipo);
            }
        }
        else if (strcmp(tipo, "entero") == 0 && strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->data->lexema, "entero") == 0)
            strcpy(get_aux_top()->next->next->next->data->lexema, "entero");
        else if (consultar_tipo_entrada(id_tabla, get_aux_top()->next->next->data->lexema))
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "entero");
        }
        else
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
        }
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 112:
    {
        strcpy(get_aux_top()->data->lexema, "tipo_ok");
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
        strcpy(get_aux_top()->next->data->lexema, "tipo_ok");
        pop_aux();
        break;
    }
    case 115:
    {
        strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 116:
    {
        strcpy(get_aux_top()->next->data->lexema, "logico");
        pop_aux();
        break;
    }
    case 117:
    {
        strcpy(get_aux_top()->next->data->lexema, "cadena");
        pop_aux();
        break;
    }
    case 118:
    {
        if (strcmp(get_aux_top()->next->data->lexema, "entero") == 0 || strcmp(get_aux_top()->next->data->lexema, "cadena") == 0)
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        else
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            gen_error_semantico(fp_error, 204, linea, "Solo se permite la utilización de la sentencia \'print\' con datos o variables de tipo \'entero\' o \'cadena\'.");
            exit(1);
        }
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 119:
    {
        char *tipo = (char *)malloc(32 * sizeof(char));
        if ((tipo = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->data->lexema)) == NULL)
        {
            if ((tipo = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->data->lexema)) == NULL)
            {
                crear_entrada(id_tabla, get_aux_top()->next->data->lexema);
                asignar_tipo_entrada(id_tabla, get_aux_top()->next->data->lexema, "entero");
                crear_atributo_entero(id_tabla, get_aux_top()->next->data->lexema, "despl", *despl);
                *despl += 1;
                escribir_tabla(id_tabla, ts_file_2);
            }
            else
            {
                if (strcmp(tipo, "cadena") == 0 || strcmp(tipo, "entero") == 0)
                    strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
                else if (strcmp(tipo, "logico") == 0)
                {
                    strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
                    char explicacion[256];
                    sprintf(explicacion, "La variable \'%s\' declarada como tipo \'logico\' no permite aceptar input del usuario.", get_aux_top()->next->data->lexema);
                    gen_error_semantico(fp_error, 201, linea, explicacion);
                    exit(1);
                }
            }
        }
        else if (strcmp(tipo, "cadena") == 0 || strcmp(tipo, "entero") == 0)
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        else if (strcmp(tipo, "logico") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            char explicacion[256];
            sprintf(explicacion, "La variable \'%s\' declarada como tipo \'logico\' no permite aceptar input del usuario.", get_aux_top()->next->data->lexema);
            gen_error_semantico(fp_error, 201, linea, explicacion);
            exit(1);
        }
        else
        {
        }

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 120:
    {
        if (existe_tabla(2) == 1)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            gen_error_semantico(fp_error, 202, linea, "La sentencia \'return\' debe de estar contenida en una función.");
            exit(1);
        }
        else if (strcmp(get_aux_top()->next->next->next->data->lexema2, "vacio") == 0 && strcmp(get_aux_top()->next->data->lexema, "vacio") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        }
        else if (strcmp(consultar_valor_atributo_cadena(id_tabla, get_aux_top()->next->next->next->data->lexema2, "TipoRetorno"), "vacio") != 0 && strcmp(get_aux_top()->next->data->lexema, "vacio") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            char explicacion[512];
            sprintf(explicacion, "El dato devuelto del tipo \'%s\' no se corresponde con el tipo de retorno de la función \'%s\'. Debe de devolver un dato del tipo \'%s\'.",
                    get_aux_top()->next->data->lexema,
                    consultar_valor_atributo_cadena(id_tabla, get_aux_top()->next->next->next->data->lexema2, "TipoRetorno"),
                    get_aux_top()->next->next->next->data->lexema2);
            gen_error_semantico(fp_error, 206, linea, explicacion);
            exit(1);
        }
        else if (strcmp(consultar_valor_atributo_cadena(id_tabla, get_aux_top()->next->next->next->data->lexema2, "TipoRetorno"), "vacio") == 0 && strcmp(get_aux_top()->next->data->lexema, "vacio") != 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            char explicacion[512];
            sprintf(explicacion, "El dato devuelto del tipo \'%s\' no se corresponde con el tipo de retorno de la función \'%s\'. Debe de devolver un dato del tipo \'%s\'.",
                    get_aux_top()->next->data->lexema,
                    consultar_valor_atributo_cadena(id_tabla, get_aux_top()->next->next->next->data->lexema2, "TipoRetorno"),
                    get_aux_top()->next->next->next->data->lexema2);
            gen_error_semantico(fp_error, 206, linea, explicacion);
            exit(1);
        }
        else if (strcmp(get_aux_top()->next->data->lexema, consultar_valor_atributo_cadena(id_tabla, get_aux_top()->next->next->next->data->lexema2, "TipoRetorno")) != 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            char explicacion[512];
            sprintf(explicacion, "El dato devuelto del tipo \'%s\' no se corresponde con el tipo de retorno de la función \'%s\'. Debe de devolver un dato del tipo \'%s\'.",
                    get_aux_top()->next->data->lexema,
                    get_aux_top()->next->next->next->data->lexema2,
                    consultar_valor_atributo_cadena(id_tabla, get_aux_top()->next->next->next->data->lexema2, "TipoRetorno"));
            gen_error_semantico(fp_error, 205, linea, explicacion);
            exit(1);
        }
        else
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        }

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 121:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema);
        break;
    }
    case 122:
    {
        strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->data->lexema);
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 123:
    {
        if (strcmp(get_aux_top()->next->next->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->data->lexema, "entero") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        }
        else if (strcmp(consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->next->next->data->lexema2), get_aux_top()->next->data->lexema) == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        }
        else if (strcmp(consultar_tipo_entrada(id_tabla, get_aux_top()->next->next->next->data->lexema2), get_aux_top()->next->data->lexema) == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        }
        else
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            char explicacion[256];
            sprintf(explicacion, "Ambos lados del operador de asignación deben de ser del mismo tipo.");
            gen_error_semantico(fp_error, 208, linea, explicacion);
            exit(1);
        }
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 124:
    {
        if (consultar_tipo_entrada(id_tabla_actual, get_aux_top()->next->data->lexema2) == NULL)
        {
            strcpy(get_aux_top()->next->data->lexema, "tipo_error");
            char explicacion[256];
            sprintf(explicacion, "La función con identificador \'%s\' no está declarada.",
                    get_aux_top()->next->data->lexema2);
            gen_error_semantico(fp_error, 206, linea, explicacion);
            exit(1);
        }
        else if (consultar_tipo_entrada(id_tabla, get_aux_top()->next->data->lexema2) == NULL)
        {
            strcpy(get_aux_top()->next->data->lexema, "tipo_error");
            char explicacion[256];
            sprintf(explicacion, "La función con identificador \'%s\' no está declarada.",
                    get_aux_top()->next->data->lexema2);
            gen_error_semantico(fp_error, 206, linea, explicacion);
            exit(1);
        }
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        strcpy(get_top()->data->lexema, "tipo_ok");
        break;
    }
    case 125:
    {
        strcpy(get_aux_top()->next->next->next->next->data->lexema, get_aux_top()->next->next->data->lexema);

        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 126:
    {
        get_top()->data->valor = 1;
        break;
    }
    case 127:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);
        get_top()->data->valor = get_aux_top()->data->valor;
        break;
    }
    case 128:
    {
        char consulta_1[64];
        sprintf(consulta_1, "TipoParam%d", get_aux_top()->next->data->valor);
        if (strcmp(get_aux_top()->next->data->lexema, consultar_valor_atributo_cadena(id_tabla_actual, get_aux_top()->next->next->data->lexema2, consulta_1)) == 0 && strcmp(get_aux_top()->data->lexema, "tipo_ok") == 0)
        {
            strcpy(get_aux_top()->next->next->data->lexema, "tipo_ok");
        }
        else
        {
            strcpy(get_aux_top()->next->next->data->lexema, "tipo_error");
            char explicacion[256];
            sprintf(explicacion, "El parámtero número %d de la llamada a la función \'%s\' debe ser de tipo \'%s\'.",
                    get_aux_top()->next->data->valor,
                    get_aux_top()->next->next->data->lexema2,
                    consultar_valor_atributo_cadena(id_tabla_actual, get_aux_top()->next->next->data->lexema2, consulta_1));
            gen_error_semantico(fp_error, 203, linea, explicacion);
            exit(1);
        }

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 129:
    {
        get_top()->data->valor = get_aux_top()->next->data->valor + 1;
        break;
    }
    case 130:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->data->lexema2);
        get_top()->data->valor = get_aux_top()->data->valor;
        strcpy(get_top()->data->lexema, get_aux_top()->next->next->data->lexema);

        break;
    }
    case 131:
    {
        char consulta_2[64];
        sprintf(consulta_2, "TipoParam%d", get_aux_top()->next->data->valor);
        if (strcmp(get_aux_top()->next->data->lexema, consultar_valor_atributo_cadena(id_tabla_actual, get_aux_top()->next->next->next->data->lexema2, consulta_2)) == 0 && strcmp(get_aux_top()->data->lexema, "tipo_ok") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_ok");
        }
        else
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, "tipo_error");
            char explicacion[256];
            sprintf(explicacion, "El parámtero número %d de la llamada a la función \'%s\' debe ser de tipo \'%s\'.",
                    get_aux_top()->next->data->valor,
                    get_aux_top()->next->next->next->data->lexema2,
                    consultar_valor_atributo_cadena(id_tabla_actual, get_aux_top()->next->next->next->data->lexema2, consulta_2));
            gen_error_semantico(fp_error, 203, linea, explicacion);
            exit(1);
        }

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 132:
    {
        strcpy(get_aux_top()->data->lexema, "tipo_ok");
        break;
    }
    case 133:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();

        break;
    }
    case 134:
    {
        strcpy(get_aux_top()->data->lexema, "vacio");
        break;
    }
    case 135:
    {
        *zona_decl = TRUE;
        break;
    }
    case 136:
    {
        asignar_tipo_entrada(id_tabla, get_aux_top()->data->lexema, "funcion");
        escribir_tabla(id_tabla, ts_file_2);
        *id_tabla_aux = crear_tabla();
        *despl_aux = 0;
        break;
    }
    case 137:
    {
        crear_atributo_cadena(id_tabla, get_aux_top()->next->data->lexema, "TipoRetorno", get_aux_top()->data->lexema);
        escribir_tabla(id_tabla, ts_file_2);
        break;
    }
    case 138:
    {
        get_top()->data->valor = 1;
        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->data->lexema);
        crear_atributo_entero(id_tabla, get_aux_top()->next->next->data->lexema, "NumParams", 0);
        escribir_tabla(id_tabla, ts_file_2);
        break;
    }
    case 139:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->next->next->next->data->lexema);
        strcpy(get_top()->data->lexema2, get_aux_top()->next->next->next->next->next->data->lexema);
        break;
    }
    case 140:
    {
        destruir_tabla(*id_tabla_aux);
        *id_tabla_aux = -1;
        break;
    }
    case 141:
    {
        for (i = 0; i < 9; ++i)
            pop_aux();

        break;
    }
    case 142:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 143:
    {
        strcpy(get_aux_top()->data->lexema, "vacio");
        break;
    }
    case 144:
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
    case 145:
    {
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 146:
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
    case 147:
    {
        for (i = 0; i < 4; ++i)
            pop_aux();

        break;
    }
    case 148:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema2);
        break;
    }
    case 149:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        break;
    }
    case 150:
    {
        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 151:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 152:
    {
        if (strcmp(get_aux_top()->data->lexema, "logico") == 0)
        {
            strcpy(get_aux_top()->next->next->data->lexema, "logico");
        }
        else
            strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->next->data->lexema);

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 153:
    {
        if (strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->next->data->lexema, "entero") == 0)
        {
            strcpy(get_top()->data->lexema, "logico");
        }
        else
        {
            strcpy(get_top()->data->lexema, "tipo_error");
            char explicacion[256];
            sprintf(explicacion, "Ambos operadores del operador \'!=\' deben de ser de tipo \'logico\'.");
            gen_error_semantico(fp_error, 207, linea, explicacion);
            exit(1);
        }

        break;
    }
    case 154:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->data->lexema);

        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 155:
    {
        strcpy(get_top()->data->lexema, get_aux_top()->data->lexema);
        break;
    }
    case 156:
    {
        if (get_aux_top()->data->lexema == NULL)
        {
            strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->next->data->lexema);
        }
        else if (strcmp(get_aux_top()->data->lexema, get_aux_top()->next->data->lexema) == 0)
        {
            strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->data->lexema);
        }
        else
        {
            strcpy(get_aux_top()->next->next->data->lexema, "tipo_error");
            gen_error_semantico(fp_error, 209, linea, "Los miembros de la expresión no tienen el mismo tipo.");
            exit(-1);
        }

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 157:
    {
        if (strcmp(get_aux_top()->data->lexema, "entero") == 0 && strcmp(get_aux_top()->next->next->data->lexema, "entero") == 0)
            strcpy(get_top()->data->lexema, "entero");
        else
        {
            strcpy(get_top()->data->lexema, "tipo_error");
            gen_error_semantico(fp_error, 210, linea, "Los operandos del operador \'%\' han de ser de tipo \'entero\'.");
            exit(1);
        }

        break;
    }
    case 158:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->data->lexema);
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 159:
    {
        if (strcmp(get_aux_top()->data->lexema, "logico") == 0)
            strcpy(get_aux_top()->next->next->data->lexema, "logico");
        else
            strcpy(get_aux_top()->next->next->data->lexema, "tipo_error");

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 160:
    {
        strcpy(get_aux_top()->next->data->lexema, get_aux_top()->data->lexema);
        pop_aux();
        break;
    }
    case 161:
    {
        char *tipo_entrada;
        strcpy(get_top()->data->lexema2, get_aux_top()->data->lexema);
        if ((tipo_entrada = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->data->lexema)) == NULL)
        {
            if ((tipo_entrada = consultar_tipo_entrada(id_tabla, get_aux_top()->data->lexema)) == NULL)
                strcpy(get_top()->data->lexema, "entero");
            else
            {
                strcpy(get_top()->data->lexema, tipo_entrada);
            }
        }
        else
        {
            strcpy(get_top()->data->lexema, tipo_entrada);
        }

        break;
    }
    case 162:
    {
        char *tipo_entrada_2;
        if ((tipo_entrada_2 = consultar_tipo_entrada(id_tabla_actual, get_aux_top()->data->lexema2)) == NULL && consultar_tipo_entrada(id_tabla, get_aux_top()->data->lexema2) == NULL)
            strcpy(get_aux_top()->next->next->data->lexema, "entero");
        else
        {
            strcpy(get_aux_top()->next->next->data->lexema, get_aux_top()->data->lexema);
        }

        for (i = 0; i < 2; ++i)
            pop_aux();

        break;
    }
    case 163:
    {
        strcpy(get_aux_top()->next->next->next->data->lexema, get_aux_top()->next->data->lexema);
        for (i = 0; i < 3; ++i)
            pop_aux();

        break;
    }
    case 164:
    {
        strcpy(get_aux_top()->next->data->lexema, "entero");
        pop_aux();
        break;
    }
    case 165:
    {
        strcpy(get_aux_top()->next->data->lexema, "cadena");
        pop_aux();
        break;
    }
    case 166:
    {
        strcpy(get_top()->data->lexema2, get_aux_top()->next->data->lexema2);
        strcpy(get_top()->data->lexema, get_aux_top()->next->data->lexema);
        break;
    }
    case 167:
    {
        if (strcmp(get_aux_top()->next->data->lexema, "tipo_ok") == 0)
        {
            strcpy(get_aux_top()->next->next->next->data->lexema, consultar_valor_atributo_cadena(id_tabla_actual, get_aux_top()->next->next->next->data->lexema2, "TipoRetorno"));
        }
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
