#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 10

typedef char string[64];
typedef int info_type;

typedef struct Stack {
    int top;
    info_type data[MAX_STACK];
} Stack;

void init(Stack *s);
void push(Stack *s, info_type data);
info_type pop(Stack *s);
void show(Stack s);

int is_empty(Stack s);
int is_full(Stack s);
