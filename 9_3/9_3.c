#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void printPageHeader(int pageNumber) {
    printf("\n- Page %d -\n", pageNumber);
}

void printLineWithNumber(int lineNumber, const char *line) {
    printf("%d: %s", lineNumber, line);
}

void paginateFile(const char *filename, int linesPerPage, int maxLineLength) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int currentPage = 1;
    int lineCount = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        lineCount++;
        lineNumber = (lineCount - 1) % linesPerPage + 1;

        printLineWithNumber(lineNumber, line);

        if (lineNumber == linesPerPage) {
            printPageHeader(currentPage);
            currentPage++;
        }
    }

    if (lineNumber != 0) {
        printPageHeader(currentPage);
    }

    fclose(file);
}


