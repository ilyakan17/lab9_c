#include <stdio.h>

#define MAX_LINE_LENGTH 256

void interleaveFiles(const char *filename1, const char *filename2) {
    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("File open error.\n");
        return;
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];

    int eof1 = 0;
    int eof2 = 0;

    while (!eof1 || !eof2) {
        if (!eof1 && fgets(line1, sizeof(line1), file1) != NULL) {
            printf("%s\n", line1);
        } 
        else {
            eof1 = 1;
        }

        if (!eof2 && fgets(line2, sizeof(line2), file2) != NULL) {
            printf("%s\n", line2);
        } 
        else {
            eof2 = 1;
        }
    }
    fclose(file1);
    fclose(file2);
}


