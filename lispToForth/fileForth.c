#include "tradForth.h"


char* FILENAME = "lispToForth/finalTrad.forth";

void cleanFile() {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fclose(file);
}

void writeFile(const char* text) {
    FILE* file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%s", text);
    fclose(file);
}

