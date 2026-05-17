// Tab.c
#include <stdio.h>
#include "Tab.h"

void FillArray(int arr[], int size) {
    printf("Podaj 10 wartosci: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void PrintArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int FindMax(int array[], int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int FindMin(int array[], int size) {
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int Average(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

int Median(int array[], int size) {
    int max = array[0];
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void SaveTable(int array[], int size) {
    FILE * fptr;
    fptr = fopen("table.txt", "w+");
    if (fptr != NULL) {
        for (int i = 0; i < size; i++) {
            fprintf(fptr, "%d ", array[i]);
        }
        fclose(fptr);
    }
}

void LoadTable(int array[], int size) {
    FILE * fptr;
    fptr = fopen("table.txt", "r");
    if (fptr != NULL) {
        for (int i = 0; i < size; i++) {
            fscanf(fptr, "%d", &array[i]);
        }
        fclose(fptr);
    }
}

void PrintMenu() {
    printf("MENU\n");
    printf("1. Wypelnij tablice\n");
    printf("2. Wypisz tablice\n");
    printf("3. Znajdz minimum\n");
    printf("4. Znajdz maksimum\n");
    printf("5. Srednia\n");
    printf("6. Mediana\n");
    printf("7. Zapisz tablice\n");
    printf("8. Przywroc tablice\n");
    printf("0. Exit\n");
    printf("Wybor: ");
}