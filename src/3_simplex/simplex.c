#include "simplex.h"

int main() {
    int rows = 0, columns = 0;  // количество уравнений и переменных в каноническом виде
    arr_size_input(&rows, &columns);
    
    return 0;
}

void arr_size_input(int *rows, int *columns) {
    printf("Введите количество переменных: ");
    scanf("%d", rows);
    printf("\nВведите количество уравнений с учетом Zmax в канонической форме: ");
    scanf("%d", columns);
    *rows += 2;
}