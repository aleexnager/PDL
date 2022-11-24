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

#define VALOR_T 1
#define CADENA_T 0

//* Definiciones para los símbolos no
//* terminales de la gramática de contexto
//* libre.

#define _P 0
#define _B 1
#define _T 2
#define _S 3
#define _W 4
#define _L 5
#define _Q 6
#define _X 7
#define _F 8
#define _H 9
#define _A 10
#define _K 11
#define _C 12
#define _E 13
#define _Y 14
#define _R 15
#define _Z 16
#define _U 17
#define _V 18
#define _J 19
#define _$ 20

typedef struct token {
    int type; // VALOR_T || CADENA_T
    int id;
    int valor;
    char *lexema;
} token_t;

int esc1(char c);
int esc2(char c);
int esdel(char c);

int mt_afd_estado(int estado_actual, char c);
int mt_afd_accion(int estado_actual, char c);

FILE *gen_error(FILE *fp, int cod_error, int linea, char leido, char *buf_linea);
FILE *gen_error_int(FILE *fp, int linea, int c, char *buf_linea);
FILE *gen_error_string(FILE *fp, int linea, char *lexema, char *buf_linea);

int es_pal_res(const char* lexema);

FILE *an_lex(FILE *inputfile, int id_tabla, token_t *token, int *linea, char *buf, int *index);

int an_st(char *cadena);

int *tabla_LL1(int s, int token);

#endif
