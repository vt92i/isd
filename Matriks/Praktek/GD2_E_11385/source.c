#include "header.h"

void init_matriks(Data data[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            data[i][j].value = -1;
            strcpy(data[i][j].status, "-");
        }
    }
}

void print_matriks(Data data[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d\t", data[i][j].value);
        }
        printf("\n");
    }
}

Data create_data(int value, char status[]) {
    Data data;
    data.value = value;
    strcpy(data.status, status);
    return data;
}

Index find_data(Data data[ROW][COL], int value) {
    int i, j;
    Index index;
    index.i = -1;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (data[i][j].value == value) {
                index.i = i;
                index.j = j;
                return index;
            }
        }
    }

    return index;
}

bool is_filled(Data data[ROW][COL], Index index) {
    if (strcmpi(data[index.i][index.j].status, "-")) return true;
    return false;
}
