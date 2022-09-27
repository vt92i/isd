#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 5

typedef char string[64];

typedef struct Nasabah {
    string nama;
    int no_rekening;
    int saldo;
} Nasabah;

typedef struct Queue {
    Nasabah nasabah[MAX_QUEUE];
    int head;
    int tail;
} Queue;

void init(Queue *Q);
void enqueue(Queue *Q, Nasabah nasabah);
void dequeue(Queue *Q);
void print_queue(Queue Q);

int is_empty(Queue Q);
int is_full(Queue Q);
int is_one_element(Queue Q);
