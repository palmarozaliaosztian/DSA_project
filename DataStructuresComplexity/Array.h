//
// Created by palma on 5/16/2021.
//

#ifndef DATASTRUCTURESCOMPLEXITY_ARRAY_H
#define DATASTRUCTURESCOMPLEXITY_ARRAY_H


#include "Word.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int numberOfItems;
    int maxCapacity;
    Word* words;
}Array;

/**
 * This function creates a new IntArray
 * @param capacity, the maximum number of words
 * @return the newly allocated IntArray
 */
Array* createArray(int capacity);

/**
 * This function destroys the array and free all the memory used.
 * @param pArray, reference of the array that needs to be deallocated.
 */
void destroyArray(Array **pArray);
/**
 * This function adds a new item to the array if the capacity allows it
 * @param word, the new item that needs to be added to the array, feel free to add more complex items as well
 * @param array, the current IntArray which stores all the items
 */
void addItemToArray(Word word, Array* array);

/**
 * This function returns the current number of items in the IntArray
 * @param array, the current IntArray which stores all the items
 * @return the number of items
 */
int getNumberOfItemsFromArray(Array* array);


/**
 * This function removes a given item from the array.
 * Be sure that in case of this kind of data structure you need to copy all items after the deleted item.
 * Be sure to also decrement the number of items.
 * @param itemToBeDeleted, the item that needs to be removed from the array
 * @param array, the current IntArray which stores all the items
 * @return a bool value which is true if the remove was successful, false otherwise
 */
bool removeItemFromArray(Word itemToBeDeleted, Array* array);

/**
 * This functions returns the nth (item found at a given position) item from the array.
 * If there is no such position the return value is an empty array.
 * @param n, the nth item in the array
 * @param array, the current IntArray which stores all the items
 * @return the item found at the specific position
 */
Word getNthItemFromArray(int n, Array* array);

/**
 *
 * @param itemToBeFound
 * @param array
 * @return
 */
bool findItemInArray(Word itemToBeFound, Array* array);

/**
 * This function prints all items found in the IntArray data structure
 * @param array, the current IntArray which stores all the items
 */
void printAllItemsOfArray(Array* array);



#endif //DATASTRUCTURESCOMPLEXITY_ARRAY_H
