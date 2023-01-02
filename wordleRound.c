#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

// checkGuess(guess, answer) validates if the guessed word was correct. If not correct,
//   provides a clue as to which letters, if any, are in the correct position or 
//   incorrect position
// effects: creates output
// requires: guess and answer are not null

bool checkGuess(char* guess, const char* answer) {
    assert(guess);
    assert(answer);
    if (strcasecmp(guess, answer) == 0) {
        return true;
    }

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



// wordleRound(correctWord) Plays a round of Wordle, allowing the user up to 6 guesses to guess the word correctly
// effects: allocates and frees memory
// requires: correctWord is not null 

void wordleRound(const char* correctWord) {
    assert(correctWord);
    int numGuesses = 0;
    bool guessedWord = false;
    char* guess = malloc(6 * sizeof(char));

    while (numGuesses < 5 && !guessedWord) {
        printf("Enter a 5 letter word and hit enter: ");
        scanf("%s", guess);
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