#include "header.h"

void init(perusahaan p[], int index) {
    void init_stockprice(perusahaan * p, int index) {
        if (index > 7 - 1) return;
        p->stockprice[index] = 0;
        init_stockprice(p, index + 1);
    }

    if (index > MAX_ARRAY - 1) return;
    strcpy(p[index].kode, "");
    strcpy(p[index].status, "");
    strcpy(p[index].nama, "");
    init_stockprice(&p[index], 0);

    init(p, index + 1);
}

void print_all(perusahaan p[], int index) {
    if (index > MAX_ARRAY - 1) return;
    if (strcmpi(p[index].kode, "") != 0) {
        void print_stockprice(perusahaan p, int index) {
            if (index > 7 - 1) return;
            printf("\tHari %d : %.0f IDR \n", index + 1, p.stockprice[index]);
            print_stockprice(p, index + 1);
        }

        printf("\n[ Perusahaan %d ]", index + 1);
        printf("\nKode : %s", p[index].kode);
        printf("\nStatus : %s", p[index].status);
        printf("\nNama : %s", p[index].nama);
        printf("\nHistory Stock Price : \n");
        print_stockprice(p[index], 0);
    }

    print_all(p, index + 1);
}

int get_empty_index(perusahaan p[], int index) {
    if (index > MAX_ARRAY - 1) return -1;
    if (strcmpi(p[index].kode, "") == 0) return index;
    return get_empty_index(p, index + 1);
}

int is_empty(perusahaan p[], int index) {
    if (index > MAX_ARRAY - 1) return 1;
    if (strcmpi(p[index].kode, "") != 0) return 0;
    return is_empty(p, index + 1);
}

int find(perusahaan p[], int index, string kode) {
    if (index > MAX_ARRAY - 1) return -1;
    if (strcmpi(p[index].kode, kode) == 0) return index;
    return find(p, index + 1, kode);
}

void input_stockprice(perusahaan *p, int index) {
    if (index > 7 - 1) return;
    while (true) {
        printf("Hari %d : ", index + 1);
        scanf("%f", &p->stockprice[index]);
        if (p->stockprice[index] > 0) break;
    }
    input_stockprice(p, index + 1);
}

void statistik_satu_hari(perusahaan p[], int index, int day, perusahaan q[]) {
    if (index > MAX_ARRAY - 1) return;
    if (index == 0) init(q, 0);
    if (strcmpi(p[index].kode, "") != 0) {
        void print_stockprice(perusahaan p, int index) {
            if (index > 7 - 1) return;
            if (index + 1 == day) {
                printf("\tHari %d : %.0f IDR \n", index + 1, p.stockprice[index]);

                q[0].stockprice[index] = q[0].stockprice[index] == 0 ? INT_MIN : q[0].stockprice[index];
                q[1].stockprice[index] = q[1].stockprice[index] == 0 ? INT_MAX : q[1].stockprice[index];

                q[0] = p.stockprice[index] >= q[0].stockprice[index] ? p : q[0];
                q[1] = p.stockprice[index] <= q[1].stockprice[index] ? p : q[1];
            }
            print_stockprice(p, index + 1);
        }
        printf("\n[ Perusahaan %d ]", index + 1);
        printf("\nKode : %s", p[index].kode);
        printf("\nStatus : %s", p[index].status);
        printf("\nNama : %s", p[index].nama);
        printf("\nHistory Stock Price %d : \n", day);
        print_stockprice(p[index], 0);
    }
    if (index + 1 == MAX_ARRAY) {
        printf("\n[ Saham Termahal ]");
        printf("\nNama Perusahaan : %s", q[0].nama);
        printf("\nHarga Saham : %.0f IDR \n", q[0].stockprice[day - 1]);

        printf("\n[ Saham Termurah ]");
        printf("\nNama Perusahaan : %s", q[1].nama);
        printf("\nHarga Saham : %.0f IDR", q[1].stockprice[day - 1]);
    }
    statistik_satu_hari(p, index + 1, day, q);
}

void simulasi(int n, int x, int d) {
    if (x > 15) return;

    int val;
    float min_val, max_val;

    min_val = (-10.0f / 100.0f) * (float)n;
    max_val = (15.0f / 100.0f) * (float)n;
    val = (rand() % ((int)round(max_val) - (int)round(min_val))) + (int)round(min_val);
    if (x == d) {
        min_val = (-50.0f / 100.0f) * (float)n;
        max_val = (-30.0f / 100.0f) * (float)n;
        val = (rand() % ((int)round(max_val) - (int)round(min_val))) + (int)round(min_val);
        printf("\n[ Market Crash Day %d! ]\n", d);
        printf("[%d] - [ Start: %d ] - [ Change: %d (%.2f percent) ] - [ End: %d ] \n\n", x, n, val, 100.0f * ((float)val / (float)n), n + val);
    } else
        printf("[%d] - [ Start: %d ] - [ Change: %d (%.2f percent) ] - [ End: %d ] \n", x, n, val, 100.0f * ((float)val / (float)n), n + val);

    simulasi(n + val, x + 1, d);
}

void best_worst(perusahaan p) {
    struct stockprice {
        float value;
        int day;
    } best, worst;

    void print_stockprice(perusahaan p, int index) {
        if (index > 7 - 1) return;
        if (index == 0) {
            best.value = p.stockprice[index];
            best.day = index + 1;
            worst.value = p.stockprice[index];
            worst.day = index + 1;
        }

        if (p.stockprice[index] > best.value) {
            best.value = p.stockprice[index];
            best.day = index + 1;
        }

        if (p.stockprice[index] < worst.value) {
            worst.value = p.stockprice[index];
            worst.day = index + 1;
        }

        print_stockprice(p, index + 1);
    }
    print_stockprice(p, 0);

    printf("\nStatus : %s", p.status);
    printf("\nNama : %s", p.nama);

    printf("\n\n[ Best Day - Highest Stock Price ]");
    printf("\nHari : %d", best.day);
    printf("\nHarga Saham : %.0f IDR", best.value);

    printf("\n\n[ Worst Day - Lowest Stock Price ]");
    printf("\nHari : %d", worst.day);
    printf("\nHarga Saham : %.0f IDR", worst.value);
}

void sort_by_status(perusahaan p[], perusahaan pq[], perusahaan pk[], int index) {
    if (index > MAX_ARRAY - 1) return;
    if (index == 0) {
        init(pq, 0);
        init(pk, 0);
    }

    if (strcmpi(p[index].kode, "") != 0) {
        pq[get_empty_index(pq, 0)] = strcmpi(p[index].status, "Umum") == 0 ? p[index] : pq[get_empty_index(pq, 0)];
        pk[get_empty_index(pk, 0)] = strcmpi(p[index].status, "Swasta") == 0 ? p[index] : pk[get_empty_index(pk, 0)];
    }

    sort_by_status(p, pq, pk, index + 1);
}
