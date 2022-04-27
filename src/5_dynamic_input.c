#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    int len = 0;
    char *s = (char*) malloc(sizeof(char));
    while (scanf("%c", &c) == 1 && c != '\n') {
        s = (char*) realloc(s, (len + 1) * sizeof(char));
        s[(len)++] = c;
    }
    puts(s);
    free(s);
    return 0;
}