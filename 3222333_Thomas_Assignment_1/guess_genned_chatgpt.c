#include <stdio.h>

int main() {
    int secretNumber = 7;
    int guess;
    int tries = 0;
    int correct = 0;

    while (tries < 3) {
        printf("Guess the secret number (1-10): ");
        scanf("%d", &guess);

        tries++;

        if (guess == secretNumber) {
            printf("Correct! You guessed the secret number!\n");
            correct = 1;
            break;
        } else if (guess < secretNumber) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }
    }

    if (correct) {
        printf("You win!\n");
    } else {
        printf("You lose! The secret number was %d.\n", secretNumber);
    }

    return 0;
}