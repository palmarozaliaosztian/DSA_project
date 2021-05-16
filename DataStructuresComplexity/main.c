#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "Results.h"
#include <windows.h>

/**
 * useful variables and function in order to measure time
 * feel free to use this or any other method you find efficient
 */
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        printf("QueryPerformanceFrequency failed!\n");

    PCFreq = (double)(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return (double)(li.QuadPart-CounterStart)/PCFreq;
}

/**
 * useful constants
 */


const int numberOfWords = 81028;

/**
 * DECLARATION OF DIFFERENT DATA STRUCTURES
 */

///Array
Array* array;
///List
///BinaryTree
///Heap
///HashTable


///Use the results HashTable for storing results
Results *results;

void measureAdditionComplexity();

void createDataStructures();

void measureSearchComplexity();

void measureRemoveComplexity();

void measureAccessComplexity();

double calculateAverageTime(enum DSType type, Word word, enum Operation operation, int index);

void destroyDataStructures();

void measureComplexityForDifferentDataStructures(const char *fileName);

int main() {
    printf("This program was written in order to compare the execution time and efficiency of different data structures\n");

    int numberOfInputFiles = 5;
    const char* fileNames[] = {
            "dictionary10.txt",
            "dictionary100.txt",
            "dictionary1000.txt",
            "dictionary10000.txt",
            "dictionary_all.txt"};

    for(int i = 0; i < numberOfInputFiles; ++i) {
        measureComplexityForDifferentDataStructures(fileNames[i]);
    }

    return 0;
}

void measureComplexityForDifferentDataStructures(const char *fileName) {
    FILE* file = freopen(fileName, "r", stdin);
    if(!file) {
        printf("Error when opening the input file\n");
        exit(1);
    }

    ///INITIALIZE RESULTS
    results = initializeResults();

    ///CREATE DATA STRUCTURES
    createDataStructures();

    ///ADDITION
    measureAdditionComplexity();

    ///SEARCH
    measureSearchComplexity();

    ///REMOVE
    measureRemoveComplexity();

    ///ACCESS
    measureAccessComplexity();


    printf("Results for input file: %s\n", fileName);
    printAllResults(results);

    destroyDataStructures();

    fclose(file);
}

void createDataStructures() {
    ///Create Array
    array = createArray(numberOfWords);
    initializeResultsFor(results, ArrayType);

    ///Create List

    ///Create BinaryTree

    ///Create Heap

    ///Create HashTable

}

void destroyDataStructures() {
    ///Destroy Array
    destroyArray(&array);

    ///Destroy List

    ///Destroy BinaryTree

    ///Destroy Heap

    ///Destroy HashTable
}

void measureAdditionComplexity() {

    ///useful variables
    char item[30];
    double avgTimeTaken = 0;
    double result;


    while(scanf("%s", item) == 1) {
        ///add item to Array
        StartCounter();
        addItemToArray(newWord(item), array);
        result = GetCounter();
        avgTimeTaken += result;

        ///add item to List

        ///add item to BinaryTree

        ///add item to Heap

        ///add item to HashTable

    }

    //printf("Array: AVG time taken by addition is : %.10f\n", avgTimeTaken/numberOfWords);
    addResult(ArrayType, BestCase, Insert, result, results);
    addResult(ArrayType, WorstCase, Insert, result, results);
    addResult(ArrayType, AvgCase, Insert, result, results);

}

void measureAccessComplexity() {
    double result;

    ///access in Array
    int bestCaseIndex = 0;
    int worstCaseIndex = array->numberOfItems-1;

    result = calculateAverageTime(ArrayType, array->words[bestCaseIndex], Access, 0);
    //printf("Array: avg time taken by access (BEST CASE) is : %.10f\n", result);
    addResult(ArrayType, BestCase, Access, result, results);

    result = calculateAverageTime(ArrayType, array->words[worstCaseIndex], Access, worstCaseIndex);
    //printf("Array: avg time taken by access (WORST CASE) is : %.10f\n", result);
    addResult(ArrayType, WorstCase, Access, result, results);

    int middleIndex =  array->numberOfItems/2;
    result = calculateAverageTime(ArrayType, array->words[middleIndex], Access, middleIndex);
    addResult(ArrayType, AvgCase, Access, result, results);
    //printf("Array: avg time taken by access (AVG CASE) is : %.10f\n", result);

}

