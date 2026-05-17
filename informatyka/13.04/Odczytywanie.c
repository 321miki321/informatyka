#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char fileLine[100];

    fptr = fopen("plik.txt", "r");
    if (fptr != 0) {
        while (!feof(fptr)) {
            fgets(fileLine, 100, fptr);
            if (!feof(fptr)) {
                puts(fileLine);
            }
        }
    } else {
        printf("\nBlad otwierania pliku!\n");
    }

    fclose(fptr);
    return 0;
}