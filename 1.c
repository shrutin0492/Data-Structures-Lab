#include <stdio.h>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two integers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two integers
float divide(int a, int b) {
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0.0;
    }
}

// Function to calculate modulo of two integers
int modulo(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Modulo by zero!\n");
        return 0;
    }
}

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Sum: %d\n", add(num1, num2));
    printf("Difference: %d\n", subtract(num1, num2));
    printf("Product: %d\n", multiply(num1, num2));
    
    if (num2 != 0) {
        printf("Quotient: %.2f\n", divide(num1, num2));
        printf("Modulo: %d\n", modulo(num1, num2));
    }

    return 0;
}
