#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void tail(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File open error.\n");
        return;
    }
    // Создаем массив для хранения последних N строк
    char **lines = (char **)malloc(n * sizeof(char *));
    if (lines == NULL) {
        printf("Memory allocation error.\n");
        fclose(file);
        return;
    }

    int count = 0;  // Счетчик строк
    int i;

    // Заполняем массив значениями NULL
    for (i = 0; i < n; i++) {
        lines[i] = NULL;
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Копируем текущую строку в массив lines
        if (lines[count % n] != NULL) {
            free(lines[count % n]);
        }
        lines[count % n] = strdup(buffer); // strdup копирует строку

        count++;
    }
    fclose(file);

    // Выводим последние N строк
    int start = count > n ? count % n : 0;
    for (i = 0; i < n; i++) {
        if (lines[(start + i) % n] != NULL) {
            printf("%s", lines[(start + i) % n]);
            free(lines[(start + i) % n]);
        }
    }
    free(lines);
}
