#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x;
    int *x_ptr;

    printf("\nMasukan value untuk variable X : ");
    scanf("%d", &x);

    x_ptr = &x;
    printf("\nAlamat dari variable X adalah [ %x ] dan valuenya adalah [ %d ]\n", x_ptr, *x_ptr);

    return 0;
}
