#include "stdio.h"

int raise(int x, int y) {
    if (y == 0) return 1;
    return x * raise(x, y - 1);
}

int fib(int n) {
    if (1 >= n) return n;
    return fib(n - 1) + fib(n - 2);
}

void print_fib(int n) {
    if (n == 0) return;
    print_fib(n - 1);
    printf("%d ", fib(n));
}

int main(void) {
    int x, y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("%d\n\n", raise(x, y));

    int n;
    printf("Enter fib: ");
    scanf("%d", &n);
    printf("%d\n", fib(n));

    print_fib(n);

    return 0;
}
