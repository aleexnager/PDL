#include "lifo_aux.h"
#include <stdlib.h>
#include <stdio.h>

struct lifo_aux *top_aux = NULL;
int aux_stack_size = 0;

void push_aux(token_t *data)
{
    struct lifo_aux *new = (struct lifo_aux *)malloc(sizeof(struct lifo_aux));
    new->data = data;
    new->next = top_aux;
    if (top_aux == NULL)
        new->next = NULL;
    else
        new->next = top_aux;

    ++aux_stack_size;
    top_aux = new;
}

token_t *pop_aux(void)
{
    if (top_aux == NULL)
        return NULL;

    struct lifo_aux *item = top_aux;
    token_t *data = top_aux->data;
    top_aux = top_aux->next;
    free(item);
    --aux_stack_size;
    return data;
}

token_t *peek_aux(void)
{
    return top_aux->data;
}

void print_aux(void)
{
    struct lifo_aux *cur;
    cur = top_aux;
    printf("Stack:\n");
    while (cur != NULL)
    {
        printf("%d\n-\n", cur->data->id);
        cur = cur->next;
    }
    printf("\n");
}

int size_aux(void)
{
    return aux_stack_size;
}
