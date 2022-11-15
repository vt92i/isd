#include <conio.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY 5
typedef char string[64];

typedef struct perusahaan {
    string kode, status, nama;
    float stockprice[7];
} perusahaan;

void init(perusahaan p[], int index);
void print_all(perusahaan p[], int index);

int get_empty_index(perusahaan p[], int index);
int is_empty(perusahaan p[], int index);

int find(perusahaan p[], int index, string kode);

void input_stockprice(perusahaan *p, int index);

void statistik_satu_hari(perusahaan p[], int index, int day, perusahaan q[]);
void simulasi(int n, int x, int d);

void best_worst(perusahaan p);
void sort_by_status(perusahaan p[], perusahaan pq[], perusahaan pk[], int index);
