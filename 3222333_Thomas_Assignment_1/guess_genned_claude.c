//Raw Ai generated code from ChatGPT
#include <stdio.h>

int main() {
    int secret = 7;
    int guess;
    int attempts = 3;
    int won = 0;

    printf("Guess the secret number (between 1 and 10). You have %d tries.\n", attempts);

    for (int i = 1; i <= attempts; i++) {
        printf("Attempt %d: Enter your guess: ", i);
        scanf("%d", &guess);

        if (guess == secret) {
            won = 1;
            break;
        } else if (guess < secret) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }
    }

    if (won) {
        printf("Congratulations! You guessed the secret number %d correctly!\n", secret);
    } else {
        printf("Sorry, you're out of tries. The secret number was %d.\n", secret);
    }

    return 0;
}
