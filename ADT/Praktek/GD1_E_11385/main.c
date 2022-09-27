#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(void) {
    Mahasiswa M[5];
    string nama, npm;

    int menu, index;
    initMahasiswa(M);

    do {
        system("cls");
        printf("==== GUIDED 1 - ADT ==== \n");
        printf("1. Tambah data \n");
        printf("2. Tampil data \n");
        printf("3. Hapus data \n");
        printf("0. Exit \n");
        printf(">> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                index = isFull(M);
                if (isFull(M) != -1) {
                    printf("\nMasukan Nama Mahasiswa : ");
                    fflush(stdin);
                    gets(nama);
                    printf("Masukan NPM Mahasiswa  : ");
                    fflush(stdin);
                    gets(npm);

                    M[index] = makeMahasiswa(nama, npm);
                    printf("\nBerhasil menambahkan data! \n");
                } else {
                    printf("\nData sudah penuh! \n");
                }
                break;

            case 2:
                tampilMahasiswa(M);
                break;

            case 3:
                printf("\nMasukan NPM Mahasiswa yang akan dihapus : ");
                fflush(stdin);
                gets(npm);
                hapusMahasiswa(M, npm);
                break;

            case 0:
                printf("\n==== Keluar dari Program ====\n");
                break;

            default:
                printf("\nMenu tidak tersedia! \n");
                break;
        }
        getch();
    } while (menu != 0);

    return 0;
}
