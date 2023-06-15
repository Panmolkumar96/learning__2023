#include <stdio.h>

void printExponent(double x) {
    unsigned long long* ptr = (unsigned long long*)&x;
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;
    
    printf("Exponent in hexadecimal: 0x%llx\n", exponent);
    
    // Convert exponent to binary
    printf("Exponent in binary: 0b");
    for (int i = 10; i >= 0; i--) {
        unsigned long long bit = (exponent >> i) & 1;
        printf("%llu", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);
    return 0;
}
