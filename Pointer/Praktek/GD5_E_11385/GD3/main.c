#include "header.h"

int main(void) {
    int menu, submenu, id;

    Data D[ROW][COL];
    Data *d_ptr;

    d_ptr = *D;
    init_data(D);

    do {
        system("cls");

        print_data(D);
        printf("\n\n[ Posisi Sekarang ]");
        printf("\nID : %d", d_ptr->id);
        printf("\nNama : %s", d_ptr->nama);
        printf("\nTanggal Lahir : %s", d_ptr->tanggal_lahir);

        printf("\n\n==== GUIDED POINTER =====");
        printf("\n1. Pilih Posisi");
        printf("\n2. Isi Data");
        printf("\n3. Ubah Data");
        printf("\n4. Hapus Data");
        printf("\n5. Pindah Data");
        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n--- Pindah Posisi ---");
                printf("\n1. Pilih Data by ID");
                printf("\n2. Shift Right");
                printf("\n3. Shift Left");

                printf("\n>>> ");
                scanf("%d", &submenu);

                switch (submenu) {
                    case 1:
                        printf("\nMasukan ID : ");
                        scanf("%d", &id);

                        if (find_by_id(d_ptr, D, id)->id == d_ptr->id)
                            printf("\nID adalah posisi sekarang!\n");
                        else if (find_by_id(d_ptr, D, id)->id == 0)
                            printf("\nID tidak ditemukan!\n");
                        else {
                            d_ptr = find_by_id(d_ptr, D, id);
                            printf("\nBerpindah ke ID %d\n", id);
                        }

                        break;

                    case 2:
                        if (d_ptr->id == ROW * COL)
                            printf("\nID sudah mentok!\n");
                        else
                            d_ptr++;
                        break;

                    case 3:
                        if (d_ptr->id == 1)
                            printf("\nID sudah mentok!\n");
                        else
                            d_ptr--;
                        break;

                    default:
                        break;
                }

                break;

            case 2:
                if (strcmpi(d_ptr->nama, "-") != 0) {
                    printf("\nData sudah terisi!\n");
                } else {
                    printf("\n--- Input Data ---\n");
                    input_data(d_ptr);
                    printf("\nBerhasil input data!\n");
                }
                break;

            case 3:
                if (strcmpi(d_ptr->nama, "-") == 0) {
                    printf("\nData kosong!\n");
                } else {
                    printf("\n--- Ubah Data ---\n");
                    input_data(d_ptr);
                    printf("\nBerhasil ubah data!\n");
                }
                break;

            case 4:
                if (strcmpi(d_ptr->nama, "-") != 0) {
                    *d_ptr = make_data(d_ptr->id, "-", "-");
                } else {
                    printf("\nData kosong!\n");
                }
                break;

            case 5:
                if (strcmpi(d_ptr->nama, "-") != 0) {
                    printf("\nMasukan ID : ");
                    scanf("%d", &id);

                    if (find_by_id(d_ptr, D, id)->id == d_ptr->id)
                        printf("\nID adalah posisi sekarang!\n");
                    else if (find_by_id(d_ptr, D, id)->id == 0)
                        printf("\nID tidak ditemukan!\n");
                    else {
                        int current_id = d_ptr->id;
                        int target_id = id;

                        Data *temp = find_by_id(d_ptr, D, current_id);

                        d_ptr = find_by_id(d_ptr, D, target_id);
                        if (strcmpi(d_ptr->nama, "-") != 0) {
                            printf("\nID tidak kosong!");
                            break;
                        }

                        *d_ptr = make_data(target_id, temp->nama, temp->tanggal_lahir);

                        d_ptr = find_by_id(d_ptr, D, current_id);
                        *d_ptr = make_data(current_id, "-", "-");

                        d_ptr = find_by_id(d_ptr, D, target_id);
                        printf("\nPindah posisi ke ID %d\n", id);
                    }

                } else {
                    printf("\nData kosong!\n");
                }
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
