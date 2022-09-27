
typedef char string[24];

typedef struct {
    string nama;
    string nik;
    string pekerjaan;
    int umur;
} Customer;

void init(Customer C[]);
void print_data(Customer C[]);

int find_data(Customer C[], string data);
int find_empty(Customer C[]);
