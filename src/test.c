#include <stdio.h>
#include <stdlib.h>

int main() {
    long double result = 1;
    for (int i = 1; i < 41; i++) {
        result *= i;
    }
    printf("%Lf", result);
    return 0;
}