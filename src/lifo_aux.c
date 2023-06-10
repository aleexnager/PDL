#include "lifo_aux.h"
#include <stdlib.h>
#include <stdio.h>

struct lifo_aux *top2 = NULL;

void push2(int data)
{
    struct lifo_aux *new = (struct lifo_aux *) malloc(sizeof(struct lifo_aux));
    new->data = data;
    new->next = top2;
    if (top2 == NULL)
        new->next = NULL;
    else
        new->next = top2;
    
    top2 = new;
}

int pop2()
{
    if (top2 == NULL)
        exit(-1);
    
    struct lifo_aux *item = top2;
    int data = top2->data;
    top2 = top2->next;
    free(item);
    return data;
}

int peek2()
{
    return top2->data;
}

void print2()
{
    struct lifo_aux *cur;
    cur = top2;
    printf("Stack:\n");
    while (cur != NULL)
    {
        printf("%d\n-\n", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
