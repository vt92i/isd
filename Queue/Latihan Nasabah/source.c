#include "header.h"

void init(Queue *Q) {
    Q->head = -1;
    Q->tail = -1;
}

void enqueue(Queue *Q, Nasabah nasabah) {
    if (is_full(*Q)) {
        printf("\nAntrian penuh!\n");
        return;
    }

    if (is_empty(*Q)) {
        Q->head = Q->tail = 0;
    } else {
        Q->tail = Q->tail == MAX_QUEUE - 1 ? Q->tail = 0 : Q->tail++;
    }
    Q->nasabah[Q->tail] = nasabah;
}

void dequeue(Queue *Q) {
    Nasabah nasabah;
    if (is_empty(*Q))
        printf("\nAntrian kosong!\n");
    else {
        nasabah = Q->nasabah[Q->head];
        if (is_one_element(*Q))
            init(Q);
        else {
            Q->head = Q->head == MAX_QUEUE - 1 ? Q->head = 0 : Q->head++;
        }
        printf("\nNasabah %s dengan no rekening %d dan saldo %d telah keluar dari antrian!\n", nasabah.nama, nasabah.no_rekening, nasabah.saldo);
    }
}

void print_queue(Queue Q) {
    if (is_empty(Q)) {
        printf("\nAntrian kosong!\n");
        return;
    }

    int i;
    for (i = Q.head; i <= Q.tail; i++) {
        printf("Nasabah %d \n", i + 1);
        printf("Nama : %s \n", Q.nasabah[i].nama);
        printf("No Rekening : %d \n", Q.nasabah[i].no_rekening);
        printf("Saldo : %d \n", Q.nasabah[i].saldo);
        printf("\n");
    }
}

int is_empty(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

int is_full(Queue Q) {
    return ((Q.head < Q.tail && Q.tail - Q.head == MAX_QUEUE - 1) || (Q.head > Q.tail && Q.head - Q.tail == 1));
}

int is_one_element(Queue Q) {
    return Q.head == Q.tail && Q.head != -1;
}
