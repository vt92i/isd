#include "header.h"

int main(void) {
    Data data[ROW][COL];

    int menu, angka;
    Index index;

    init_matriks(data);

    do {
        system("cls");
        printf("\n==== GUIDED MATRIX ====\n");
        printf("\nNama : Benidiktus Violaz Morello Anjolie");
        printf("\nNPM  : 210711385");
        printf("\n1. Isi Data");
        printf("\n2. Cari Data");
        printf("\n3. Print Data");
        printf("\n0. Keluar");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n=== Input Data ===\n");

                while (true) {
                    printf("Index I : ");
                    scanf("%d", &index.i);

                    if (index.i < 0)
                        printf("Index tidak boleh kurang dari 0!\n\n");
                    else if (index.i >= ROW)
                        printf("Index tidak boleh lebih dari %d!\n\n", ROW - 1);
                    else
                        break;
                }

                while (true) {
                    printf("Index J : ");
                    scanf("%d", &index.j);

                    if (index.j < 0)
                        printf("Index tidak boleh kurang dari 0!\n\n");
                    else if (index.j >= COL)
                        printf("Index tidak boleh lebih dari %d!\n\n", COL - 1);
                    else
                        break;
                }

                if (is_filled(data, index)) {
                    printf("\nData sudah terisi!\n");
                    break;
                } else {
                    printf("\nInput Angka : ");
                    scanf("%d", &angka);
                    data[index.i][index.j] = create_data(angka, "data_filled");
                    printf("\nBerhasil input data!\n");
                }
                break;

            case 2:
                printf("\n=== Cari Data ===\n");

                printf("\nInput Angka : ");
                scanf("%d", &angka);

                index = find_data(data, angka);

                if (index.i == -1) {
                    printf("\nData tidak ditemukan!\n");
                } else {
                    printf("\nData pertama kali ditemukan pada index");
                    printf("\nI : %d", index.i);
                    printf("\nJ : %d", index.j);
                }
                break;

            case 3:
                printf("\n=== Print Data ===\n");
                print_matriks(data);
                break;

            case 0:
                printf("\nKeluar Program");
                printf("\nNama : Benidiktus Violaz Morello Anjolie");
                printf("\nNPM  : 210711385");
                break;

            default:
                printf("\nMenu tidak tersedia!\n");
                break;
        }
        getch();
    } while (menu != 0);

    return 0;
}
