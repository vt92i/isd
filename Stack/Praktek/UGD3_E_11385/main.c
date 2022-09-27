#include "header.h"

int main(void) {
    int menu;

    Stack s;
    Kamar k;

    int is_initialized = 0;

    do {
        system("cls");
        printf("\n==== UNGUIDED STACK (ARRAY IMPLEMENTATION) =====\n");
        printf("\n1. Init Data");
        printf("\n2. Input Data");
        printf("\n3. Ubah Data");
        printf("\n4. Delete Data");
        printf("\n5. Show Data");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
            	if (!is_initialized) {
            		init(&s);
            		is_initialized = 1;
            		printf("\nInit berhasil!\n");
				} else 
            		printf("\nStack sudah init!\n");
                break;

            case 2:
            	if (!is_initialized) {
            		printf("\nBelum init!\n");
            		break;
				}
				
                if (!is_full(s)) {
                	printf("\n");
                	
                	while(true) {
                		printf("Input Nama Penghuni : "); fflush(stdin); gets(k.nama_penghuni);
                		
                		if (strlen(k.nama_penghuni) != 0) break;
					}
                	
                    while(true) {
                    	printf("Input Kode Kamar : "); fflush(stdin); gets(k.kode_kamar);
                    	
                    	if (strlen(k.kode_kamar) != 0) break;
					}
                    
                    while(true) {
                    	printf("Input Kelas Kamar : "); fflush(stdin); gets(k.kelas_kamar);
                    	
                    	if (strcmp(k.kelas_kamar, "Deluxe") == 0 || strcmp(k.kelas_kamar, "Superior") == 0 || strcmp(k.kelas_kamar, "Standard") == 0) break;
                	}
					
					while(true) {
						printf("Input Lama Penyewaan (hari) : "); scanf("%d", &k.lama_penyewaan);
						
						if (k.lama_penyewaan > 0) break;
					}
					
					push(&s, k);				
                    printf("\nBerhasil push data!\n");
                } else {
                    printf("\nStack sudah penuh!\n");
                }
                break;

            case 3:
            	if (!is_initialized) {
            		printf("\nBelum init!\n");
            		break;
				}
				
                if (!is_empty(s)) {
                	printf("\n");
                	
                    while(true) {
                    	printf("Input Kode Kamar : "); fflush(stdin); gets(k.kode_kamar);
                    	
                    	if (strlen(k.kode_kamar) != 0) break;
					}
					
					int index = find_kamar_by_kode_kamar(s, k.kode_kamar);
					if (index != -1) {
						printf("\n");
	                	while(true) {
	                		printf("Input Nama Penghuni : "); fflush(stdin); gets(s.kamar[index].nama_penghuni);
	                		
	                		if (strlen(k.nama_penghuni) != 0) break;
						}
	                	
	                    while(true) {
	                    	printf("Input Kode Kamar : "); fflush(stdin); gets(s.kamar[index].kode_kamar);
	                    	
	                    	if (strlen(k.kode_kamar) != 0) break;
						}
	                    
	                    while(true) {
	                    	printf("Input Kelas Kamar : "); fflush(stdin); gets(s.kamar[index].kelas_kamar);
	                    	
	                    	if (strcmp(s.kamar[index].kelas_kamar, "Deluxe") == 0 || strcmp(s.kamar[index].kelas_kamar, "Superior") == 0 || strcmp(s.kamar[index].kelas_kamar, "Standard") == 0) break;
	                	}
						
						while(true) {
							printf("Input Lama Penyewaan (hari) : "); scanf("%d", &s.kamar[index].lama_penyewaan);
							
							if (s.kamar[index].lama_penyewaan > 0) break;
						}
						
                    printf("\nBerhasil ubah data!\n");
					} else {
						printf("\nKamar tidak ditemukan!\n");
					}
					
                } else
                    printf("\nStack kosong!\n");
                break;
            
            case 4:
            	if (!is_initialized) {
            		printf("\nBelum init!\n");
            		break;
				}
				
            	if (!is_empty(s)) {
					k = pop(&s);
			    	printf("[ Data Yang Di POP ] \n");
			    	printf("Nama Penghuni : %s \n", k.nama_penghuni);
			    	printf("Kode Kamar : %s \n", k.kode_kamar);
			    	printf("Kelas Kamar : %s \n", k.kelas_kamar);
			    	printf("Lama Penyewaan : %d hari \n", k.lama_penyewaan);	
				} else {
					printf("\nStack kosong!\n");
				}
            	
            	break;

			case 5:
            	if (!is_initialized) {
            		printf("\nBelum init!\n");
            		break;
				}
				
				printf("\n[ Show Data ]\n");
                if (!is_empty(s))
                    show(s);
                else
                    printf("\nStack kosong!\n");
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
