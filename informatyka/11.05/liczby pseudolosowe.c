#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int b_limit, t_limit, volume;
    printf("Prog dolny liczb pseudolosowych\n");
    scanf("%d", &b_limit);
    printf("Prog gorny liczb pseudolosowych\n");
    scanf("%d", &t_limit);
    printf("ile liczb liczb pseudolosowych\n");
    scanf("%d", &volume);

    int *temps = (int *) malloc(volume * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < volume; ++i) {
        temps[i] = rand() % (t_limit - b_limit + 1) + b_limit;
    }
    for (int i = 0; i < volume; ++i) {
        printf("%d, ", temps[i]);
    }
    free(temps);

    return 0;
}