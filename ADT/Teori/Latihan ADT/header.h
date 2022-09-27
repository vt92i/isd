typedef char string[64];

typedef struct
{
    string nama_kabupaten;
    string nama_bupati;
} Kabupaten;

typedef struct
{
    string nama_provinsi;
    string nama_gubernur;
    Kabupaten kabupaten[2];
} Provinsi;

void init_provinsi(Provinsi *provinsi);
void show_provinsi(Provinsi provinsi);
