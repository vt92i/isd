#include "header.h"

int main(void) {
    multilist l;
    init_empty(&l);

    address_parent p_tmp;
    address_child c_tmp;

    string nama, confirm;
    int id_parent, id_tim, umur, menu;

    do {
        system("cls");

        printf("\n\n==== GUIDED LINKED LIST 2=====");
        printf("\n[ Parent ]");
        printf("\n1. Insert First Parent");
        printf("\n2. Insert After Parent");
        printf("\n3. Insert Last Parent");
        printf("\n4. Delete First Parent");
        printf("\n5. Delete At Parent");
        printf("\n6. Delete Last Parent");
        printf("\n7. Find Parent");
        printf("\n8. Print Parent\n");

        printf("\n[ Child ]");
        printf("\n9. Insert First Child");
        printf("\n10. Insert Last Child");
        printf("\n11. Delete First Child");
        printf("\n12. Delete Last Child");
        printf("\n13. Print Child\n");

        printf("\n14. Print All");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input First Parent ]\n");
                while (true) {
                    printf("ID Tim : ");
                    scanf("%d", &id_tim);
                    if (is_unique_id(l, id_tim)) {
                        break;
                    } else {
                        printf("\nID sudah ada, silahkan masukkan ID yang lain!\n");
                    }
                }

                while (true) {
                    printf("Nama Tim : ");
                    scanf("%s", &nama);
                    if (strlen(nama) != 0) {
                        break;
                    } else {
                        printf("\nNama Tim tidak boleh kosong!\n");
                    }
                }

                insert_first_parent(&l, make_data_parent(id_tim, nama));
                printf("\nData berhasil dimasukkan!\n");
                break;

            case 2:
                printf("\n[ Input After Parent ]\n");

                if (is_empty(l)) {
                    printf("\nList kosong!\n");
                    break;
                }

                printf("ID Parent : ");
                scanf("%d", &id_parent);

                p_tmp = find_parent(l, id_parent);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    while (true) {
                        printf("ID Tim : ");
                        scanf("%d", &id_tim);
                        if (is_unique_id(l, id_tim)) {
                            break;
                        } else {
                            printf("\nID sudah ada, silahkan masukkan ID yang lain!\n");
                        }
                    }

                    while (true) {
                        printf("Nama Tim : ");
                        scanf("%s", &nama);
                        if (strlen(nama) != 0) {
                            break;
                        } else {
                            printf("\nNama Tim tidak boleh kosong!\n");
                        }
                    }

                    insert_after_parent(&l, id_parent, make_data_parent(id_tim, nama));
                    printf("\nData berhasil dimasukkan!\n");
                }
                break;

            case 3:
                printf("\n[ Input Last Parent ]\n");
                while (true) {
                    printf("ID Tim : ");
                    scanf("%d", &id_tim);
                    if (is_unique_id(l, id_tim)) {
                        break;
                    } else {
                        printf("\nID sudah ada, silahkan masukkan ID yang lain!\n");
                    }
                }

                while (true) {
                    printf("Nama Tim : ");
                    scanf("%s", &nama);
                    if (strlen(nama) != 0) {
                        break;
                    } else {
                        printf("\nNama Tim tidak boleh kosong!\n");
                    }
                }

                insert_last_parent(&l, make_data_parent(id_tim, nama));
                printf("\nData berhasil dimasukkan!\n");
                break;

            case 4:
                printf("\n[ Delete First Parent ]\n");

                if (is_empty(l)) {
                    printf("\nList kosong!\n");
                    break;
                }

                print_parent(l.first_parent);
                print_all_children(l.first_parent);

                printf("\nYakin ingin menghapus data? (y/n)");
                fflush(stdin);
                gets(confirm);
                if (strcmp(confirm, "y") == 0) {
                    delete_first_parent(&l);
                    printf("\nData berhasil dihapus!\n");
                } else {
                    printf("\nData tidak jadi dihapus!\n");
                }
                break;

            case 5:
                printf("\n[ Delete At Parent ]\n");

                if (is_empty(l)) {
                    printf("\nList kosong!\n");
                    break;
                }

                printf("ID Parent : ");
                scanf("%d", &id_parent);

                p_tmp = find_parent(l, id_parent);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    print_parent(p_tmp);
                    print_all_children(p_tmp);

                    printf("\nYakin ingin menghapus data? (y/n)");
                    fflush(stdin);
                    gets(confirm);
                    if (strcmp(confirm, "y") == 0) {
                        delete_at_parent(&l, id_parent);
                        printf("\nData berhasil dihapus!\n");
                    } else {
                        printf("\nData tidak jadi dihapus!\n");
                    }
                }
                break;

            case 6:
                printf("\n[ Delete Last Parent ]\n");

                if (is_empty(l)) {
                    printf("\nList kosong!\n");
                    break;
                }

                for (p_tmp = l.first_parent; p_tmp->next != NULL; p_tmp = p_tmp->next)
                    ;

                print_parent(p_tmp);
                print_all_children(p_tmp);

                printf("\nYakin ingin menghapus data? (y/n)");
                fflush(stdin);
                gets(confirm);
                if (strcmp(confirm, "y") == 0) {
                    delete_last_parent(&l);
                    printf("\nData berhasil dihapus!\n");
                } else {
                    printf("\nData tidak jadi dihapus!\n");
                }
                break;

            case 7:
                printf("\n[ Find Parent ]\n");

                printf("ID Parent : ");
                scanf("%d", &id_parent);

                p_tmp = find_parent(l, id_parent);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    print_parent(p_tmp);
                    print_all_children(p_tmp);
                }

                break;

            case 8:
                printf("\n[ Print Parent ]\n");
                if (!is_empty(l))
                    print_all_parent(l);
                else
                    printf("\nList kosong!\n");
                break;

            case 9:
                printf("\n[ Input First Child ]\n");

                printf("ID Parent : ");
                scanf("%d", &id_parent);

                p_tmp = find_parent(l, id_parent);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    print_parent(p_tmp);

                    while (true) {
                        printf("Nama Pemain : ");
                        scanf("%s", &nama);
                        if (strlen(nama) != 0) {
                            break;
                        } else {
                            printf("\nNama Pemain tidak boleh kosong!\n");
                        }
                    }

                    while (true) {
                        printf("Umur : ");
                        scanf("%d", &umur);
                        if (umur > 0) {
                            break;
                        } else {
                            printf("\nUmur tidak boleh kurang dari 1!\n");
                        }
                    }

                    insert_first_child(l, id_parent, make_data_child(nama, umur));
                    printf("\nData berhasil dimasukkan!\n");
                }
                break;

            case 10:
                printf("\n[ Input Last Child ]\n");

                printf("ID Parent : ");
                scanf("%d", &id_parent);

                p_tmp = find_parent(l, id_parent);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    print_parent(p_tmp);

                    while (true) {
                        printf("Nama Pemain : ");
                        scanf("%s", &nama);
                        if (strlen(nama) != 0) {
                            break;
                        } else {
                            printf("\nNama Pemain tidak boleh kosong!\n");
                        }
                    }

                    while (true) {
                        printf("Umur : ");
                        scanf("%d", &umur);
                        if (umur > 0) {
                            break;
                        } else {
                            printf("\nUmur tidak boleh kurang dari 1!\n");
                        }
                    }

                    insert_last_child(l, id_parent, make_data_child(nama, umur));
                    printf("\nData berhasil dimasukkan!\n");
                }
                break;

            case 11:
                printf("\n[ Delete First Child ]\n");

                printf("ID Parent : ");
                scanf("%d", &id_parent);

                p_tmp = find_parent(l, id_parent);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    print_parent(p_tmp);
                    if (have_children(p_tmp)) {
                        print_child(p_tmp->first_child);
                        printf("\nYakin ingin menghapus data? (y/n)");
                        fflush(stdin);
                        gets(confirm);
                        if (strcmp(confirm, "y") == 0) {
                            delete_first_child(l, id_parent);
                            printf("\nData berhasil dihapus!\n");
                        } else {
                            printf("\nData tidak jadi dihapus!\n");
                        }
                    } else
                        printf("\nParent tidak memiliki child!\n");
                }

                break;

            case 12:
                printf("\n[ Delete Last Child ]\n");

                printf("ID Parent : ");
                scanf("%d", &id_parent);

                p_tmp = find_parent(l, id_parent);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    print_parent(p_tmp);
                    if (have_children(p_tmp)) {
                        for (c_tmp = p_tmp->first_child; c_tmp->next != NULL; c_tmp = c_tmp->next)
                            ;
                        print_child(c_tmp);
                        printf("\nYakin ingin menghapus data? (y/n)");
                        fflush(stdin);
                        gets(confirm);
                        if (strcmp(confirm, "y") == 0) {
                            delete_last_child(l, id_parent);
                            printf("\nData berhasil dihapus!\n");
                        } else {
                            printf("\nData tidak jadi dihapus!\n");
                        }
                    } else
                        printf("\nParent tidak memiliki child!\n");
                }
                break;

            case 13:
                printf("\n[ Print Child ]\n");

                printf("ID Parent : ");
                scanf("%d", &id_parent);

                p_tmp = find_parent(l, id_parent);
                if (p_tmp == NULL) {
                    printf("\nID Parent tidak ditemukan!\n");
                } else {
                    print_all_children(p_tmp);
                }
                break;

            case 14:
                if (!is_empty(l))
                    print_all(l);
                else
                    printf("\nList kosong!\n");
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
