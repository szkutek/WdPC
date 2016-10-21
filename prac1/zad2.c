//290207
//lista 1
//zadanie 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random(void){
    int seed = time(NULL);
    srand(seed);
    return rand()%101;
}

int main(void){
    int n = generate_random();
    int guessed = 0;
    int round = 1, max_rounds = 10;
    int users_guess = 0;

    puts("A number in range from 0 to 100 has been generated. Take a guess:");

    while ( round <= max_rounds && guessed == 0){
        scanf("%d", &users_guess);

        if (users_guess == n) guessed = 1;
        else if (round == max_rounds && guessed == 0)
            printf("You lost! The number was %d.\n", n);
        else {
            if (users_guess > n)
                printf("The number is smaller. ");
            else printf("The number is bigger. ");
        }

        if (round < max_rounds && guessed == 0) printf("Try again:\n");
        round++;
    }

    if (guessed == 1){
        if (round-1 == 1)
            printf("WINNER! You guessed the number on the %d st try.\n", round-1);
        else if (round-1 == 2)
            printf("WINNER! You guessed the number on the %d nd try.\n", round-1);
        else if (round-1 == 3)
            printf("WINNER! You guessed the number on the %d rd try.\n", round-1);
        else
            printf("WINNER! You guessed the number on the %d th try.\n", round-1);
    }


    return 0;
}
