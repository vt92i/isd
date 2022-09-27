#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE 5

typedef char string[64];

typedef struct Nasabah {
    string nama, jenis;
    int id, jumlah_uang;
} Nasabah;

typedef struct Queue {
    Nasabah N[MAX_QUEUE];
    int head, tail;
} Queue;

Nasabah make_nasabah(int id, string nama, string jenis, int jumlah_uang);

void init(Queue *Q);
void print(Queue Q);

int is_empty(Queue Q);
int is_full(Queue Q);
int is_one_element(Queue Q);
int find_data_by_id(Queue Q, int id);

void enqueue(Queue *Q, Nasabah N);
void dequeue(Queue *Q);
