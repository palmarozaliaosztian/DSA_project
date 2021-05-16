//
// Created by palma on 5/16/2021.
//

#ifndef DATASTRUCTURESCOMPLEXITY_WORD_H
#define DATASTRUCTURESCOMPLEXITY_WORD_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A basic example for an item which can be stored in different data structures
 * Feel free to use other type or extend this with additional properties
 */
typedef struct {
    char* englishWord;
}Word;

/**
 * This function creates a new Word based on an english word
 * @param word, a string from which the function creates a new Word type.
 * @return the newly created word
 */
Word newWord(char* word);

/**
 * Comparison of two words
 * In this case the comparison is made using the english form of the words
 * Feel free to write other comparisons according to other criteria
 * 0 if equal
 * -1 if word1 < word2
 * 1 if word1 > word2
 * @param word1
 * @param word2
 * @return
 */
int compareToWords(Word word1, Word word2);

/**
 * Prints a word to the standard output
 * @param word, word to be printed
 */
void printWord(Word word);

#endif //DATASTRUCTURESCOMPLEXITY_WORD_H
