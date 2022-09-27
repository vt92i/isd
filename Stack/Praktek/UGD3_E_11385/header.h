#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 10

typedef char string[64];

typedef struct Kamar {
	string nama_penghuni;
	string kode_kamar;
	string kelas_kamar;
	int lama_penyewaan;
} Kamar;

typedef struct Stack {
    int top;
    Kamar kamar[MAX_STACK];
} Stack;

void init(Stack *s);
void push(Stack *s, Kamar kamar);
Kamar pop(Stack *s);
void show(Stack s);

int is_empty(Stack s);
int is_full(Stack s);

int find_kamar_by_kode_kamar(Stack s, string kode_kamar);
