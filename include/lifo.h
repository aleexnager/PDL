#ifndef _lifo_included_

struct lifo
{
    int data;
    struct lifo *next;
};

void push(int data);
int pop(void);
int peek(void);
void print(void);

#endif
