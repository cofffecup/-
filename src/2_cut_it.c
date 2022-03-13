// Copyright [2022] <cofffecup>
#include <stdio.h>

int main() {
    char n[100];
    int tmp;
    fgets(n, 100, stdin);
    for (int i = 0; n[i] != '\0'; i++) {
        tmp = i;
        if (n[i] == 47 && n[i + 1] == 42) {  // 47 - "/", 42 - "*"
            do {
                i++;
                if (n[i] == '\0') {
                    i = tmp - 1;
                    break;
                }
                if (n[i] == 47 && n[i - 1] == 42 && n[i - 2] == 47 &&
                i - 2 == tmp) {
                    i = tmp - 1;
                    break;
                }
            } while (!(n[i] == 47 && n[i - 1] == 42));
            i++;
        }
        printf("%c", n[i]);
    }
    return 0;
}
