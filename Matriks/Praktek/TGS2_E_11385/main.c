#include "header.h"

int main(void) {
    Index index;

    Meja m[ROW][COL];
    init_meja(m);

    string nama_pelanggan, nomor_meja;
    int kode_pesanan;

    int menu;

    do {
        system("cls");

        printf("\nNama : Benidiktus Violaz Morello Anjolie\n");
        printf("NPM  : 210711385\n");

        printf("\n==== UNGUIDED MATRIX ====\n");
        printf("1. Input Data\n");
        printf("2. Edit Data\n");
        printf("3. Cari Data\n");
        printf("4. Tampil Data\n");

        printf("\n==== TUGAS MATRIX ====\n");
        printf("5. Hapus Data\n");
        printf("6. Enkripsi Kode Pesanan\n");
        printf("7. Enkripsi Nomor Meja (Rotate 90 Degree)\n");
        printf("0. Keluar\n");

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

                if (is_filled(m, index)) {
                    printf("\nMeja sudah terisi!\n");
                    break;
                } else {
                    printf("\n");
                    while (true) {
                        printf("Input Nama Pelanggan : ");
                        fflush(stdin);
                        gets(m[index.i][index.j].nama_pelanggan);

                        if (strlen(m[index.i][index.j].nama_pelanggan) == 0) continue;
                        if (strcmpi(m[index.i][index.j].nama_pelanggan, "-") == 0) continue;

                        break;
                    }

                    while (true) {
                        printf("Input Nomor Meja     : ");
                        fflush(stdin);
                        gets(m[index.i][index.j].nomor_meja);

                        if (strlen(m[index.i][index.j].nomor_meja) < 3) continue;

                        break;
                    }

                    while (true) {
                        printf("Input Kode Pesanan   : ");
                        scanf("%d", &m[index.i][index.j].kode_pesanan);

                        if (m[index.i][index.j].kode_pesanan < 0) continue;

                        break;
                    }

                    printf("\nInput Data berhasil!\n");
                }
                break;

            case 2:
                printf("\n=== Edit Data ===\n");

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

                if (!is_filled(m, index)) {
                    printf("\nMeja belum input!\n");
                    break;
                }

                printf("\n");
                while (true) {
                    printf("Input Nama Pelanggan : ");
                    fflush(stdin);
                    gets(m[index.i][index.j].nama_pelanggan);

                    if (strlen(m[index.i][index.j].nama_pelanggan) == 0) continue;
                    if (strcmpi(m[index.i][index.j].nama_pelanggan, "-") == 0) continue;

                    break;
                }

                while (true) {
                    printf("Input Nomor Meja     : ");
                    fflush(stdin);
                    gets(m[index.i][index.j].nomor_meja);

                    if (strlen(m[index.i][index.j].nomor_meja) < 3) continue;

                    break;
                }

                while (true) {
                    printf("Input Kode Pesanan   : ");
                    scanf("%d", &m[index.i][index.j].kode_pesanan);

                    if (m[index.i][index.j].kode_pesanan < 0) continue;

                    break;
                }

                printf("\nInput Data berhasil!\n");
                break;

            case 3:
                printf("\n=== Cari Data ===\n");

                printf("Input Nomor Meja : ");
                fflush(stdin);
                gets(nomor_meja);

                index = find_data_by_nomor_meja(m, nomor_meja);

                if (index.i == -1) {
                    printf("\nData tidak ditemukan!\n");
                } else {
                    printf("\n");
                    printf("Nama Pelanggan : %s \n", m[index.i][index.j].nama_pelanggan);
                    printf("Nomor Meja     : %s \n", m[index.i][index.j].nomor_meja);
                    printf("Kode Pesanan   : %d \n", m[index.i][index.j].kode_pesanan);
                }
                break;

            case 4:
                printf("\n=== Print Data ===\n");
                print_meja(m);
                break;

            case 5:
                printf("\n=== Hapus Data ===\n");

                printf("Input Nama Pelanggan : ");
                fflush(stdin);
                gets(nama_pelanggan);

                index = find_data_by_nama_pelanggan(m, nama_pelanggan);

                if (index.i == -1) {
                    printf("\nData tidak ditemukan!\n");
                } else {
                    m[index.i][index.j] = create_meja("-", "-", 0);
                    printf("\nData berhasil dihapus!\n");
                }
                break;

            case 6:
                printf("\n=== Enkripsi Kode Pesanan ===\n");
                encrypt_kode_pesanan(m);
                break;

            case 7:
                printf("\n=== Enkripsi Nomor Meja (Rotate 90 Degree) ===\n");
                print_matrix_rotate90deg(m);
                break;

            case 0:
                printf("\n[ Keluar Program ]");
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
