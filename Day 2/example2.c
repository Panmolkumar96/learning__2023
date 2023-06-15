#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char* charA = (char*)a;
    char* charB = (char*)b;
    
    for (size_t i = 0; i < size; i++) {
        char temp = charA[i];
        charA[i] = charB[i];
        charB[i] = temp;
    }
}

int main() {
    int a = 5;
    int b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    swap(&a, &b, sizeof(int));
    
    printf("After swap: a = %d, b = %d\n", a, b);
    
    float c = 2.5;
    float d = 3.7;
    printf("Before swap: c = %.2f, d = %.2f\n", c, d);
    
    swap(&c, &d, sizeof(float));
    
    printf("After swap: c = %.2f, d = %.2f\n", c, d);
    
    return 0;
}
