#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void arr_size_input(int *rows, int *columns);
void tabl_input(float **tabl, int rows, int columns);
void print_tabl(float **tabl, int rows, int columns);
void free_memory(float **tabl, int *basis, int rows);
void change_tabl(float **tabl, int rows, int columns, int *flag, int *basis);