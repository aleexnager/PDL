#ifndef _lifo_aux_included_

struct lifo_aux
{
    int data;
    struct lifo_aux *next;
};

void push2(int data);
int pop2(void);
int peek2(void);
void print2(void);

#endif
