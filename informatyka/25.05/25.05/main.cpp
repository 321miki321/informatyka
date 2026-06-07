//#include <iostream>
#include <stdio.h>
#include "kolejka.h"

void menu(void)
{
    printf("\n");
    printf("1 - dolacz liczbe do kolejki (Push)\n");
    printf("2 - odczytuje pierwszy element w kolejce (Front)\n");
    printf("3 - usun liczbe z poczatku kolejki (Pop)\n");
    printf("4 - sprawdz czy kolejka jest pusta\n");
    printf("5 - sprawdz czy kolejka jest pelna\n");
    printf("6 - koniec programu\n");
    printf("\n");
}

int main()
{
    int temp = 0;
    int option = 0;
    printf("Kolejka\n");
    while (1)
    {
        menu();
        scanf("%d", &option);


        switch (option)
        {
            case 1:
                if ( !isStackFull() ){
                    printf("Podaj wartosc: ");
                    scanf("%d", &temp);
                    Push(temp);
                }
                else {
                    printf("operacja niedozwolona kolejka pelna!!!\n\n");
                }

                break;

            case 2:
                if (!isStackEmpty()) {
                    temp = Front();
                    printf("Odczytana wartosc: %d", temp);
                }
                else {
                    printf("operacja niedozwolona kolejka pusta!!!\n\n");
                }

                break;

            case 3:
                if (!isStackEmpty()) {
                    temp = Pop();
                    printf("Odczytana wartosc: %d", temp);
                }
                else {
                    printf("operacja niedozwolona kolejka pusta!!!\n\n");
                }
                break;

            case 4:
                if (isStackEmpty()) {
                    printf("Kolejka jest pusty.\n");
                }
                else {
                    printf("Kolejka nie jest pusty.\n");
                }
                break;

            case 5:
                if (isStackFull()) {
                    printf("Kolejka jest pelny.\n");
                }
                else {
                    printf("Kolejka nie jest pelny.\n");
                }
                break;

            case 6:
                //zakonczenie programu
                return 0;

            default:
                printf("Wybierz wlasciwa opcje.\n\n");
                break;
        }
    }

    return 0;
}