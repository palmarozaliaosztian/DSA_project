//
// Created by palma on 5/16/2021.
//

#include "Word.h"


Word newWord(char* word) {
    Word newWord;
    newWord.englishWord = (char*)calloc(strlen(word)+1, sizeof(char));
    if(!newWord.englishWord) {
        printf("Error when creating new word\n");
        exit(1);
    }
    strcpy(newWord.englishWord, word);
    return newWord;
}

int compareToWords(Word word1, Word word2) {
    return strcmp(word1.englishWord, word2.englishWord);
}

void printWord(Word word) {
    printf("%s\n", word.englishWord);
}