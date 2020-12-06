#include <stdio.h>
#include <stdbool.h>
#include "../headers/array-funcs.h"

typedef unsigned int uint;

void printNum(int num) {
    printf("Num: %d\n", num);
}

int doubleNum(int num) {
    return num * 2;
}

bool onlyGreaterThanThree(int num) {
    return num > 3;
}

int main() {
    //#region forEach - Call a delegate for each element in array
    int numList[] = { 5, 4, 3, 7, 10, 1 };
    uint size = sizeof(numList) / sizeof(numList[0]);
    int* start = numList;
    int* end = start + size;

    forEach(start, end, printNum);
    //#endregion

    //#region map
    int* mapStart = 0;
    int* mapEnd = 0;
    map(start, end, doubleNum, &mapStart, &mapEnd);
    int* mapStartCpy = mapStart;

    if (mapStart != mapEnd) {
        while (mapStart != mapEnd) {
            printf("doubled num: %d\n", *mapStart);
            ++mapStart;
        }
        // releasing memory as new array is created in heap
        if (mapStartCpy) {
            free(mapStartCpy);
            mapStartCpy = 0;
        }
    }
    //#endregion

    //#region filter
    int* filterStart = 0;
    int* filterEnd = 0;
    filter(start, end, onlyGreaterThanThree, &filterStart, &filterEnd);
    int* filterStartCpy = filterStart;

    if (filterStart != filterEnd) {
        while (filterStart != filterEnd) {
            printf("filtered num: %d\n", *filterStart);
            ++filterStart;
        }
        // releasing memory as new array is created in heap
        if (filterStartCpy) {
            free(filterStartCpy);
            filterStartCpy = 0;
        }
    }
    //#endregion

}