//		Studi kasus antrian di teller bank
// Buatlah record Nasabah dengan atribut yang disimpan:
//	nama (string), nomor rekening (int), saldo(int)
// Buatlah ADT Queue (yaitu antrian nasabah) yang menampung nasabah tersebut (array of nasabah), sebanyak max 5 nasabah
// Lengkapi fungsi dasar Queue (Enqueue, Dequeue, CreateEmpty, isEmpty, isFull, isOneElmt)
// Buatlah prosedur untuk menampilkan data Nasabah dalam antrian
// Buatlah fungsi untuk menghitung total saldo semua nasabah dalam antrian

#include "header.h"

int main(void) {
    int menu;

    Queue Q;
    init(&Q);

    Nasabah nasabah;

    do {
        system("cls");
        printf("\n==== LATIHAN QUEUE(ARRAY IMPLEMENTATION) =====\n");
        printf("\n1. Print Queue");
        printf("\n2. Enqueue");
        printf("\n3. Dequeue");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Data Nasabah ]\n");
                print_queue(Q);
                break;

            case 2:
                printf("\n[ Input Nasabah ]\n");

                printf("Nama : ");
                scanf("%s", &nasabah.nama);
                printf("No Rekening : ");
                scanf("%d", &nasabah.no_rekening);
                printf("Saldo : ");
                scanf("%d", &nasabah.saldo);

                enqueue(&Q, nasabah);
                printf("\nNasabah %s dengan no rekening %d dan saldo %d telah masuk antrian!\n", nasabah.nama, nasabah.no_rekening, nasabah.saldo);
                break;

            case 3:
                printf("\n[ Data Nasabah ]\n");
                dequeue(&Q);
                break;

            default:
                printf("\nMenu tidak tersedia!\n");
                break;
        }

        getch();

    } while (menu != 0);

    return 0;
}
