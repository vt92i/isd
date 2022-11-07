#include "header.h"
#include "time.h"

int main(void) {
    multilist l;
    init_empty(&l);

    address_parent p_tmp;
    address_child c_tmp;

    string nama, tipe, status, confirm;
    int id, menu, counter, f, c;
    float berat;

    int arr[1024];

    // Generate parents
    char ch = 'A';
    int i;
    srand(time(NULL));
    for (i = 0; i < 26; i++) {
        char str[2] = {ch++, '\0'};
        insert_last_parent(&l, make_data_parent(i + 1, str, rand() % 2 == 0 ? "Aktif" : "Tidak Aktif"));
    }

    // Generate children
    for (i = 0; i < (rand() % 100) + 1; i++)
        insert_last_child(l, (rand() % 26) + 1, make_data_child(i + 1 + 100, rand() % 2 == 0 ? "Selesai" : "Proses", (rand() % 24) + 1));

    do {
        system("cls");

        printf("\n\n==== UNGUIDED MULTILIST=====");
        printf("\n[ Parent ]");
        printf("\n1. Input Mesin Cuci");
        printf("\n2. Edit Status Mesin Cuci");
        printf("\n3. Hapus Data Mesin Cuci\n");

        printf("\n[ Child ]");
        printf("\n4. Input Paket Cucian\n");

        printf("\n[ Utility ]");
        printf("\n5. Hitung Jumlah Mesin Cuci");
        printf("\n6. Tampil Seluruh Data");
        printf("\n7. Distribusi Paket Cucian");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input Mesin Cuci ]\n");
                while (true) {
                    printf("ID : ");
                    scanf("%d", &id);
                    if (id < 1) continue;
                    if (is_parent_unique(l, id)) {
                        break;
                    } else {
                        printf("\nID sudah ada, silahkan masukkan ID yang lain!\n");
                    }
                }

                while (true) {
                    printf("Tipe : ");
                    fflush(stdin);
                    gets(tipe);
                    if (strlen(tipe) != 0) {
                        break;
                    } else {
                        printf("\nTipe tidak boleh kosong!\n");
                    }
                }

                while (true) {
                    printf("Status : ");
                    fflush(stdin);
                    gets(status);
                    if (strlen(status) != 0) {
                        if (strcmp(status, "Aktif") == 0 || strcmp(status, "Tidak Aktif") == 0) {
                            break;
                        } else {
                            printf("\nHarus Aktif atau Tidak Aktif!\n");
                        }
                    } else {
                        printf("\nTipe tidak boleh kosong!\n");
                    }
                }

                if (id % 2 == 0)
                    insert_last_parent(&l, make_data_parent(id, tipe, status));
                else
                    insert_first_parent(&l, make_data_parent(id, tipe, status));
                printf("\nData berhasil dimasukkan!\n");
                break;

            case 2:
                printf("\n[ Edit Status Mesin Cuci ]\n");

                printf("ID Parent : ");
                scanf("%d", &id);

                p_tmp = find_parent(l, id);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    print_parent(p_tmp);

                    if (strcmp(p_tmp->dp.status, "Aktif") == 0) {
                        printf("\nYakin ingin mengubah data (Aktif -> Tidak Aktif)? (y/n)");
                        fflush(stdin);
                        gets(confirm);
                        if (strcmp(confirm, "y") == 0) {
                            strcpy(p_tmp->dp.status, "Tidak Aktif");
                            printf("\nData berhasil diubah!\n");
                        } else {
                            printf("\nData tidak jadi diubah!\n");
                        }
                    } else {
                        printf("\nYakin ingin mengubah data (Tidak Aktif -> Aktif)? (y/n)");
                        fflush(stdin);
                        gets(confirm);
                        if (strcmp(confirm, "y") == 0) {
                            strcpy(p_tmp->dp.status, "Aktif");
                            printf("\nData berhasil diubah!\n");
                        } else {
                            printf("\nData tidak jadi diubah!\n");
                        }
                    }
                }
                break;

            case 3:
                printf("\n[ Hapus Data Mesin Cuci ]\n");
                counter = 0;
                for (p_tmp = l.first_parent; p_tmp != NULL; p_tmp = p_tmp->next) {
                    if (strcmp(p_tmp->dp.status, "Tidak Aktif") == 0) {
                        arr[counter] = p_tmp->dp.id;
                        counter++;
                    }
                }
                if (counter == 0) {
                    printf("\nTidak ada Mesin Cuci yang tidak aktif!\n");
                    break;
                }
                printf("\nJumlah Mesin Cuci yang akan dihapus : %d \n", counter);
                printf("\nYakin ingin hapus? (y/n)");
                fflush(stdin);
                gets(confirm);
                if (strcmp(confirm, "y") == 0) {
                    for (f = 0; f < counter; f++)
                        delete_at_parent(&l, arr[f]);
                    printf("\nData berhasil dihapus!\n");
                } else {
                    printf("\nData tidak jadi dihapus!\n");
                }
                break;

            case 4:
                printf("\n[ Input Paket Cucian ]\n");

                printf("ID Parent : ");
                scanf("%d", &id);

                p_tmp = find_parent(l, id);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    if (strcmp(p_tmp->dp.status, "Tidak Aktif") == 0) {
                        printf("\nMesin Cuci tidak aktif!\n");
                        break;
                    }

                    while (true) {
                        printf("ID : ");
                        scanf("%d", &c);
                        if (c < 1) continue;
                        if (is_child_unique(l, c))
                            break;
                        else
                            printf("\nChild dengan ID %d sudah ada!\n", c);
                    }

                    while (true) {
                        printf("Status : ");
                        fflush(stdin);
                        gets(status);
                        if (strlen(status) != 0) {
                            if (strcmp(status, "Selesai") == 0 || strcmp(status, "Proses") == 0) {
                                break;
                            } else {
                                printf("\nHarus Selesai atau Proses!\n");
                            }
                        } else {
                            printf("\nStatus tidak boleh kosong!\n");
                        }
                    }

                    while (true) {
                        printf("Berat : ");
                        scanf("%f", &berat);
                        if (berat < 1) continue;
                        break;
                    }

                    insert_last_child(l, id, make_data_child(c, status, berat));
                    printf("\nData berhasil dimasukkan!\n");
                }
                break;

            case 5:
                printf("\n[ Hitung Jumlah Mesin Cuci ]\n");
                counter = 0;
                for (p_tmp = l.first_parent; p_tmp != NULL; p_tmp = p_tmp->next) counter++;
                printf("\nJumlah Mesin Cuci : %d \n", counter);
                break;

            case 6:
                printf("\n[ Tampil Seluruh Data ]\n");
                if (!is_empty(l))
                    print_all(l);
                else
                    printf("\nList kosong!\n");
                break;

            case 7:
                printf("\n[ Distribusi Paket Cucian ]\n");
                distribute(&l);
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
