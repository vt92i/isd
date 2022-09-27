#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE 5

typedef char string[64];

typedef struct Mahasiswa {
    string nama, npm;
    float ipk;
} Mahasiswa;

typedef struct Queue {
    Mahasiswa M[MAX_QUEUE];
    int head, tail;
} Queue;

Mahasiswa make_mahasiswa(string nama, string npm, float ipk);

void init(Queue *Q);
void print(Queue Q);

int is_empty(Queue Q);
int is_full(Queue Q);
int is_one_element(Queue Q);
int find_data_by_npm(Queue Q, string npm);

void enqueue(Queue *Q, Mahasiswa M);
void dequeue(Queue *Q);
