//
// Created by palma on 5/16/2021.
//

#include "Array.h"

Array *createArray(int capacity) {
    Array* newArray = (Array*)(malloc(sizeof(Array)));
    if(!newArray) {
        printf("Error when creating Array type\n");
        exit(1);
    }

    newArray->maxCapacity = capacity;
    newArray->numberOfItems = 0;
    newArray->words = (Word*)(calloc(capacity, sizeof(Word)));

    if(!newArray->words) {
        printf("Error when creating words array of Array data structure\n");
        exit(1);
    }
    return newArray;
}

void addItemToArray(Word word, Array *array) {
    if(array) {
        if (array->numberOfItems < array->maxCapacity - 1) {
            array->words[array->numberOfItems++] = word;
            return;
        }
    }
    printf("Cannot add new word to Array\n");

}

int getNumberOfItemsFromArray(Array *array) {
    if(array) {
        return array->numberOfItems;
    }
    return 0;
}

bool removeItemFromArray(Word itemToBeDeleted, Array *array) {
    if(array) {
        for (int i = 0; i < array->numberOfItems; ++i) {
            if (compareToWords(array->words[i], itemToBeDeleted) == 0) {
                ///now copy all items
                for (int j = i; j < array->numberOfItems - 1; ++j) {
                    array->words[j] = array->words[j + 1];
                }
                array->numberOfItems--;
                return true;
            }
        }
    }
    return false;
}

Word getNthItemFromArray(int n, Array *array) {
    Word result = newWord("");
    if(array) {
        if (n >= 0 && n < array->numberOfItems) {
            result = array->words[n];
        }
    }
    return result;
}

void printAllItemsOfArray(Array *array) {
    if(array) {
        printf("Items in Array:\n");
        for (int i = 0; i < array->numberOfItems; ++i) {
            printWord(array->words[i]);
        }
    }
}

void destroyArray(Array **pArray) {
    if(*pArray) {
        free((*pArray)->words);
        (*pArray)->maxCapacity = 0;
        (*pArray)->numberOfItems = 0;
        free(*pArray);
        *pArray = NULL;
        printf("Array deallocated\n");
        printf("\n***************************************************\n\n");

    }
}

bool findItemInArray(Word itemToBeFound, Array *array) {
    if(array) {
        for (int i = 0; i < array->numberOfItems; ++i) {
            if (compareToWords(array->words[i], itemToBeFound) == 0) {
                return true;
            }
        }
    }
    return false;
}
