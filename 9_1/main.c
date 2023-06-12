#include <stdio.h>
#include <stdlib.h>
#include "9.h"

int main() {
    char filename[256];
    int n = 5;  // Значение N по умолчанию

    printf("Enter name of the file: ");
    scanf("%255s", filename);

    printf("Enter number of strings: ");
    scanf("%d", &n);

    tail(filename, n);

    return 0;
}
