#include <stdio.h>

void compute_average_age(const int *array, int size, float *out_average);

int main() {
    int dataset[4] = { 20, 30, 40, 50 }; // Average should be 35.0
    float calculated_avg = 0.0f;

    compute_average_age(dataset, 4, &calculated_avg);
    printf("[LOG] Calculated Average: %.2f\n", calculated_avg);

    if (calculated_avg != 35.0f) {
        fprintf(stderr, "❌ TEST FAILED: Average contaminated by trailing garbage memory indices! Got: %.2f\n", calculated_avg);
        return 1;
    }
    printf("✅ TEST PASSED: Array loop safely encapsulated.\n");
    return 0;
}
