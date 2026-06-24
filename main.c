#include <stdio.h>
#include "src/basic-encryption.h"
int main() {

    char* hello_hi = encrypt("hello","hi");
    printf("\n%s\n",hello_hi);
    free(hello_hi);
    return 0;
}