#include <stdio.h>
#include "9.h"
#define MAX_LINE_LENGTH 256

int main() {
    char filename1[MAX_LINE_LENGTH];
    char filename2[MAX_LINE_LENGTH];

    printf("Enter name of first file: ");
    scanf("%255s", filename1);

    printf("Enter name of second file: ");
    scanf("%255s", filename2);

    interleaveFiles(filename1, filename2);
    return 0;
}
