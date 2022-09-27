#include "header.h"

Nasabah make_nasabah(int id, string nama, string jenis, int jumlah_uang) {
    Nasabah N;

	N.id = id;
    strcpy(N.nama, nama);
    strcpy(N.jenis, jenis);
    N.jumlah_uang = jumlah_uang;

    return N;
}

void init(Queue *Q) {
    Q->head = Q->tail = -1;
    
    int i;
    for(i = 0; i < 5; i++) {
    	Q->N[i].id = 0;
    	strcpy(Q->N[i].nama, "");
   		Q->N[i].jumlah_uang = 0;
	}
}

void print(Queue Q) {
    int i, j = 0;

    if (Q.head <= Q.tail) {
        for (i = Q.head; i <= Q.tail; i++)
            printf("%d(%s) || ", Q.N[i].id, Q.N[i].nama);
    } else {
        for (i = Q.head; i <= MAX_QUEUE - 1; i++) {
            printf("%d(%s) || ", Q.N[i].id, Q.N[i].nama);
            j++;
        }

        for (i = 0; i < Q.tail; i++) {
            printf("%d(%s) || ", Q.N[i].id, Q.N[i].nama);
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

int find_data_by_id(Queue Q, int id) {
    int i;

    if (Q.head <= Q.tail) {
        for (i = Q.head; i <= Q.tail; i++)
            if (Q.N[i].id == id) return i;
    } else {
        for (i = Q.head; i <= MAX_QUEUE - 1; i++)
            if (Q.N[i].id == id) return i;

        for (i = 0; i < Q.tail; i++)
            if (Q.N[i].id == id) return i;
    }
    return -1;
}

void enqueue(Queue *Q, Nasabah N) {
    if (is_empty(*Q))
    	Q->head = Q->tail = 0;
    else {
        if (Q->tail == MAX_QUEUE - 1)
            Q->tail = 0;
        else
            Q->tail++;
    }
    Q->N[Q->tail] = N;
}

void dequeue(Queue *Q) {
//    string t_npm;
//    strcpy(t_npm, Q->M[Q->head].npm);

    if (is_one_element(*Q))
        init(Q);
    else {
        if (Q->head == MAX_QUEUE - 1)
            Q->head = 0;
        else
            Q->head++;
    }

//    printf("\nMahasiswa dengan NPM %s berhasil dihapus!\n", t_npm);
}
