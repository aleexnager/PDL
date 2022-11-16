#ifndef _header_h_incluido_
#define _header_h_incluido_

#include <stdio.h>
// Definiciones para los tokens

#define ID 1
#define CTE_ENTERA 2
#define CADENA 3
#define OP_MODULO 4
#define OP_NEQ 5
#define OP_NEG 6
#define OP_MOD_ASIG 7
#define OP_ASIG 8
#define COMA 9
#define PUNTO_COMA 10
#define PARENT_IZQ 11
#define PARENT_DCH 12
#define LLAVE_IZQ 13
#define LLAVE_DCH 14
#define BOOLEAN 15
#define FOR 16
#define FUNCTION 17
#define IF 18
#define INPUT 19
#define INT 20
#define LET 21
#define PRINT 22
#define RETURN 23
#define STRING 24

// Definiciones para las acciones semánticas

#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define H 8
#define I 9
#define J 10
#define K 11
#define L 12
#define M 13
#define N 14
#define O 15
#define P 16
#define Q 17
#define R 18
#define S 19
#define T 20
#define U 21

#define TAM_TS 50

typedef struct token_lexema {
    int id;
    char* lexema;
} token_lexema_t;

typedef struct token_valor {
    int id;
    int valor;
} token_valor_t;

typedef struct item_ts {
    char* lexema;
    int tipo_var;
    int desp;
    int num_param;
    int tipo_dev;
    char* etiq;
} item_ts_t;

int esc1(char c);
int esc2(char c);
int esdel(char c);

int mt_afd_estado(int estado_actual, char c);
int mt_afd_accion(int estado_actual, char c);

FILE* gen_error(FILE* fp, int cod_error, int linea, char leido, char *buf_linea);
FILE* gen_error_int(FILE* fp, int linea, int c, char *buf_linea);
FILE* gen_error_string(FILE* fp, int linea, char *lexema, char *buf_linea);

int es_pal_res(const char* lexema);

int buscar_ts(const char* lexema, int top_ts, item_ts_t tabla_simb []);
int insertar_ts(int top_ts, const char* lexema, int tipo_var, int desp, item_ts_t tabla_simb []);
FILE* imprimir_ts(FILE* fp4, item_ts_t tabla_simb[], int pos_ts, int num_tabla);

int an_lex(const char *inputfile, int id_tabla);

#endif