void measureRemoveComplexity() {
    double result;

    ///remove from Array
    Word firstWord = array->words[0];
    Word lastWord = array->words[array->numberOfItems-1];

    result = calculateAverageTime(ArrayType, firstWord, Remove, 0);
    //printf("Array: avg time taken by remove (BEST CASE) is : %.10f\n", result);
    addResult(ArrayType, BestCase, Remove, result, results);

    result = calculateAverageTime(ArrayType, lastWord, Remove, array->numberOfItems-1);
    //printf("Array: avg time taken by remove (WORST CASE) is : %.10f\n", result);
    addResult(ArrayType, WorstCase, Remove, result, results);

    int middleIndex =  array->numberOfItems/2;
    result = calculateAverageTime(ArrayType, array->words[middleIndex], Remove, middleIndex);
    //printf("Array: avg time taken by remove (AVG CASE) is : %.10f\n", result);
    addResult(ArrayType, AvgCase, Remove, result, results);
}

void measureSearchComplexity() {
    double result;

    ///search in Array
    Word firstWord = array->words[0];
    Word lastWord = array->words[array->numberOfItems-1];

    result = calculateAverageTime(ArrayType, firstWord, Search, 0);
    //printf("Array: avg time taken by search (BEST CASE) is : %.10f\n", result);
    addResult(ArrayType, BestCase, Search, result, results);

    result = calculateAverageTime(ArrayType, lastWord, Search, array->numberOfItems-1);
    //printf("Array: avg time taken by search (WORST CASE) is : %.10f\n", result);
    addResult(ArrayType, WorstCase, Search, result, results);

    int middleIndex =  array->numberOfItems/2;
    result = calculateAverageTime(ArrayType, array->words[middleIndex], Search, middleIndex);
    addResult(ArrayType, AvgCase, Search, result, results);
    //printf("Array: avg time taken by search (AVG CASE) is : %.10f\n", result);
}

double calculateAverageTime(enum DSType type, Word word, enum Operation operation, int index) {

    int counter = 10;
    double  avgResult = 0;
    switch (type) {
        case ArrayType:
        {
            switch (operation) {
                case Search:
                {
                    double currentResult;
                    for(int i = 0; i < counter; ++i) {
                        StartCounter();
                        findItemInArray(word, array);
                        currentResult = GetCounter();
                        if(i > 0) {
                            avgResult += currentResult;
                        }
                    }
                    break;
                }
                case Remove:
                {
                    double currentResult;
                    for(int i = 0; i < counter; ++i) {
                        StartCounter();
                        removeItemFromArray(word, array);
                        currentResult = GetCounter();
                        if(i > 0) {
                            avgResult += currentResult;
                        }
                    }
                    break;
                }
                case Access:
                {
                    double currentResult;
                    for(int i = 0; i < counter; ++i) {
                        StartCounter();
                        getNthItemFromArray(index, array);
                        currentResult = GetCounter();
                        if(i > 0) {
                            avgResult += currentResult;
                        }
                    }
                    break;
                }
                default:
                    printf("Invalid operation\n");
                    break;
            }
            break;
        }
        case ListType: {
            ///TODO
            break;
        }
        case BinaryTreeType: {
            ///TODO
            break;
        }
        case HeapType: {
            ///TODO
            break;
        }
        case HashTableType: {
            ///TODO
            break;
        }
        default:
            printf("Invalid data structure\n");
            break;
    }
    return avgResult / counter;

}
