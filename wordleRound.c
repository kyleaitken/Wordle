#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool checkGuess(char* guess, const char* answer) {
    // check if word is correct
    if (strcasecmp(guess, answer) == 0) {
        return true;
    }

    // if not correct, give clues
    char clues[6] = {'-', '-', '-', '-', '-', '\0'};

    // check if letter(s) in correct place or in word
    for (int i=0; i<5; i++) {
        char g = toupper(guess[i]);
        for (int j=0; j<5; j++) {
            char a = toupper(answer[j]);
            if (g == a) {
                if (i == j) {
                    clues[i] = g;
                    break;
                } else {
                    clues[i] = tolower(g);
                    break;
                }
            }
        }
    }

    printf("Here's your clue: %s\nUppercase indicates the letter was in the correct position, lowercase indicates the letter is in the incorrect position\n", clues);
    return false;
}

void wordleRound(const char* correctWord) {
    int numGuesses = 0;
    bool guessedWord = false;
    char* guess = malloc(6 * sizeof(char));

    while (numGuesses < 6 && !guessedWord) {
        printf("Enter a 5 letter word and hit enter");
        do {
            fgets(guess, 6, stdin);
            guess[strcspn( guess, "\n" )] = '\0';
        } while (strlen(guess) != 5);
        numGuesses++;
        printf("Your guess was %s\n", guess);

        guessedWord = checkGuess(guess, correctWord);
        if (guessedWord) {
            printf("Congratulations! You guess correctly in %d guesses!\n", numGuesses);
        } 
        if (numGuesses == 6) {
            printf("Sorry, you used up all your guesses. The correct word was %s!\n", correctWord);
        }
    }
    free(guess);
}

