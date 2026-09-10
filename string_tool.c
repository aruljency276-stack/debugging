#include <string.h>

void safe_string_copy(char *destination, const char *source) {
    int length = strlen(source);
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }
    // BUG: Missing the assignment of the null-terminator byte ('\0') at the end.
    // Reading destination later will leak stack variables or crash.
}
