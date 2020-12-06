#include <stdlib.h>
#include <stdbool.h>

void filter(int* start, int* end, bool predicate(int), int** filterStart, int** filterEnd) {
    int length = 0;

    if (start == end) {
        filterStart = filterEnd = 0;
        return;
    }

    int* counterStart = start;

    while (start++ != end) {
        ++length;
    }

    int* filterList = (int*)malloc(length * sizeof(int));
    int* counter = filterList;
    int i = 0;

    while (i++ < length) {
        if (predicate(*counterStart)) {
            *counter = *counterStart;
            ++counter;
        }
        ++counterStart;
    }
    *filterStart = filterList;
    *filterEnd = counter;
}

void forEach(int* start, int* end, void func(int)) {
    if (start == end) {
        return;
    }

    while(start != end) {
        func(*start);
        start++;
    }
}

void map(int* start, int* end, int delegate(int), int** mapStart, int** mapEnd) {
    
}

