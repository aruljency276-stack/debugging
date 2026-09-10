#include <stdio.h>
#include <string.h>

void safe_string_copy(char *destination, const char *source);

int main() {
    const char *msg = "TEST";
    char buffer[10] = { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };

    safe_string_copy(buffer, msg);
    printf("[LOG] Destination Buffer: %s\n", buffer);

    // If the null-terminator is missing, strlen will be greater than 4
    if (strlen(buffer) != 4) {
        fprintf(stderr, "❌ TEST FAILED: String lacks proper null-terminator assignment!\n");
        return 1;
    }
    printf("✅ TEST PASSED: Bound termination character safe.\n");
    return 0;
}
