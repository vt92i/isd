#include "header.h"

int main(void) {
    int menu;
    int index;
    int is_initialized = 0;

    Stack s, s_deluxe, s_superior, s_standard;
    Kamar k;

    Kamar kk[MAX_STACK];
    kk_init(kk);

    do {
        system("cls");
        printf("\n==== UNGUIDED DAN TUGAS STACK (ARRAY IMPLEMENTATION) =====");
        printf("\n1. Init Data");
        printf("\n2. Input Data (No Sorting)");
        printf("\n3. Ubah Data");
        printf("\n4. Delete Data (POP)");
        printf("\n5. Show Data");
        printf("\n------------------------------------------------");
        printf("\n6. Input Data (Ascending)");
        printf("\n7. Input Data (Descending)");
        printf("\n8. Delete Data At");
        printf("\n9. Cluster");
        printf("\n10. Clear Cluster");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Init Data ]");
                if (!is_initialized) {
                    init(&s);
                    init(&s_deluxe);
                    init(&s_superior);
                    init(&s_standard);
                    is_initialized = 1;
                    printf("\nInit berhasil!\n");
                } else
                    printf("\nStack sudah init!\n");
                break;

            case 2:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                index = kk_find_empty(kk);
                printf("\n[ Input Data ]");
                if (!is_full(s) && index != -1) {
                    printf("\n");

                    while (true) {
                        printf("Input Nama Penghuni : ");
                        fflush(stdin);
                        gets(kk[index].nama_penghuni);

                        if (strlen(kk[index].nama_penghuni) != 0) break;
                    }

                    while (true) {
                        printf("Input Kode Kamar : ");
                        fflush(stdin);
                        gets(kk[index].kode_kamar);

                        if (strlen(kk[index].kode_kamar) != 0) break;
                    }

                    while (true) {
                        printf("Input Kelas Kamar : ");
                        fflush(stdin);
                        gets(kk[index].kelas_kamar);

                        if (strcmp(kk[index].kelas_kamar, "Deluxe") == 0 || strcmp(kk[index].kelas_kamar, "Superior") == 0 || strcmp(kk[index].kelas_kamar, "Standard") == 0) break;
                    }

                    while (true) {
                        printf("Input Lama Penyewaan (hari) : ");
                        scanf("%d", &kk[index].lama_penyewaan);

                        if (kk[index].lama_penyewaan > 0) break;
                    }

                    pop_all(&s);

                    int i;
                    for (i = -1; i < index; i++) push(&s, kk[i + 1]);

                    printf("\nBerhasil push data!\n");
                } else {
                    printf("\nStack sudah penuh!\n");
                }
                break;

            case 3:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                printf("\n[ Ubah Data ]");
                if (!is_empty(s)) {
                    printf("\n");

                    while (true) {
                        printf("Input Kode Kamar : ");
                        fflush(stdin);
                        gets(k.kode_kamar);

                        if (strlen(k.kode_kamar) != 0) break;
                    }

                    int index = find_kamar_by_kode_kamar(s, k.kode_kamar);
                    if (index != -1) {
                        printf("\n");
                        while (true) {
                            printf("Input Nama Penghuni : ");
                            fflush(stdin);
                            gets(s.kamar[index].nama_penghuni);

                            if (strlen(k.nama_penghuni) != 0) break;
                        }

                        while (true) {
                            printf("Input Kode Kamar : ");
                            fflush(stdin);
                            gets(s.kamar[index].kode_kamar);

                            if (strlen(k.kode_kamar) != 0) break;
                        }

                        while (true) {
                            printf("Input Kelas Kamar : ");
                            fflush(stdin);
                            gets(s.kamar[index].kelas_kamar);

                            if (strcmp(s.kamar[index].kelas_kamar, "Deluxe") == 0 || strcmp(s.kamar[index].kelas_kamar, "Superior") == 0 || strcmp(s.kamar[index].kelas_kamar, "Standard") == 0) break;
                        }

                        while (true) {
                            printf("Input Lama Penyewaan (hari) : ");
                            scanf("%d", &s.kamar[index].lama_penyewaan);

                            if (s.kamar[index].lama_penyewaan > 0) break;
                        }

                        printf("\nBerhasil ubah data!\n");
                    } else {
                        printf("\nKamar tidak ditemukan!\n");
                    }

                } else
                    printf("\nStack kosong!\n");
                break;

            case 4:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                index = kk_find_empty(kk);
                if (index == -1) index = MAX_STACK;

                printf("\n[ Delete Data (POP) ]");
                if (!is_empty(s)) {
                    kk[index - 1] = pop(&s);
                    printf("\n[ Data Yang Di POP ] \n");
                    printf("Nama Penghuni : %s \n", kk[index - 1].nama_penghuni);
                    printf("Kode Kamar : %s \n", kk[index - 1].kode_kamar);
                    printf("Kelas Kamar : %s \n", kk[index - 1].kelas_kamar);
                    printf("Lama Penyewaan : %d hari \n", kk[index - 1].lama_penyewaan);
                    kk_clear(&kk[index - 1]);
                } else {
                    printf("\nStack kosong!\n");
                }

                break;

            case 5:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                printf("\n[ Show Data ]");
                if (!is_empty(s))
                    show(s);
                else
                    printf("\nStack kosong!\n");
                break;

            case 6:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                index = kk_find_empty(kk);
                printf("\n[ Input Data ]");
                if (!is_full(s) && index != -1) {
                    printf("\n");

                    while (true) {
                        printf("Input Nama Penghuni : ");
                        fflush(stdin);
                        gets(kk[index].nama_penghuni);

                        if (strlen(kk[index].nama_penghuni) != 0) break;
                    }

                    while (true) {
                        printf("Input Kode Kamar : ");
                        fflush(stdin);
                        gets(kk[index].kode_kamar);

                        if (strlen(kk[index].kode_kamar) != 0) break;
                    }

                    while (true) {
                        printf("Input Kelas Kamar : ");
                        fflush(stdin);
                        gets(kk[index].kelas_kamar);

                        if (strcmp(kk[index].kelas_kamar, "Deluxe") == 0 || strcmp(kk[index].kelas_kamar, "Superior") == 0 || strcmp(kk[index].kelas_kamar, "Standard") == 0) break;
                    }

                    while (true) {
                        printf("Input Lama Penyewaan (hari) : ");
                        scanf("%d", &kk[index].lama_penyewaan);

                        if (kk[index].lama_penyewaan > 0) break;
                    }

                    pop_all(&s);
                    kk_sort_asc(kk, index + 1);

                    int i;
                    for (i = -1; i < index; i++) push(&s, kk[i + 1]);

                    printf("\nBerhasil push data!\n");
                } else {
                    printf("\nStack sudah penuh!\n");
                }
                break;

            case 7:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                index = kk_find_empty(kk);
                printf("\n[ Input Data ]");
                if (!is_full(s) && index != -1) {
                    printf("\n");

                    while (true) {
                        printf("Input Nama Penghuni : ");
                        fflush(stdin);
                        gets(kk[index].nama_penghuni);

                        if (strlen(kk[index].nama_penghuni) != 0) break;
                    }

                    while (true) {
                        printf("Input Kode Kamar : ");
                        fflush(stdin);
                        gets(kk[index].kode_kamar);

                        if (strlen(kk[index].kode_kamar) != 0) break;
                    }

                    while (true) {
                        printf("Input Kelas Kamar : ");
                        fflush(stdin);
                        gets(kk[index].kelas_kamar);

                        if (strcmp(kk[index].kelas_kamar, "Deluxe") == 0 || strcmp(kk[index].kelas_kamar, "Superior") == 0 || strcmp(kk[index].kelas_kamar, "Standard") == 0) break;
                    }

                    while (true) {
                        printf("Input Lama Penyewaan (hari) : ");
                        scanf("%d", &kk[index].lama_penyewaan);

                        if (kk[index].lama_penyewaan > 0) break;
                    }

                    pop_all(&s);
                    kk_sort_desc(kk, index + 1);

                    int i;
                    for (i = -1; i < index; i++) push(&s, kk[i + 1]);

                    printf("\nBerhasil push data!\n");
                } else {
                    printf("\nStack sudah penuh!\n");
                }
                break;

            case 8:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                printf("\n[ Delete Data At]");
                if (!is_empty(s)) {
                    printf("\n");

                    while (true) {
                        printf("Input Kode Kamar : ");
                        fflush(stdin);
                        gets(k.kode_kamar);

                        if (strlen(k.kode_kamar) != 0) break;
                    }

                    int index_k = find_kamar_by_kode_kamar(s, k.kode_kamar);

                    if (index_k != -1) {
                        int i;

                        for (i = index_k; i != MAX_STACK; i++) {
                            if (i == MAX_STACK - 1) {
                                kk_clear(&kk[i]);
                                break;
                            }
                            kk[i] = kk[i + 1];
                        }

                        index = kk_find_empty(kk);
                        pop_all(&s);

                        for (i = -1; i < index - 1; i++) push(&s, kk[i + 1]);
                        printf("\nBerhasil delete data!\n");

                    } else {
                        printf("\nKamar tidak ditemukan!\n");
                    }
                } else {
                    printf("\nStack kosong!\n");
                }
                break;

            case 9:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                printf("\n[ Cluster]");
                int i;
                for (i = 0; i != s.top + 1; i++) {
                    if (strcmp(s.kamar[i].kelas_kamar, "Deluxe") == 0)
                        if (!is_full(s_deluxe)) push(&s_deluxe, kk[i]);
                    if (strcmp(s.kamar[i].kelas_kamar, "Superior") == 0)
                        if (!is_full(s_superior)) push(&s_superior, kk[i]);
                    if (strcmp(s.kamar[i].kelas_kamar, "Standard") == 0)
                        if (!is_full(s_standard)) push(&s_standard, kk[i]);
                }

                pop_all(&s);
                kk_init(kk);

                printf("\n[ Data Deluxe ]\n");
                for (i = 0; i != s_deluxe.top + 1; i++)
                    printf("[ %s - %s - %d hari ]\n", s_deluxe.kamar[i].kode_kamar, s_deluxe.kamar[i].nama_penghuni, s_deluxe.kamar[i].lama_penyewaan);

                printf("\n[ Data Superior ]\n");
                for (i = 0; i != s_superior.top + 1; i++)
                    printf("[ %s - %s - %d hari ]\n", s_superior.kamar[i].kode_kamar, s_superior.kamar[i].nama_penghuni, s_superior.kamar[i].lama_penyewaan);

                printf("\n[ Data Standard ]\n");
                for (i = 0; i != s_standard.top + 1; i++)
                    printf("[ %s - %s - %d hari ]\n", s_standard.kamar[i].kode_kamar, s_standard.kamar[i].nama_penghuni, s_standard.kamar[i].lama_penyewaan);

                break;

            case 10:
                if (!is_initialized) {
                    printf("\nBelum init!\n");
                    break;
                }

                pop_all(&s_deluxe);
                pop_all(&s_superior);
                pop_all(&s_standard);
                printf("\nClear cluster!\n");
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
