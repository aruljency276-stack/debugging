#include <stdio.h>

char* generate_system_status() {
    // 🪲 BUG: 'status' is allocated on the local function execution STACK framework.
    // As soon as this function returns, this memory area is reclaimed/wiped out.
    char status[] = "SYSTEM_OPERATIONAL_ONLINE"; 
    return status; 
}
