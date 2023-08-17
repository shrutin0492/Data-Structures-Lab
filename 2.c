#include <stdio.h>

// Function to calculate the sum of digits of a number recursively
int sumOfDigits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return (num % 10) + sumOfDigits(num / 10);
    }
}

// Function to reverse a number recursively
int reverseNumber(int num) {
    static int reversedNum = 0;
    if (num == 0) {
        return reversedNum;
    } else {
        reversedNum = (reversedNum * 10) + (num % 10);
        return reverseNumber(num / 10);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int sum = sumOfDigits(num);
    printf("Sum of digits: %d\n", sum);

    int reversed = reverseNumber(num);
    printf("Reverse of the number: %d\n", reversed);

    return 0;
}
