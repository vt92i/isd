#include "header.h"

int main(void) {
    srand(time(NULL));

    pesawat p[5];
    init(p);

    int menu, data, index = -1, i;
    char c[10], ch;
    string str;

    do {
        system("cls");

        printf("\n===== UNGUIDED SEARCHING =====");

        printf("\nRandom Characters : ");
        generate_characters(c);
        for (i = 0; i < 10; i++)
            printf("%c ", c[i]);

        printf("\n[1]. Cari Karakter");
        printf("\n[2]. Input Pesawat");
        printf("\n[3]. Cari Berdasarkan Jumlah Penumpang");
        printf("\n[4]. Cari Berdasarkan Kode Pesawat");
        printf("\n[5]. Edit Kode Pesawat");
        printf("\n[0]. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Cari Karakter ]\n");
                printf("Input Char : ");
                scanf(" %c", &ch);

                index = find_char(c, ch);
                if (index != -1)
                    printf("\n[ %c ] ditemukan di Index %d!\n", ch, index);
                else
                    printf("\nNo Data Found!\n");

                break;

            case 2:
                printf("\n[ Input Pesawat ]\n");

                if (is_empty(p)) {
                    int i;
                    for (i = 0; i < N; i++) {
                        while (1) {
                            printf("Kode Pesawat %d : ", i + 1);
                            fflush(stdin);
                            gets(p[i].kode_pesawat);

                            if (strlen(p[i].kode_pesawat) > 0) break;
                        }
                        int number = rand() % 300 + 1;
                        while (!is_jumlah_penumpang_unique(p, number))
                            number = rand() % 300 + 1;
                        p[i].jumlah_penumpang = number;
                    }
                } else
                    printf("\nFull!\n");

                break;

            case 3:
                printf("\n[ Cari Berdasarkan Jumlah Penumpang ]\n");

                if (is_empty(p)) {
                    printf("\nEmpty!\n");
                    break;
                }

                bubble_sort_desc_int(p);
                print(p);

                printf("Input Jumlah Penumpang : ");
                scanf("%d", &data);

                index = binary_search_int(p, 0, N - 1, data);
                if (index == -1)
                    printf("\nNo Data Found!\n");
                else {
                    bubble_sort_desc_int(p);
                    printf("\nData [ %s ] ditemukan di Index %d!\n", p[index].kode_pesawat, index);
                }

                break;

            case 4:
                printf("\n[ Cari Berdasarkan Kode Pesawat ]\n");

                if (is_empty(p)) {
                    printf("\nEmpty!\n");
                    break;
                }

                bubble_sort_desc_str(p);
                print(p);

                printf("Kode Pesawat : ");
                fflush(stdin);
                gets(str);

                int q = binary_search_str(p, 0, N - 1, str);
                if (q != -1)
                    printf("\nData [ %s ] ditemukan di Index %d!\n", str, q);
                else
                    printf("\nNo Data Found!\n");

                bubble_sort_desc_int(p);
                break;

            case 5:
                printf("\n[ Edit Kode Pesawat ]\n");

                if (index == -1) {
                    printf("\nNo Data Found!\n");
                    break;
                }

                printf("\nEdit [ %s ] pada Index %d\n", p[index].kode_pesawat, index);
                printf("Kode Pesawat : ");
                fflush(stdin);
                gets(p[index].kode_pesawat);

                printf("\nOK!\n");
                break;

            case 0:
                printf("\nNama  : Benidiktus Violaz Morello Anjolie");
                printf("\nNPM   : 210711385");
                printf("\nKelas : ISD E");
                printf("\nGood Luck!\n");
                break;

            default:
                printf("\nMenu tidak tersedia!\n");
                break;
        }
        getch();
    } while (menu != 0);

    return 0;
}
