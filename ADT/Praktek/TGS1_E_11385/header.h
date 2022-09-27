#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef char string[24];

typedef struct {
    string nama;
    string rekening;
} Bank;

typedef struct {
    string nama;
    string nik;
    string pekerjaan;
    int umur;
    Bank bank[2];
} Customer;

void init(Customer C[]);
void print_data(Customer C[]);

Customer make_customer(string nama, string nik, string pekerjaan, int umur);
Customer edit_customer(string nama, string nik, string pekerjaan, int umur);
Customer delete_customer();

Bank make_bank(string nama, string rekening);
Bank edit_bank(string nama, string rekening);
Bank delete_bank();

int find_data(Customer C[], string data);
int find_empty(Customer C[]);
