#include "header.h"

void init(mahasiswa m[], int index) {
    if (index > MAX_ARRAY - 1) return;

    strcpy(m[index].nama, "");
    strcpy(m[index].npm, "");
    m[index].ipk = 0;

    init(m, index + 1);
}

void print_all(mahasiswa m[], int index) {
    if (index > MAX_ARRAY - 1) return;
    if (strcmpi(m[index].npm, "") != 0) {
        printf("\n[ Mahasiswa %d ]", index + 1);
        printf("\nNama : %s", m[index].nama);
        printf("\nNPM : %s", m[index].npm);
        printf("\nIPK : %.2f\n", m[index].ipk);
    }

    print_all(m, index + 1);
}

int get_empty_index(mahasiswa m[], int index) {
    if (index > MAX_ARRAY - 1) return -1;
    if (strcmpi(m[index].npm, "") == 0) return index;
    return get_empty_index(m, index + 1);
}

int is_empty(mahasiswa m[], int index) {
    if (index > MAX_ARRAY - 1) return 1;
    if (strcmpi(m[index].npm, "") != 0) return 0;
    return is_empty(m, index + 1);
}

int find(mahasiswa m[], int index, string npm) {
    if (index > MAX_ARRAY - 1) return -1;
    if (strcmpi(m[index].npm, npm) == 0) return index;
    return find(m, index + 1, npm);
}
