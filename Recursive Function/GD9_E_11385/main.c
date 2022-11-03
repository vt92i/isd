#include "header.h"

int main(void) {
    mahasiswa m[MAX_ARRAY], tmp;
    init(m, 0);
    int menu, index;

    do {
        system("cls");

        printf("\n==== GUIDED RECURSIVE FUNCTION =====");
        printf("\n[ Core ]");
        printf("\n1. Input Mahasiswa");
        printf("\n2. Tampil Mahasiswa\n");

        printf("\n[ Utility]");
        printf("\n3. Cari Mahasiswa");
        printf("\n4. Edit Mahasiswa");
        printf("\n5. Hapus Mahasiswa\n");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input Mahasiswa ]\n");

                index = get_empty_index(m, 0);
                if (index == -1) {
                    printf("\nData sudah penuh!\n");
                    break;
                }

                while (true) {
                    printf("Nama : ");
                    fflush(stdin);
                    gets(tmp.nama);
                    if (strlen(tmp.nama) != 0) break;
                }

                while (true) {
                    printf("NPM : ");
                    fflush(stdin);
                    gets(tmp.npm);
                    if (strlen(tmp.npm) != 0) break;
                }

                while (true) {
                    printf("IPK : ");
                    scanf("%f", &tmp.ipk);
                    if (tmp.ipk > 0) break;
                }

                m[index] = tmp;
                printf("\nData berhasil disimpan!\n");
                break;

            case 2:
                printf("\n[ Tampil Mahasiswa ]\n");
                if (is_empty(m, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }
                print_all(m, 0);
                break;

            case 3:
                printf("\n[ Cari Mahasiswa ]\n");
                if (is_empty(m, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }

                while (true) {
                    printf("NPM : ");
                    fflush(stdin);
                    gets(tmp.npm);
                    if (strlen(tmp.npm) != 0) break;
                }

                index = find(m, 0, tmp.npm);
                if (index == -1) break;
                printf("\n[ Mahasiswa %d ]", index + 1);
                printf("\nNama : %s", m[index].nama);
                printf("\nNPM : %s", m[index].npm);
                printf("\nIPK : %.2f\n", m[index].ipk);
                break;

            case 4:
                printf("\n[ Edit Mahasiswa ]\n");
                if (is_empty(m, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }

                while (true) {
                    printf("NPM : ");
                    fflush(stdin);
                    gets(tmp.npm);
                    if (strlen(tmp.npm) != 0) break;
                }

                index = find(m, 0, tmp.npm);
                if (index == -1) break;

                printf("\n");
                while (true) {
                    printf("Nama : ");
                    fflush(stdin);
                    gets(m[index].nama);
                    if (strlen(m[index].nama) != 0) break;
                }

                while (true) {
                    printf("IPK : ");
                    scanf("%f", &m[index].ipk);
                    if (m[index].ipk > 0) break;
                }

                printf("\nData berhasil disimpan!\n");
                break;

            case 5:
                printf("\n[ Hapus Mahasiswa ]\n");
                if (is_empty(m, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }

                while (true) {
                    printf("NPM : ");
                    fflush(stdin);
                    gets(tmp.npm);
                    if (strlen(tmp.npm) != 0) break;
                }

                index = find(m, 0, tmp.npm);
                if (index == -1) break;

                strcpy(m[index].nama, "");
                strcpy(m[index].npm, "");
                m[index].ipk = 0;

                printf("\nData berhasil dihapus!\n");
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
