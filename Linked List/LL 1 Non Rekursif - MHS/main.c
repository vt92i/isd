#include "header.h"

int main(int argc, char *argv[]) {
    Mahasiswa M;
    int nim;
    string nama;
    float ipk;

    int pil = -1;

    List myList;
    address cari;
    inisialisasi(&myList);

    do {
        system("cls");
        printf("---=== Menu ===---\n");
        printf(" 1. Insert First\n");
        printf(" 2. Insert Last\n");
        printf(" 3. Delete First\n");
        printf(" 4. Delete Last\n");
        printf(" 5. Show List\n");
        printf(" 6. Cari IPK\n");
        printf(" 7. Print Mahasiswa IPK Tertinggi\n");
        printf(" 8. Hapus Mahasiswa IPK < 2\n");
        printf(" 0. Exit\n");
        printf("Masukkan pilihan : ");
        scanf("%d", &pil);

        switch (pil) {
            case 1: {
                printf("\nMasukkan NIM  : ");
                scanf("%d", &nim);
                printf("Masukkan Nama : ");
                fflush(stdin);
                gets(nama);
                printf("Masukkan Ipk  : ");
                scanf("%f", &ipk);
                M = initMahasiswa(nim, nama, ipk);
                insertFirst(&myList, M);
                getch();
                break;
            }
            case 2: {
                printf("\nMasukkan NIM  : ");
                scanf("%d", &nim);
                printf("Masukkan Nama : ");
                fflush(stdin);
                gets(nama);
                printf("Masukkan Ipk  : ");
                scanf("%f", &ipk);
                M = initMahasiswa(nim, nama, ipk);
                insertLast(&myList, M);
                getch();
                break;
            }
            case 3: {
                deleteFirst(&myList);
                getch();
                break;
            }
            case 4: {
                deleteLast(&myList);
                getch();
                break;
            }
            case 5: {
                showList(myList);
                getch();
                break;
            }
            case 6: {
                // printf("Masukkan Nama : ");
                // fflush(stdin);
                // gets(nama);
                // ipk = findNode(myList, nama);
                // if (ipk != -1)
                //     printf("IPK dari mahasiswa %s adalah %0.2f", nama, ipk);
                // else
                //     printf("Mahasiswa %s tidak ditemukan", nama);
                getch();
                break;
            }

            case 7:
                break;

            case 8:
                deleteIPK(&myList);
                break;

            case 9:
                printf("\nMasukkan NIM  : ");
                scanf("%d", &nim);

                deleteAt(&myList, nim);

                break;
        }
    } while (pil != 0);

    return 0;
}
