#include <stdio.h>

typedef struct Stack {
    int top;
    int data[24];
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int data) {
    s->top++;
    s->data[s->top] = data;
}

void pop(Stack *s) {
    int data = s->data[s->top];
    s->top--;
}

void show(Stack s) {
    printf("\n");
    for (int i = 0; i != s.top + 1; i++) {
        printf("| %d ", s.data[i]);
    }
    printf("|\n");
}

void enkripsi(Stack *S, int array[]) {
    for (int i = 0; i < 10; i++) {
        if (array[i] == 1)
            push(S, array[i]);
        if (array[i] == 8)
            push(S, array[i]);
        if (array[i] == 5)
            pop(S);
    }
    show(*S);
}

int main(void) {
    Stack s;
    init(&s);

    int array[] = {3, 1, 2, 1, 4, 8, 9, 8, 5, 7};
    enkripsi(&s, array);

    return 0;
}
