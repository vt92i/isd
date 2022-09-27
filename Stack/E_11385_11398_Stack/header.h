#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 10
typedef int Element;

typedef struct {
    int top;
    Element isi[MAX_STACK];
} Stack;

void init_array(int arr[]);
void initStack(Stack *s);

void copy_ganjil_genap(Stack *ganjil, Stack *genap, int arr[]);
void kosongkan_semua_stack(Stack *ganjil, Stack *genap);

int isEmpty(Stack s);
int isFull(Stack s);
void push(Stack *s, Element val);
Element pop(Stack *s);
void show(Stack s);
void show2(Stack s);
