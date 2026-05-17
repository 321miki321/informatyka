#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void printArray(int* numbers, int size) {
    for (int i = 0; i < size; i++) {
        printf("*(numbers + %d) = %d\n", i, *(numbers + i));
    }
}

void swap(int* n1, int* n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main() {
    int numbers[SIZE] = {0};
    int sorted_numbers[SIZE] = {0};
    int choice;
    FILE *fptr;

    do {
        printf("\n--- MENU OPERACJI ---\n");
        printf("1. Wyswietl tablice\n");
        printf("2. Znajdz MAX\n");
        printf("3. Znajdz MIN\n");
        printf("4. Oblicz sume i srednia\n");
        printf("5. Oblicz mediane\n");
        printf("6. Wprowadz dane do tablicy\n");
        printf("7. Zapisz tablice do pliku\n");
        printf("8. Wczytaj tablice z pliku\n");
        printf("0. Wyjscie\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printArray(numbers, SIZE);
                break;

            case 2: {
                int max = numbers[0];
                for (int i = 1; i < SIZE; i++) if (numbers[i] > max) max = numbers[i];
                printf("Max = %d\n", max);
                break;
            }

            case 3: {
                int min = numbers[0];
                for (int i = 1; i < SIZE; i++) if (numbers[i] < min) min = numbers[i];
                printf("Min = %d\n", min);
                break;
            }

            case 4: {
                int sum = 0;
                for (int i = 0; i < SIZE; i++) sum += numbers[i];
                printf("Suma = %d, Srednia = %.2f\n", sum, (float)sum / SIZE);
                break;
            }

            case 5: {
                float median;
                if (SIZE % 2 == 0) {
                    median = (sorted_numbers[SIZE / 2 - 1] + sorted_numbers[SIZE / 2]) / 2.0f;
                } else {
                    median = (float)sorted_numbers[SIZE / 2];
                }
                printf("Mediana = %.2f\n", median);
                break;
            }

            case 6: {
                for (int i = 0; i < SIZE; i++) {
                    printf("Liczba %d: ", i + 1);
                    scanf("%d", &numbers[i]);
                    sorted_numbers[i] = numbers[i];
                }
                for (int i = 0; i < SIZE - 1; i++) {
                    for (int j = 0; j < SIZE - i - 1; j++) {
                        if (sorted_numbers[j] > sorted_numbers[j + 1]) {
                            swap(&sorted_numbers[j], &sorted_numbers[j + 1]);
                        }
                    }
                }
                break;
            }

            case 7: {
                fptr = fopen("plik.txt", "w");
                if (fptr == 0) {
                    printf("Blad otwarcia pliku do zapisu!\n");
                } else {
                    for (int i = 0; i < SIZE; i++) {
                        fprintf(fptr, "%d\n", numbers[i]);
                    }
                    fclose(fptr);
                    printf("Dane zostaly pomyslnie zapisane do plik.txt\n");
                }
                break;
            }

            case 8: {
                fptr = fopen("plik.txt", "r");
                if (fptr == 0) {
                    printf("Brak pliku plik.txt lub blad odczytu!\n");
                } else {
                    for (int i = 0; i < SIZE; i++) {
                        if (fscanf(fptr, "%d", &numbers[i]) != 1) break;
                        sorted_numbers[i] = numbers[i];
                    }
                    fclose(fptr);
                    printf("Dane zostaly wczytane z pliku.\n");
                }
                break;
            }

            case 0:
                printf("Koniec programu.\n");
                break;

            default:
                printf("Niepoprawny wybor!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}