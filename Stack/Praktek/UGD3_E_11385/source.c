#include "header.h"

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, Kamar kamar) {
    s->top++;
    s->kamar[s->top] = kamar;
}

Kamar pop(Stack *s) {
    Kamar k;

    k = s->kamar[s->top];
    s->top--;

    return k;
}

void show(Stack s) {
    int i;

    for (i = 0; i != s.top + 1; i++) {
    	printf("[ Data ke %d ] \n", i+1);
    	printf("Nama Penghuni : %s \n", s.kamar[i].nama_penghuni);
    	printf("Kode Kamar : %s \n", s.kamar[i].kode_kamar);
    	printf("Kelas Kamar : %s \n", s.kamar[i].kelas_kamar);
    	printf("Lama Penyewaan : %d hari \n", s.kamar[i].lama_penyewaan);
    	printf("\n");
    }
}

int is_empty(Stack s) {
    return s.top == -1;
}

int is_full(Stack s) {
    return s.top == MAX_STACK - 1;
}

int find_kamar_by_kode_kamar(Stack s, string kode_kamar) {
	int i;
	for (i = 0; i != s.top + 1; i++) {
    	if (strcmp(s.kamar[i].kode_kamar, kode_kamar) == 0) return i;
    }
    return -1;
}
