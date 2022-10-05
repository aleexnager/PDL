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

#define FILAS_M 10
#define COLUMNAS_M 13

typedef struct transicion {
    int estado_siguiente;
    int accion;
} transicion_t;

typedef struct token_valor {
    int id_token;
    int valor;
} token_valor_t;

typedef struct token_lexema {
    int id_token;
    char *lexema;
} token_lexema_t;
