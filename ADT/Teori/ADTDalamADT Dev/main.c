#include "header.h"

int main(int argc, char *argv[]) 
{
	Mahasiswa mhs;
	int nim;
	char nama[100];
	float ipk;
	
	Prodi inf;
	char kodeprodi[10];
	char namaprodi[20];
	
	printf("\nMasukkan Kode Prodi : ");scanf("%s",&kodeprodi);
	printf("\nMasukkan Nama Prodi : ");scanf("%s",&namaprodi);
	printf("     Masukkan NIM Mahasiswa: ");scanf("%d",&nim);
	printf("     Masukkan Nama Mahasiswa : " );scanf( "%s",&nama);
	printf("     Masukkan Ipk Mahasiswa : " );scanf( "%f",&ipk);
	isiDataMhs(&mhs,nim,nama,ipk);
	isiDataProdi(&inf,kodeprodi,namaprodi,mhs);
	
	tampilDataProdi(inf);
	
	system("pause");	
	return 0;
}
