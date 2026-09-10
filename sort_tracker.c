#include <stdio.h>

void compute_average_age(const int *array, int size, float *out_average) {
    int sum = 0;
    // BUG: Inadvertently modifying the index loop boundaries or passing an uninitialized assignment pointer layout
    for (int i = 0; i <= size; i++) { // Off-by-one: processes array[size] which is garbage memory
        sum += array[i];
    }
    *out_average = (float)sum / size;
}
