#include "header.h"

int main(int argc, char *argv[]) 
{
	Mahasiswa mhs[3]; 
	int nim;
	char nama[100];
	float ipk;
	
	int i;
	
	for (i=0; i<=2; i++)
	{
		printf("\n\nMasukkan NIM  : ");scanf("%d",&nim);
		printf("Masukkan Nama : " );scanf( "%s",&nama);
		printf("Masukkan Ipk  : " );scanf( "%f",&ipk);
		isiData(&mhs[i],nim,nama,ipk);
	}

	tampilData(mhs);

	system("pause");	
	return 0;
}
