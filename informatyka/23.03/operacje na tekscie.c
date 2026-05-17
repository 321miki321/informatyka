#include <stdio.h>

void toLower(char *text) {
    while(*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}

void toUpper(char *text) {
    while(*text) {
        if ('a' <= *text && *text <= 'z') {
            *text -= ('a' - 'A');
        }
        text++;
    }
}

int textSize(char *text) {
    int size = 0;
    while(*text) {
        size++;
        text++;
    }
    return size;
}

int main() {
    while(1) {
        printf("Enter text:\n");
        char text[10000];
        fgets(text, 10000, stdin);
        
        text[textSize(text) - 1] = 0;
        
        if (!text[0]) {
            break;
        }
        
        printf("%s\n", text);
        toLower(text);
        printf("%s\n", text);
        toUpper(text);
        printf("%s\n", text);
        printf("Liczba znakow = %d\n", textSize(text));
    }
    return 0;
}