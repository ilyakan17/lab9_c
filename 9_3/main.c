#include <stdio.h>
#include "9.h"
#define MAX_LINE_LENGTH 256

int main() {
    int linesPerPage, maxLineLength;
    char filename[MAX_LINE_LENGTH];

    printf("Enter number of string on page: ");
    scanf("%d", &linesPerPage);

    printf("Enter max length of string: ");
    scanf("%d", &maxLineLength);

    printf("Enter name of the file: ");
    scanf("%255s", filename);

    paginateFile(filename, linesPerPage, maxLineLength);

    return 0;
}
