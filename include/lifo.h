#ifndef _lifo_included_

#include "header.h"

struct lifo
{
    token_t *data;
    struct lifo *next;
};

void push(token_t *data);
token_t *pop(void);
token_t *peek(void);
struct lifo *get_top(void);
void print(void);
int size(void);

#endif
