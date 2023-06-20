#ifndef _header_h_incluido_
#define _header_h_incluido_

#include <stdio.h>

#define TRUE 1
#define FALSE 0

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

//* Definiciones para los símbolos no
//* terminales de la gramática de contexto
//* libre.

#define _P_PRIMA 25
#define _P 26
#define _B 27
#define _T 28
#define _S 29
#define _W 30
#define _L 31
#define _Q 32
#define _X 33
#define _F 34
#define _H 35
#define _A 36
#define _K 37
#define _C 38
#define _E 39
#define _Y 40
#define _R 41
#define _Z 42
#define _U 43
#define _V 44
#define _J 45
#define _N 46
#define _M 47
#define _FIN_CADENA 48

typedef struct token
{
    int id;
    int valor;
    char *lexema;
    char *lexema2;
} token_t;

int esc1(char c);
int esc2(char c);
int esdel(char c);

int mt_afd_estado(int estado_actual, char c);
int mt_afd_accion(int estado_actual, char c);

FILE *gen_error(FILE *fp, int cod_error, int linea, char leido, char *buf_linea);
FILE *gen_error_int(FILE *fp, int linea, int c, char *buf_linea);
FILE *gen_error_string(FILE *fp, int linea, char *lexema, char *buf_linea);
FILE *gen_error_sintactico(FILE *fp, int linea, token_t *token);
FILE *gen_error_semantico(FILE *fp, int linea, token_t *token);

int es_pal_res(const char *lexema);
int es_terminal(int simb);
int es_regla_semantica(int n_regla);

FILE *an_lex(FILE *inputfile, int id_tabla, token_t *token, int *linea, char *buf);
int an_st(FILE *input_file, int id_table);

int *tabla_LL1(int s, int token, int *regla);
void ejecutar_regla_semantica(int id_tabla, int *id_tabla_aux, int n_regla, int *despl, int *despl_aux, int *zona_decl, FILE *fp_error);

#endif
