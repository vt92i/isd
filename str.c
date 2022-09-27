#include <stdio.h>

char* return_string(char str[]) {
    return str;
}

int main(void) {
    char* str = return_string("Hello World!");
    printf("%s\n", str);

    printf("%s\n", return_string("Hello World!"));

    return 0;
}
