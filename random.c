#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void random(int n, int x) {
    if (x > 24) return;

    int val;
    float min_val, max_val;
    min_val = (-10.0f / 100.0f) * (float)n;
    max_val = (10.0f / 100.0f) * (float)n;
    val = (rand() % ((int)max_val - (int)min_val)) + (int)min_val;

    printf("[%d] - [ Start: %d ] - [ Change: %d (%.2f%) ] - [ End: %d ] \n", x, n, val, 100.0f * ((float)val / (float)n), n + val);

    random(n + val, x + 1);
}

int main(void) {
    int n = 1000;

    srand(time(NULL));
    random(n, 1);

    return 0;
}
