#include "lifo.h"
#include <stdlib.h>
#include <stdio.h>

struct lifo *top = NULL;

void push(int data)
{
    struct lifo *new = (struct lifo *) malloc(sizeof(struct lifo));
    new->data = data;
    new->next = top;
    if (top == NULL)
        new->next = NULL;
    else
        new->next = top;
    
    top = new;
}

int pop()
{
    if (top == NULL)
        exit(-1);
    
    struct lifo *item = top;
    int data = top->data;
    top = top->next;
    free(item);
    return data;
}

int peek()
{
    return top->data;
}

void print()
{
    struct lifo *cur;
    cur = top;
    printf("Stack:\n");
    while (cur != NULL)
    {
        printf("%d\n-\n", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
