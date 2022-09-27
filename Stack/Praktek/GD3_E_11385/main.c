#include "header.h"

int main(void) {
    int menu;

    info_type data;
    Stack s;

    init(&s);

    do {
        system("cls");
        printf("\n==== GUIDED STACK (ARRAY IMPLEMENTATION) =====\n");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Show");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                if (!is_full(s)) {
                    printf("\nInput Data : ");
                    scanf("%d", &data);
                    push(&s, data);
                    printf("\nBerhasil push data!\n");
                } else {
                    printf("\nStack sudah penuh!\n");
                }
                break;

            case 2:
                if (!is_empty(s)) {
                    printf("\nData yang di-pop : %d\n", pop(&s));
                } else {
                    printf("\nStack kosong!\n");
                }
                break;

            case 3:
                if (!is_empty(s))
                    show(s);
                else
                    printf("\nStack kosong!\n");
                break;

            case 0:
                printf("\nNama : Benidiktus Violaz Morello Anjolie");
                printf("\nNPM  : 210711385");
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
