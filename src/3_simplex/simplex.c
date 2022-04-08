#include "simplex.h"

int main() {
    int rows = 0, columns = 0;  // количество уравнений и переменных в каноническом виде
    arr_size_input(&rows, &columns);
    int *basis = malloc((rows - 1) * sizeof(int));
    for (int i = 0; i < rows - 1; ++i)
        basis[i] = columns + 1 + i;
    columns += rows;

    float **tabl = NULL;
    tabl = malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; ++i)
        tabl[i] = malloc(columns * sizeof(float));

    tabl_input(tabl, rows, columns);
    print_tabl(tabl, rows, columns);
    int flag = 0;
    do {
        change_tabl(tabl, rows, columns, &flag, basis);
        if (flag == 1)
            break;
        print_tabl(tabl, rows, columns);
    } while (flag != 1);

    free_memory(tabl, basis, rows);
    return 0;
}

void arr_size_input(int *rows, int *columns) {
    printf("Введите количество переменных: ");
    scanf("%d", columns);
    printf("Введите количество уравнений, задающих условия: ");
    scanf("%d", rows);
}

void tabl_input(float **tabl, int rows, int columns) {
    for (int i = 1; i <= rows; ++i) {
        if (i != rows) {
            printf("\nВведите для %d уравнения\n", i);
            for (int j = 0; j < columns; ++j) {
                if (j > 0 && j < columns)
                    printf("коэффициент при x%d: ", j);
                if (j == 0)
                    printf("свободный член ограничения: ");
                scanf("%f", &tabl[i - 1][j]);
            }
        } 
        if (i == rows) {
            printf("\nВведите коэффициенты для уравнения Zmax ");
            for (int j = 0; j < columns; ++j) {
                if (j > 0 && j <= columns - rows) {
                    printf("при х%d: ", j);
                    scanf("%f", &tabl[i - 1][j]);
                    tabl[i - 1][j] *= -1;
                } else {
                    tabl[i - 1][j] = 0;
                }
            }
        }
    }
    printf("\n");
}

void print_tabl(float **tabl, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (tabl[i][j] == (int)tabl[i][j]) {
                if (j != columns - 1)
                    printf("%5.0f | ", tabl[i][j]);
                else
                    printf("%5.0f\n", tabl[i][j]);
            } else {
                if (j != columns - 1)
                    printf("%5.1f | ", tabl[i][j]);
                else
                    printf("%5.1f\n", tabl[i][j]);
            }
        }
    }
    printf("\n-------------------------\n");
}

void free_memory(float **tabl, int *basis, int rows) {
    if (tabl != NULL) {
        for ( int i = 0; i < rows; i++) {
            free(tabl[i]);
        }
        free(tabl);
    }
    if (basis != NULL)
        free(basis);
}

void change_tabl(float **tabl, int rows, int columns, int *flag, int *basis) {
    int x = 0, y = 0;
    float min = 9999, res = 0;

    for (int i = rows - 1, j = 0; j < columns; ++j) {
            if (tabl[i][j] < min) {
                min = tabl[i][j];
                x = j;
            }
    }
    min = 9999;
    for (int i = 0; i < rows - 1; ++i) {
        if (tabl[i][x] > 0 && tabl[i][0] / tabl[i][x] < min) {
            min = tabl[i][0] / tabl[i][x];
            y = i;
        }
    }

    res = tabl[y][x];
    basis[y] = x;
    float tmp[rows][columns];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            tmp[i][j] = tabl[i][j];      
        }
    }

    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (i != y) {
                tabl[i][j] = (tmp[i][j] * res - tmp[i][x]*tmp[y][j])/res;
            }
            if (i == y) {
                tabl[i][j] = tmp[i][j] / res;
            }

            if (tabl[i][j] == -0.0 ) {
                tabl[i][j] = 0;
            }
        }
    }
    int count = 0;
    for (int i = rows - 1, j = 0; j < columns; ++j) {
        if (tmp[i][j] >= 0)
            count++;
    }
    if (count == columns)
        *flag = 1;
    else
        *flag = 0;
    printf("res = %.1f\nстрока = %d, столбец = %d\n\n", res, x, y+1);
    printf("Переменные в базисе следующей таблицы: ");
    for (int i = 0; i < rows - 1; ++i) {
        printf("x%d ", basis[i]);
    }
    printf("\n\n");
}