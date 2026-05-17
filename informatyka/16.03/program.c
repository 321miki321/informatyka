#include <stdio.h>
#define SIZE 10

int Max(int numbers[]) {
    int max = numbers[0];
    for (int i = 0; i < SIZE; i++) {
        if (*(numbers + i) > max) {
            max = *(numbers + i);
        }
    }
    return max;
}

int Min(int numbers[]) {
    int min = numbers[0];
    for (int i = 0; i < SIZE; i++) {
        if (*(numbers + i) < min) {
            min = *(numbers + i);
        }
    }
    return min;
}

int Sum(int numbers[]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += *(numbers + i);
    }
    return sum;
}

float srednia(int numbers[]) {
    return (float)(Sum(numbers)) / SIZE;
}

float Mediana(int numbers[]) {
    float mediana = 0;
    if(SIZE % 2) {
        mediana = (float)(*(numbers + SIZE/2) + *(numbers + SIZE/2 - 1)) / 2.0;
    } else {
        mediana = *(numbers + SIZE/2);
    }
    return mediana;
}

void swap(int numbers[]) {
    int temp;
    for (int i = 0; i < SIZE; i++) {
        for(int j = i + 1; j < SIZE; j++ ) {
            if(*(numbers + i) > *(numbers + j)) {
                temp = *(numbers + i);
                *(numbers + i) = *(numbers + j);
                *(numbers + j) = temp;
            }
        }
    }
}

void wczytywanie(int numbers[]) {
    int z;
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &z);
        *(numbers + i) = z;
    }

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("*(numbers + %d) = %d\n", i, *(numbers + i));
    }
}

int main() {
    printf("Tablice\n");
    int numbers[SIZE];

    wczytywanie(numbers);

    swap(numbers);

    printf("max = %d\n", Max(numbers));

    printf("min = %d\n", Min(numbers));

    printf("suma = %d\n", Sum(numbers));

    printf("average = %.2f\n", srednia(numbers));

    printf("mediana = %f\n", Mediana(numbers));

    return 0;
}