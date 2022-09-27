#include "header.h"

int main(void) {
    Queue q_np, q_p;
    Nasabah N;

    int menu, submenu, index;

    init(&q_np); init(&q_p);
    
    int id = 555;
    
    int total_np = 0, total_uang_np = 0;
    int total_p =0, total_uang_p = 0;
    

    do {
        system("cls");

        printf("\n==== UNGUIDED QUEUE (ARRAY IMPLEMENTATION) =====");
        printf("\n1. Masuk Antrian");
        printf("\n2. Setor");
        printf("\n3. Tampil Antrian");
        printf("\n4. Cari Data");
        
		printf("\n\n==== TUGAS QUEUE (ARRAY IMPLEMENTATION) =====");
        printf("\n5. Edit Data");
        printf("\n6. Riwayat");
        printf("\n0. Exit");
        printf("\n------------------------------------------------");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
            	printf("\nPilih Jenis Antrian\n");
            	printf("\n1. Non Prioritas");
       			printf("\n2. Prioritas");
       			printf("\n>>> ");
            	scanf("%d", &submenu);
            	
            	switch (submenu) {
            		case 1:
            			if (!is_full(q_np)) {
		                    printf("\n[ Input Data ]\n");
		                    
		                    printf("ID : %d \n", id);
		                    N.id = id;
		                    
		                    while(true) {
								printf("Nama : ");
		                    	fflush(stdin);
		                   		gets(N.nama);
		                   		
		                   		if (strlen(N.nama) == 0) continue;
		                   		if (strcmp(N.nama, "-") == 0) continue;
		                   		if (N.nama[0] == ' ') continue;
		                   		break;
							}
		                    
		                    printf("Jenis : Non Prioritas\n");
		                    strcpy(N.jenis, "Non Prioritas");
		                    
		                    while(true) {
		                    	printf("Uang : ");
		                   		scanf("%d", &N.jumlah_uang);
		                   		
		                   		if (N.jumlah_uang >= 100000) break;
							}
		
		                    enqueue(&q_np, make_nasabah(N.id, N.nama, N.jenis, N.jumlah_uang));
		                    id++;
		                    printf("\nInput data berhasil!\n");
		                    
		                } else {
		                    printf("\nQueue sudah penuh!\n");
		                }
            			break;
            			
            		case 2:
            			if (!is_full(q_p)) {
		                    printf("\n[ Input Data ]\n");
		                    
		                    printf("ID : %d \n", id);
		                    N.id = id;
		                    
		                    while(true) {
								printf("Nama : ");
		                    	fflush(stdin);
		                   		gets(N.nama);
		                   		
		                   		if (strlen(N.nama) == 0) continue;
		                   		if (strcmp(N.nama, "-") == 0) continue;
		                   		if (N.nama[0] == ' ') continue;
		                   		break;
							}
		                    
		                    printf("Jenis : Prioritas\n");
		                    strcpy(N.jenis, "Prioritas");
		                    
		                    while(true) {
		                    	printf("Uang : ");
		                   		scanf("%d", &N.jumlah_uang);
		                   		
		                   		if (N.jumlah_uang >= 1000000) break;
							}
		
		                    enqueue(&q_p, make_nasabah(N.id, N.nama, N.jenis, N.jumlah_uang));
		                    id++;
		                    printf("\nInput data berhasil!\n");
		                    
		                } else {
		                    printf("\nQueue sudah penuh!\n");
		                }
            			break;
            			
            		default:
            			printf("\nPilihan tidak valid!\n");
				}
                break;

            case 2:
				printf("\nPilih Jenis Antrian\n");
            	printf("\n1. Non Prioritas");
       			printf("\n2. Prioritas");
       			printf("\n>>> ");
            	scanf("%d", &submenu);
            	
            	switch (submenu) {
            		case 1:
            			if (!is_empty(q_np)) {
            				printf("ID %d dengan nama %s berhasil melakukan pembayaran!\n", q_np.N[q_np.head].id, q_np.N[q_np.head].nama);
            				total_np++;
            				total_uang_np += q_np.N[q_np.head].jumlah_uang;
		                    dequeue(&q_np);		                    
		                } else {
		                    printf("\nQueue kosong!\n");
		                }
            			break;
            			
            		case 2:
            			if (!is_empty(q_p)) {
            				printf("ID %d dengan nama %s berhasil melakukan pembayaran!\n", q_p.N[q_p.head].id, q_p.N[q_p.head].nama);
            				total_p++;
            				total_uang_p += q_p.N[q_p.head].jumlah_uang;
		                    dequeue(&q_p);		                    
		                } else {
		                    printf("\nQueue kosong!\n");
		                }
            			break;
            			
            		default:
            			printf("\nPilihan tidak valid!\n");
				}
            	
                break;

            case 3:
            	printf("\n\nAntrian Non Prioritas\n");
            	if (!is_empty(q_np)) print(q_np);
            	
            	printf("\n\nAntrian Prioritas\n");
            	if (!is_empty(q_p)) print(q_p);
                break;

            case 5:
                if (!is_empty(q_np) || !is_empty(q_p)) {
                    printf("\n[ Cari Data]\n");
                    printf("Input ID : ");
					scanf("%d", &N.id);

                    index = find_data_by_id(q_np, N.id);
                                        
                    if (index != -1) {
                        printf("\n[ Ubah Data ]\n");
                        
                         while(true) {
								printf("Nama : ");
		                    	fflush(stdin);
		                   		gets(N.nama);
		                   		
		                   		if (strlen(N.nama) == 0) continue;
		                   		if (strcmp(N.nama, "-") == 0) continue;
		                   		if (N.nama[0] == ' ') continue;
		                   		
		                   		break;
							}
		                    
		                    
		                while(true) {
		                    	printf("Uang : ");
		                   		scanf("%d", &N.jumlah_uang);
		                   		
		                   		if (N.jumlah_uang >= 100000) break;
							}
							
						strcpy(q_np.N[index].nama, N.nama);
						q_np.N[index].jumlah_uang =  N.jumlah_uang;
						
						printf("\n[ Data Baru ]\n");
                        printf("ID : %d\n", q_np.N[index].id);
                        printf("Nama : %s\n", q_np.N[index].nama);
                        printf("Jenis : %s\n", q_np.N[index].jenis);
                        printf("Uang : %d\n", q_np.N[index].jumlah_uang);
                        break;
                    }
                    
                    index = find_data_by_id(q_p, N.id);
                                        
                    if (index != -1) {
                    	 printf("\n[ Ubah Data ]\n");
                        
                         while(true) {
								printf("Nama : ");
		                    	fflush(stdin);
		                   		gets(N.nama);
		                   		
		                   		if (strlen(N.nama) == 0) continue;
		                   		if (strcmp(N.nama, "-") == 0) continue;
		                   		if (N.nama[0] == ' ') continue;
		                   		
		                   		break;
							}
		                    
		                    
		                while(true) {
		                    	printf("Uang : ");
		                   		scanf("%d", &N.jumlah_uang);
		                   		
		                   		if (N.jumlah_uang >= 100000) break;
							}
							
						strcpy(q_p.N[index].nama, N.nama);
						q_p.N[index].jumlah_uang =  N.jumlah_uang;
                    	
                        printf("\n[ Data Baru ]\n");
                        printf("ID : %d\n", q_p.N[index].id);
                        printf("Nama : %s\n", q_p.N[index].nama);
                        printf("Jenis : %s\n", q_p.N[index].jenis);
                        printf("Uang : %d\n", q_p.N[index].jumlah_uang);
                        break;
                    }
                                        
                    printf("\nData tidak ditemukan!\n");
                } else
                    printf("\nQueue masih kosong!\n");

                break;
                
            case 4:
                if (!is_empty(q_np) || !is_empty(q_p)) {
                    printf("\n[ Cari Data]\n");
                    printf("Input ID : ");
					scanf("%d", &N.id);

                    index = find_data_by_id(q_np, N.id);
                                        
                    if (index != -1) {
                        printf("\n[ Data Ditemukan ]\n");
                        printf("ID : %d\n", q_np.N[index].id);
                        printf("Nama : %s\n", q_np.N[index].nama);
                        printf("Jenis : %s\n", q_np.N[index].jenis);
                        printf("Uang : %d\n", q_np.N[index].jumlah_uang);
                        break;
                    }
                    
                    index = find_data_by_id(q_p, N.id);
                                        
                    if (index != -1) {
                        printf("\n[ Data Ditemukan ]\n");
                        printf("ID : %d\n", q_p.N[index].id);
                        printf("Nama : %s\n", q_p.N[index].nama);
                        printf("Jenis : %s\n", q_p.N[index].jenis);
                        printf("Uang : %d\n", q_p.N[index].jumlah_uang);
                        break;
                    }
                                        
                    printf("\nData tidak ditemukan!\n");
                } else
                    printf("\nQueue masih kosong!\n");
            	break;

			case 6:
				printf("\nRiwayat\n");
				
				printf("Total Non Prioritas : %d \n", total_np);
				printf("Total Uang Non Prioritas : %d IDR \n", total_uang_np);
				
				printf("Total Prioritas : %d \n", total_p);
				printf("Total Uang Non Prioritas : %d IDR \n", total_uang_p);
				
				printf("Total Non Prioritas + Prioritas : %d \n", total_np + total_p);
				printf("Total Non Prioritas + Prioritas : %d \n", total_uang_np + total_uang_p);
				
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
