#include "simplex.h"

int main() {
    int rows = 0, columns = 0;  // количество уравнений и переменных в каноническом виде
    arr_size_input(&rows, &columns);

    int **tabl = NULL;
    tabl = malloc(columns * sizeof(int*));
    for (int i = 0; i < columns; ++i)
        tabl[i] = malloc(rows * sizeof(int));

    tabl_input(tabl, rows, columns);
    print_tabl(tabl, rows, columns);
    int flag = 0;
    do {
        change_tabl(tabl, rows, columns, &flag);
        print_tabl(tabl, rows, columns);
    } while (flag == 0);

    free_memory(tabl, columns);
    return 0;
}

void arr_size_input(int *rows, int *columns) {
    printf("Введите количество переменных: ");
    scanf("%d", rows);
    printf("Введите количество уравнений с учетом Zmax в канонической форме: ");
    scanf("%d", columns);
    *rows += *columns;
}

void tabl_input(int **tabl, int rows, int columns) {
    for (int i = 1; i <= columns; ++i) {
        if (i != columns) {
            printf("\nВведите для %d уравнения\n", i);
            for (int j = 0; j < rows; ++j) {
                if (j > 0 && j < rows)
                    printf("коэффициент при x%d: ", j);
                if (j == 0)
                    printf("свободный член ограничения: ");
                scanf("%d", &tabl[i - 1][j]);
            }
        } 
        if (i == columns) {
            printf("\nВведите коэффициенты для уравнения Zmax ");
            for (int j = 0; j < rows; ++j) {
                if (j > 0 && j <= rows - columns) {
                    printf("при х%d: ", j);
                    scanf("%d", &tabl[i - 1][j]);
                } else {
                    tabl[i - 1][j] = 0;
                }
            }
        }
    }
}

void print_tabl(int **tabl, int rows, int columns) {
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (j != rows - 1)
                printf("%5d | ", tabl[i][j]);
            else
                printf("%5d\n", tabl[i][j]);
        }
    }
    printf("\n-------------------------\n");
}

void free_memory(int **tabl, int columns) {
    for (int i = 0; i < columns; ++i) {
        if (tabl[i] != NULL)
            free(tabl[i]);
    }
    if (tabl != NULL)
        free(tabl);
}

void change_tabl(int **tabl, int rows, int columns, int *flag) {

}