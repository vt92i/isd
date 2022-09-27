#include "header.h"

int main(void) {
	
	Index index;
    Meja m[ROW][COL];
	init_meja(m);

	string nama_pelanggan, nomor_meja;
	int kode_pesanan;
    
	int menu;

    do {
        system("cls");
        printf("\n==== UNGUIDED MATRIX ====\n");
        printf("\nNama : Benidiktus Violaz Morello Anjolie");
        printf("\nNPM  : 210711385");
        printf("\n1. Input Data");
        printf("\n2. Edit Data");
        printf("\n3. Cari Data");
        printf("\n4. Tampil Data");
        printf("\n5. Hapus Data");
        printf("\n6. Enkripsi Nomor Meja");
        printf("\n7. Enkripsi Kode Pesanan");
      	printf("\n0. Keluar");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n=== Input Data ===\n");

                while (true) {
                    printf("Index I : ");
                    scanf("%d", &index.i);

                    if (index.i < 0)
                        printf("Index tidak boleh kurang dari 0!\n\n");
                    else if (index.i >= ROW)
                        printf("Index tidak boleh lebih dari %d!\n\n", ROW - 1);
                    else
                        break;
                }

                while (true) {
                    printf("Index J : ");
                    scanf("%d", &index.j);

                    if (index.j < 0)
                        printf("Index tidak boleh kurang dari 0!\n\n");
                    else if (index.j >= COL)
                        printf("Index tidak boleh lebih dari %d!\n\n", COL - 1);
                    else
                        break;
                }

                if (is_filled(m, index)) {
                    printf("\nMeja sudah terisi!\n");
                    break;
                } else {
                	while(true) {
                		printf("\nInput Nama Pelanggan : "); fflush(stdin); gets(m[index.i][index.j].nama_pelanggan);
                		
                		if (strlen(m[index.i][index.j].nama_pelanggan) == 0) continue;
                		if (strcmpi(m[index.i][index.j].nama_pelanggan, "-") == 0) continue;
                		
                		break;
                		
					}
					
					while(true) {
						printf("\nInput Nomor Meja : "); fflush(stdin); gets(m[index.i][index.j].nomor_meja);
						
						if (strlen(m[index.i][index.j].nomor_meja) < 3) continue;
						
						break;						
					}
                    
                    while(true) {
                    	printf("\nInput Kode Pesanan : "); scanf("%d", &m[index.i][index.j].kode_pesanan);
                    	
                    	if(m[index.i][index.j].kode_pesanan < 0) continue;
                    	
                    	break;
					}
                    
                    
                    printf("\nInput Data berhasil!\n");                  
                }
                break;

            case 2:
      			  printf("\n=== Edit Data ===\n");

 				while (true) {
                    printf("Index I : ");
                    scanf("%d", &index.i);

                    if (index.i < 0)
                        printf("Index tidak boleh kurang dari 0!\n\n");
                    else if (index.i >= ROW)
                        printf("Index tidak boleh lebih dari %d!\n\n", ROW - 1);
                    else
                        break;
                }

                while (true) {
                    printf("Index J : ");
                    scanf("%d", &index.j);

                    if (index.j < 0)
                        printf("Index tidak boleh kurang dari 0!\n\n");
                    else if (index.j >= COL)
                        printf("Index tidak boleh lebih dari %d!\n\n", COL - 1);
                    else
                        break;
                }
                
                 if (!is_filled(m, index)) {
                    printf("\nMeja belum input!\n");
                    break;
                }
                
                    printf("\nInput Nama Pelanggan : "); fflush(stdin); gets(m[index.i][index.j].nama_pelanggan);
                    printf("\nInput Nomor Meja : "); fflush(stdin); gets(m[index.i][index.j].nomor_meja);
                    printf("\nInput Kode Pesanan : "); scanf("%d", &m[index.i][index.j].kode_pesanan);
                    printf("\nInput Data berhasil!\n"); 
                
                break;

            case 3:
      			  printf("\n=== Cari Data ===\n");

                printf("\nInput Nomor Meja : "); fflush(stdin); gets(nomor_meja);
                
                index = find_data(m, nomor_meja);

                if (index.i == -1) {
                    printf("\nData tidak ditemukan!\n");
                } else {
                    printf("\nNama Pelanggan : %s \n", m[index.i][index.j].nama_pelanggan);
                    printf("\nNomor Meja : %s \n", m[index.i][index.j].nomor_meja);
                    printf("\nKode Pesanan : %d \n", m[index.i][index.j].kode_pesanan);
                }
                break;

			case 4:
				printf("\n=== Print Data ===\n");
                print_meja(m);
                break;
                
            case 5:
            	printf("\n=== Hapus Data ===\n");
            	
            	printf("\nInput Nama Pelanggan : "); fflush(stdin); gets(nama_pelanggan);
            	
            	index = find_data_by_name(m, nama_pelanggan);
            	
            	if (index.i == -1) {
                    printf("\nData tidak ditemukan!\n");
                } else {
                    m[index.i][index.j] = create_meja("-", "-", 0);
                    printf("\nData berhasil dihapus!\n");
                }
            	break;

            case 0:
                printf("\nKeluar Program");
                printf("\nNama : Benidiktus Violaz Morello Anjolie");
                printf("\nNPM  : 210711385");
                break;

            default:
                printf("\nMenu tidak tersedia!\n");
                break;
        }
        getch();
    } while (menu != 0);

    return 0;
}
