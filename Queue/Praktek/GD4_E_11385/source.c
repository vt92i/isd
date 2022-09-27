#include "header.h"

Mahasiswa make_mahasiswa(string nama, string npm, float ipk) {
    Mahasiswa M;

    strcpy(M.nama, nama);
    strcpy(M.npm, npm);
    M.ipk = ipk;

    return M;
}

void init(Queue *Q) {
    Q->head = Q->tail = -1;
}

void print(Queue Q) {
    int i, j = 0;

    if (Q.head <= Q.tail) {
        for (i = Q.head; i <= Q.tail; i++)
            printf("%d. %s(%.2f); \n", i + 1, Q.M[i].nama, Q.M[i].ipk);
    } else {
        for (i = Q.head; i <= MAX_QUEUE - 1; i++) {
            printf("%d. %s(%.2f); \n", j, Q.M[i].nama, Q.M[i].ipk);
            j++;
        }

        for (i = 0; i < Q.tail; i++) {
            printf("%d. %s(%.2f); \n", j, Q.M[i].nama, Q.M[i].ipk);
            j++;
        }
    }
}

int is_empty(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

int is_full(Queue Q) {
    return Q.head < Q.tail && Q.tail - Q.head == MAX_QUEUE - 1 || Q.tail < Q.head && Q.tail + 1 == Q.head;
}

int is_one_element(Queue Q) {
    return Q.head == Q.tail && !is_empty(Q);
}

int find_data_by_npm(Queue Q, string npm) {
    int i;

    if (Q.head <= Q.tail) {
        for (i = Q.head; i <= Q.tail; i++)
            if (strcmp(Q.M[i].npm, npm) == 0) return i;
    } else {
        for (i = Q.head; i <= MAX_QUEUE - 1; i++)
            if (strcmp(Q.M[i].npm, npm) == 0) return i;

        for (i = 0; i < Q.tail; i++)
            if (strcmp(Q.M[i].npm, npm) == 0) return i;
    }
    return -1;
}

void enqueue(Queue *Q, Mahasiswa M) {
    if (is_empty(*Q))
        Q->head = Q->tail = 0;
    else {
        if (Q->tail == MAX_QUEUE - 1)
            Q->tail = 0;
        else
            Q->tail++;
    }
    Q->M[Q->tail] = M;
}

void dequeue(Queue *Q) {
    string t_npm;
    strcpy(t_npm, Q->M[Q->head].npm);

    if (is_one_element(*Q))
        init(Q);
    else {
        if (Q->head == MAX_QUEUE - 1)
            Q->head = 0;
        else
            Q->head++;
    }

    printf("\nMahasiswa dengan NPM %s berhasil dihapus!\n", t_npm);
}
