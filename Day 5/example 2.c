#include <stdio.h>

// Structure for representing a complex number
struct Complex {
    double real;
    double imaginary;
};

// Function to read a complex number from the user
void readComplex(struct Complex* complexPtr) {
    printf("Enter the real part: ");
    scanf("%lf", &(complexPtr->real));
    
    printf("Enter the imaginary part: ");
    scanf("%lf", &(complexPtr->imaginary));
}

// Function to write a complex number
void writeComplex(struct Complex complex) {
    printf("Complex number: %.2f + %.2fi\n", complex.real, complex.imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex complex1, struct Complex complex2) {
    struct Complex result;
    result.real = complex1.real + complex2.real;
    result.imaginary = complex1.imaginary + complex2.imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex complex1, struct Complex complex2) {
    struct Complex result;
    result.real = complex1.real * complex2.real - complex1.imaginary * complex2.imaginary;
    result.imaginary = complex1.real * complex2.imaginary + complex1.imaginary * complex2.real;
    return result;
}

int main() {
    struct Complex complex1, complex2, sum, product;

    // Read the first complex number
    printf("Enter the first complex number:\n");
    readComplex(&complex1);

    // Read the second complex number
    printf("Enter the second complex number:\n");
    readComplex(&complex2);

    // Add the complex numbers
    sum = addComplex(complex1, complex2);

    // Multiply the complex numbers
    product = multiplyComplex(complex1, complex2);

    // Write the complex numbers, sum, and product
    printf("\n");
    writeComplex(complex1);
    writeComplex(complex2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(sum);
    printf("\nProduct of the complex numbers:\n");
    writeComplex(product);

    return 0;
}
