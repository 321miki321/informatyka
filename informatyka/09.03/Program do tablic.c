#include <stdio.h>
#define SIZE 10

int main() {
    printf("Tablice\n");
    int numbers[SIZE] = {1, 2, 3, 40, -5, 6, 7, 8, 9, 10};

    int z;
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &z);
        *(numbers + i) = z;
    }

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("*(numbers + %d) = %d\n", i, *(numbers + i));
    }

    int max = *numbers;
    for (int i = 0; i < SIZE; i++) {
        if (*(numbers + i) > max) {
            max = *(numbers + i);
        }
    }

    printf("\n");
    printf("max = %d\n", max);

    int min = *numbers;
    for (int i = 0; i < SIZE; i++) {
        if (*(numbers + i) < min) {
            min = *(numbers + i);
        }
    }

    printf("min = %d\n", min);

    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += *(numbers + i);
    }

    printf("sum = %d\n", sum);
    float average = (float) sum / SIZE;
    printf("average = %.2f\n", average);

    int swap;
    for (int i = 0; i < SIZE; i++) {
        for(int j = i + 1; j < SIZE; j++ ){
            if(*(numbers + i) > *(numbers + j)){
                swap = *(numbers + i);
                *(numbers + i) = *(numbers + j);
                *(numbers + j) = swap;
            }
        }
    }

    float mediana;
    if(SIZE % 2) {
        mediana = (float)(*(numbers + SIZE/2) + *(numbers + SIZE/2 - 1)) / 2.0;
    } else {
        mediana = *(numbers + SIZE/2);
    }
    printf("mediana = %f\n", mediana);

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("*(numbers + %d) = %d\n", i, *(numbers + i));
    }
    return 0;
}