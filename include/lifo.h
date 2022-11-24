#ifndef _lifo_included_

struct lifo {
    int data;
    struct lifo *next;
};

void push(int data);
int pop();
int peek();
void print();

#endif
