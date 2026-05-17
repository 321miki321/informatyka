#include <stdio.h>

int main() {
    printf("Prosty kalkulator\n");

    printf("Podaj 1 liczbe:\n");
    int number1 = 0;
    scanf("%d", &number1);

    printf("Podaj 2 liczbe:\n");
    int number2 = 0;
    scanf("%d", &number2);

    printf("%d + %d = %d\n", number1, number2, number1 + number2);
    printf("%d - %d = %d\n", number1, number2, number1 - number2);
    printf("%d * %d = %d\n", number1, number2, number1 * number2);
    printf("%d / %d = %d\n", number1, number2, number1 / number2);

    return 0;
}