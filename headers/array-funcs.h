void filter(int * start, int * end, bool predicate(int), int ** filterStart, int ** filterEnd);
void forEach(int* start, int* end, void func(int));
void map(int* start, int* end, int func(int), int** mapStart, int** mapEnd);