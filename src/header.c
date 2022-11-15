#include <ctype.h>
#include "header.h"

int esc1(char c) {
    if (isascii(c) && c != '\n') return 1;
    return 0;
}

int esc2(char c) {
    if (isascii(c) && c != '\'') return 1;
    return 0;
}

int esdel(char c) {
    if (isspace(c) && c != '\n') return 1;
    return 0;
}
