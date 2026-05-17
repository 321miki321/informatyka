#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char letter;
    int i;

    fptr = fopen("plik.txt", "w+");
    if (fptr == 0) {
        printf("Wystapil blad podczas otwierania pliku.\n");
        exit(1);
    }

    for (letter = 'A'; letter <= 'Z'; letter++) {
        fputc(letter, fptr);
    }
    puts("Zapisano litery od A do Z.");

    fseek(fptr, -1, SEEK_END);
    printf("Oto zawartosc pliku wydrukowana wstecz:\n");
    for (i = 26; i > 0; i--) {
        letter = fgetc(fptr);
        fseek(fptr, -2, SEEK_CUR);
        printf("%c", letter);
    }
    printf("\n");

    fclose(fptr);
    return 0;
}