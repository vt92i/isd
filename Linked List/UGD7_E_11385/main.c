#include "header.h"

int main(void) {
    List L;
    address P, Q;

    Data D;

    int menu, submenu, number;
    int counter = 1;
    int i = 1;

    init_empty(&L);

    do {
        system("cls");

        printf("\n\n==== Trans Jogja =====");
        printf("\n1. Show Routes");
        printf("\n2. Add Stop");
        printf("\n3. Delete Stop");
        printf("\n4. Sort Route");
        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Show Routes ]\n");
                print_list(L);
                break;

            case 2:
                printf("\n[ Add Stop ]\n");

                counter = 1;
                printf("[0]\n");
                for (P = L.first; P != NULL; P = P->next) {
                    printf("[%d] %s : %d Minutes - %.0f Km \n", counter, P->data.stop, P->data.minutes, P->data.distance);
                    counter++;
                }
                printf("[%d]\n", counter);

                printf("\nInput Number : ");
                scanf("%d", &number);

                if (!(number >= 0 && number <= counter)) break;

                printf("Nama Stop : ");
                fflush(stdin);
                gets(D.stop);
                printf("Minutes : ");
                scanf("%d", &D.minutes);
                printf("Distance : ");
                scanf("%f", &D.distance);
                P = allocate_data(D);

                if (number == 0) {
                    insert_first(&L, P);
                    break;
                }

                if (number == counter) {
                    insert_last(&L, P);
                    break;
                }

                i = 1;
                for (P = L.first; P != NULL; P = P->next) {
                    if (i == number) break;
                    i++;
                }

                Q = allocate_data(D);
                insert_after(P, Q);
                break;

            case 3:
                printf("\n[ Delete Stop ]\n");

                printf("\n1. Delete All");
                printf("\n2. Delete Specific");

                printf("\n>>> ");
                scanf("%d", &submenu);

                switch (submenu) {
                    case 1:
                        if (is_empty(L)) {
                            printf("List kosong!\n");
                            break;
                        }

                        while (!is_empty(L))
                            delete_last(&L);
                        break;

                    case 2:
                        if (is_empty(L)) {
                            printf("List kosong!\n");
                            break;
                        }

                        counter = 1;
                        for (P = L.first; P != NULL; P = P->next) {
                            printf("%d. %s : %d Minutes - %.0f Km \n", counter, P->data.stop, P->data.minutes, P->data.distance);
                            counter++;
                        }

                        printf("\nInput Number : ");
                        scanf("%d", &number);

                        if (!(number >= 1 && number <= counter)) break;

                        i = 1;
                        for (P = L.first; P != NULL; P = P->next) {
                            if (i == number) {
                                delete_at(&L, P);
                                break;
                            }
                            i++;
                        }
                        break;

                    default:
                        break;
                }

                break;

            case 4:
                if (is_empty(L)) {
                    printf("List kosong!\n");
                    break;
                }

                printf("\n1. Sort by Time");
                printf("\n2. Sort by Distance");

                printf("\n>>> ");
                scanf("%d", &submenu);

                switch (submenu) {
                    case 1:
                        sort_time(&L);
                        break;

                    case 2:
                        sort_distance(&L);
                        break;

                    default:
                        break;
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
