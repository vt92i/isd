#include "header.h"

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, info_type data) {
    s->top++;
    s->data[s->top] = data;
}

info_type pop(Stack *s) {
    info_type data;

    data = s->data[s->top];
    s->top--;

    return data;
}

void show(Stack s) {
    int i;

    printf("\n");
    for (i = 0; i != s.top + 1; i++) {
        printf("| %d ", s.data[i]);
    }
    printf("|\n");
}

int is_empty(Stack s) {
    return s.top == -1;
}

int is_full(Stack s) {
    return s.top == MAX_STACK - 1;
}
