#include "header.h"

int main(void) {


  
    


	int A[10];
	init_array(A);
	
	Stack stack_ganjil, stack_genap;
	initStack(&stack_ganjil);
	initStack(&stack_genap);
	

	int menu;

    do {
        system("cls");
        printf("\n---------- MENU QUIZ---------");
        printf("\n1. Salin ke Stack Genap dan Ganjil");
        printf("\n2. Kosongkan semua Stack");
        printf("\n3. Print semua Stack");
        
        printf("\n\n>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                copy_ganjil_genap(&stack_ganjil, &stack_genap, A);
                break;
            case 2:
//               kosongkan_semua_stack(&stuck_ganjil, &stack_genap);
                break;
                
            case 3:
            	printf("\nStack Ganjil\n");
            	show(stack_ganjil);
            	
            	printf("\nStack Genap\n");
            	show(stack_genap);
            	
            	break;
        }
			getch();
    } while (menu != 0);
    return 0;
}
