//
// Created by palma on 5/16/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include "Results.h"

Results *initializeResults() {
    Results *resultsTable = (Results *) (malloc(sizeof(Results)));
    if (!resultsTable) {
        printf("Cannot initialize results\n");
        exit(1);
    }
    resultsTable->results = (DataStructureComplexity *) (malloc(sizeof(DataStructureComplexity)));
    if (!resultsTable->results) {
        printf("Cannot initialize results\n");
        exit(1);
    }
    resultsTable->numberOfResults = 0;

    return resultsTable;

}

char* getCaseTypeByIndex(int index) {
    switch (index) {
        case 0:
            return "Best Case";
        case 1:
            return "Worst Case";
        case 2:
            return "Avg Case";
        default:
            return "Invalid case";
    }
}

void initializeResultsFor(Results *results, enum DSType type) {

    DataStructureComplexity result;
    result.type = type;
    result.numberOfResults = 0;
    result.cases[0].caseType = BestCase;
    result.cases[1].caseType = WorstCase;
    result.cases[2].caseType = AvgCase;

    results->results[type] = result;
    results->numberOfResults++;

}

void addResult(enum DSType type, enum CaseType caseType, enum Operation operation, double timeTaken, Results *resultsTable) {

    switch (caseType) {
        case BestCase:
            if (resultsTable->results[type].numberOfResults == 0) {
                resultsTable->results[type].numberOfResults = 1;
            }
            break;
        case WorstCase:
            if (resultsTable->results[type].numberOfResults == 1) {
                resultsTable->results[type].numberOfResults = 2;
            }
            break;
        case AvgCase:
            if (resultsTable->results[type].numberOfResults == 2) {
                resultsTable->results[type].numberOfResults = 3;
            }
            break;
        default:
            printf("Invalid case\n");
            break;

    }
    switch (operation) {
        case Insert:
            resultsTable->results[type].cases[caseType].timeTakenDuringAddition = timeTaken;
            break;
        case Search:
            resultsTable->results[type].cases[caseType].timeTakenDuringSearch = timeTaken;
            break;
        case Remove:
            resultsTable->results[type].cases[caseType].timeTakenDuringRemove = timeTaken;
            break;
        case Access:
            resultsTable->results[type].cases[caseType].timeTakenDuringAccess = timeTaken;
            break;
        default:
            printf("Invalid operation\n");
            break;

    }

}

void printAllResults(Results *resultsTable) {

    printf("ALL RESULTS\n");
    for (int i = 0; i < resultsTable->numberOfResults; ++i) {
        printf("\t - %s:\n", getDataStructureTypeByIndex(resultsTable->results[i].type));
        for (int j = 0; j < resultsTable->results[i].numberOfResults; ++j) {
            printf("\t\t ~ %s:\n", getCaseTypeByIndex(resultsTable->results[i].cases[j].caseType));
            printf("\t\t\t insertion: %.10lf\n", resultsTable->results[i].cases[j].timeTakenDuringAddition);
            printf("\t\t\t search: %.10lf\n", resultsTable->results[i].cases[j].timeTakenDuringSearch);
            printf("\t\t\t remove: %.10lf\n", resultsTable->results[i].cases[j].timeTakenDuringRemove);
            printf("\t\t\t access: %.10lf\n", resultsTable->results[i].cases[j].timeTakenDuringAccess);
            printf("\n");
        }

    }

}

char *getDataStructureTypeByIndex(int index) {
    switch (index) {
        case 0:
            return "ARRAY";
        case 1:
            return "LIST";
        case 2:
            return "BINARY TREE";
        case 3:
            return "HEAP";
        case 4:
            return "HASH TABLE";
        default:
            return "UNKNOWN";
    }
}
