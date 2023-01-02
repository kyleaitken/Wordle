// This program plays a game of wordle through the console

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include "wordleRound.c"

#define WORD_LIST_SIZE 1000


int main(void) {
    char** wordsList = calloc(WORD_LIST_SIZE, sizeof(char*));
    char* word = malloc(6 * sizeof(char));

    FILE* wordsLib = fopen("words.txt", "r");
    if (wordsLib == NULL) {
        perror("Message from perror");
        return -1;
    }

    int counter = 0;
    while(fscanf(wordsLib, "%s", word) != EOF) {
        wordsList[counter] = word;
        word = malloc(6 * sizeof(char));
        counter++;
    }
    fclose(wordsLib);

    //Get random word
    srand(time(NULL));
    char* randWord = wordsList[rand() % WORD_LIST_SIZE];
    printf("%s\n", randWord);

    // Run Game
    wordleRound(randWord);

    // free memory 
    for (int i=0; i<=counter; i++){
        free(wordsList[i]);
    }
    free(wordsList);
    free(word);
}