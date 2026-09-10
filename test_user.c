#include <assert.h>
#include <string.h>
#include <stdio.h>

char* generate_system_status();

int main() {
    char* result = generate_system_status();
    
    // Call another dummy function to overwrite the stack framework values completely
    printf("Wiping old local call frames...\n");
    
    // If it's a dangling pointer, this check will read garbage values or Segfault
    if (strcmp(result, "SYSTEM_OPERATIONAL_ONLINE") != 0) {
        printf("Challenge 9 Failed: Pointer pointed to dropped stack memory structure.\n");
        return 1;
    }
    printf("Challenge 9 Passed!\n");
    return 0;
}

