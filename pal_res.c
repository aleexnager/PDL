#include <stdlib.h>
#include <string.h>
#include "header.h"

int es_pal_res(const char* lexema) {
    if (!strcmp(lexema, "boolean")) {
        return BOOLEAN;
    } else if (!strcmp(lexema, "for")) {
        return FOR;
    } else if (!strcmp(lexema, "function")) {
        return FUNCTION;
    } else if (!strcmp(lexema, "if")) {
        return IF;
    } else if (!strcmp(lexema, "input")) {
        return INPUT;
    } else if (!strcmp(lexema, "int")) {
        return INT;
    } else if (!strcmp(lexema, "let")) {
        return LET;
    } else if (!strcmp(lexema, "print")) {
        return PRINT;
    } else if (!strcmp(lexema, "return")) {
        return RETURN;
    } else if (!strcmp(lexema, "string")) {
        return STRING;
    } else {
        return -1;
    }
}
