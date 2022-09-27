#include "header.h"

int main(int argc, char *argv[]) 
{
	Mahasiswa mhs;
	int nim;
	char nama[100];
	float ipk;
	
	printf("\nMasukkan nim    : ");
	scanf("%d", &nim);
	printf("Masukkan nama    : " );
	scanf( "%s", &nama);
	printf("Masukkan ipk	 : " );
	scanf( "%f", &ipk);
	
	isiData(&mhs, nim, nama, ipk);
	
	tampilData(mhs);
	
	ubahIPK(&mhs, 3.78);
	
	printf("\nMahasiswa diubah IPK-nya : ");
	tampilData(mhs);
	
	system("pause");	
	return 0;
}
