#include <stdio.h>
#define STRING_LENGTH 24

int main(void) {
    char str[STRING_LENGTH];
    int number;

    printf("Enter a string: ");
    fgets(str, STRING_LENGTH, stdin);
    printf("You entered: %s \n", str);

    printf("Enter a number: ");
    fgets(str, STRING_LENGTH, stdin);
    sscanf(str, "%d", &number);
    printf("You entered: %d \n", number);

    return 0;
}
