//Prologue comments
//File_Name: Corrected_Claude_genned_code.c
//Program Description: C program that picks a number between 1 to 10 and the user gets three chances to guess it.
//Inputs: User inputted integers.
//Collaborators and Sources: ChatGPT, Claude, Professor's notes
//Author_Name: Alan Thomas
//Date of Creation: 9/8/2026
//Revision_Date: 9/8/2026
//Revisions_Made: Comments added, error handling added, ensured only valid input is accepted rather than anything



#include <stdio.h>  //header that contains standard I/O library
//AI-genned by Claude
int main() { 
    int secret = 7;   // the number player needs to guess
    int guess;         // stores which guess the player is on
    int attempts = 3;  // number of attempts a player has
    int won = 0;        // flag: 0 = hasn't won yet, 1 = guessed correctly
                         // (used after the loop to decide which final message to print)

    // Explain the rules to the player before the game starts
    printf("Guess the secret number (between 1 and 10). You have %d tries.\n", attempts);

    // Main game loop: runs at most "attempts" times.
    // "i" also doubles as the attempt number shown to the player.
    for (int i = 1; i <= attempts; i++) {   //Start of for loop that takes the attemps
        printf("Attempt %d: Enter your guess: ", i); //user input for number

        int result = scanf("%d", &guess); // scanf returns the number of items it successfully read.
	// We expect 1 (one integer). Anything else means the read failed.

	

	//Part of the revisions added by Claude

        // --- Error case 1: input stream closed (e.g., Ctrl+D, piped file ran out) ---
        // Must be checked BEFORE the general "result != 1" check below,
        // because EOF also satisfies "!= 1" and would otherwise cause
        // an infinite loop (trying to re-read from a stream that's already closed).
        if (result == EOF) {
            fprintf(stderr,
                "\nError: Input stream ended unexpectedly (EOF received). "
                "No more input is available to read. Exiting program.\n");
            return 1; // non-zero return signals abnormal termination to the OS/shell
        }//End of error case 1 loop
	
        // --- Error case 2: input wasn't a valid integer (e.g., letters, symbols) ---
        if (result != 1) { //Start of error case 2 loop
            fprintf(stderr,
                "Error: Attempt %d expects a whole number, but non-numeric input was entered. "
                "Please type digits only (e.g., 5), then press Enter.\n", i); //Printing of error message

            // scanf leaves the bad characters sitting in the input buffer.
            // If we don't clear them, the next scanf call will immediately
            // fail again on the same leftover text. This loop discards
            // characters up to (and including) the next newline.
            while (getchar() != '\n' && getchar() != EOF);

            i--;      // undo this iteration's increment so bad input
                      // doesn't cost the player a real attempt
            continue; // skip the rest of this iteration, re-prompt
        } //end of error case 2 loop

        // --- Error case 3: valid integer, but outside the allowed range ---
        if (guess < 1 || guess > 10) { //Start of error case 3 loop
            fprintf(stderr,
                "Error: %d is outside the allowed range. "
                "Your guess must be between 1 and 10 (inclusive).\n",
                guess); //Prints an appropriate error message
            i--;      // same idea: don't penalize the player for invalid input
            continue;
        } //end of error case 3 loop

        // --- Normal game logic: compare guess to the secret number ---
        if (guess == secret) { //start of game logic loop
            won = 1;  // mark as won...
            break;    // ...and exit the loop immediately (no need to keep guessing)
        } //end of if loop
		else if (guess < secret) { //start of else if loop
            printf("Too low! Try a higher number.\n");
        } //end of else if loop
		else { //start of else loop
            printf("Too high! Try a lower number.\n");
        } //end of else loop
        // If neither error case nor a correct guess, the loop simply
        // continues to the next attempt (i increments normally).
    } //end of game logic loop

    // After the loop: report the final outcome based on the "won" flag.
    // This runs whether the loop ended via break (won) or ran out
    // of attempts (loop condition false).
    if (won) { //start of if loop
        printf("Congratulations! You guessed the secret number %d correctly!\n", secret); //Print victory message when won 
    } //end of if loop
	else { //start of else loop
        printf("Sorry, you're out of tries. The secret number was %d.\n", secret); //Prints the failure message when attemps are exhausted
    } //end of else loop

    return 0; // 0 signals successful/normal program termination
} //end of the main loop
