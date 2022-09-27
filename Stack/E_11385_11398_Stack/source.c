#include "header.h"

void init_array(int arr[]) {
	int i;
	for(i = 0; i < 10; i++) {
		arr[i] = i+1;
	}
}

void initStack(Stack *s) { 
	s->top = -1; 
}

void copy_ganjil_genap(Stack *ganjil, Stack *genap, int arr[]) {
	int i;
	for(i = 0; i < 10; i++) {
		if(arr[i] % 2 == 0)
		push(genap, arr[i]);
		else
		push(ganjil, arr[i]);
			
	}
}


int isFull(Stack s) { return s.top == MAX_STACK - 1; }

int isEmpty(Stack s) { return s.top == -1; }

void push(Stack *s, Element val) {
    if (isFull(*s))
        printf("Stack penuh .....");
    else {
        s->top++;
        s->isi[s->top] = val;
    }
}

Element pop(Stack *s) {
    Element temp = 0;

    if (isEmpty(*s))
        printf("Stack kosong .....");
    else {
        temp = s->isi[s->top];
        s->top--;
    }
    return temp;
}

void show(Stack s) {
        while (s.top != -1) {
            printf("\n %d", s.isi[s.top]);
            s.top--;
        }
}
