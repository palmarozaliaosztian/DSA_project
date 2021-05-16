//
// Created by palma on 5/16/2021.
//

#ifndef DATASTRUCTURESCOMPLEXITY_RESULTS_H
#define DATASTRUCTURESCOMPLEXITY_RESULTS_H


/**
 * Util enums and structures
 */

enum DSType {
    ArrayType,
    ListType = 1,
    BinaryTreeType = 2,
    HeapType = 3,
    HashTableType = 4,
};

enum CaseType {
    BestCase,
    WorstCase,
    AvgCase
};

enum Operation {
    Search,
    Remove,
    Access,
    Insert
};

typedef struct  {
    enum CaseType caseType;

    double timeTakenDuringAddition;
    double timeTakenDuringSearch;
    double timeTakenDuringRemove;
    double timeTakenDuringAccess;

}Case;

typedef struct {

    enum DSType type;
    Case cases[3];
    int numberOfResults;

}DataStructureComplexity;

typedef struct {
    DataStructureComplexity *results;
    int numberOfResults;
}Results;


/**
 * This function allows you to add new results to a specific data structure, case and operation
 * @param type, the type of the data structure
 * @param caseResult, results of a given case
 */
void addResult(enum DSType type, enum CaseType caseType, enum Operation operation, double timeTaken, Results *results);

/**
 * This function creates and allocates memory for all results
 * @return the newly allocated result type
 */
Results* initializeResults();

/**
 * Default values for result based on a specific data structure
 * @param results, all results
 * @param type, the type of the data structure
 */
void initializeResultsFor(Results* results, enum DSType type);

/**
 * Get the string format of a specific case type
 * @param index, the order number of the CaseType enum value
 * @return string format for CaseType enum value
 */
char*  getCaseTypeByIndex(int index);

/**
 * Get the string format of a specific data structure
 * @param index, the order number of the DsType enum value
 * @return string format for DsType enum value
 */
char *getDataStructureTypeByIndex(int index);

/**
 * Print all results to the console
 * @param results, all results
 */
void printAllResults(Results* results);


#endif //DATASTRUCTURESCOMPLEXITY_RESULTS_H
