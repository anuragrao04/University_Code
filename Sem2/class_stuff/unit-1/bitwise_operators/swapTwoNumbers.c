#include <stdio.h>

int main() {
    int a, b;
    
    printf("Enter two numbers to be swapped: ");
    scanf("%d %d", &a, &b);
    
    printf("Before swapping: a = %d, b = %d\n", a, b);
    
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    printf("After swapping: a = %d, b = %d\n", a, b);
    // imagine a = 1, b = 2
    // in binary:
    // a = 01
    // b = 10 

    // a = a ^ b:
    // 01 ^ 10 = 00

    // b = a ^ b:
    // 00 ^ 10 = 01

    // a = a ^ b
    // 00 ^ 01 = 10

    // a = 10 = 2
    // b = 01 = 1


    // USING A TEMP VARIABLE:
    a = 0, b = 0;
    int temp = 0;
    printf("Now using a temp variable. \n");
    printf("Enter two numbers to be swapped: ");
    scanf("%d %d", &a, &b);
    printf("Before swapping: a = %d, b = %d\n", a, b);

    temp = a;
    a = b;
    b = temp;
    
    printf("After swapping: a = %d, b = %d\n", a, b);

    // WITHOUT USING A TEMP VARIABLE
    printf("Now without using a temp variable. \n");
    printf("Enter two numbers to be swapped: ");
    scanf("%d %d", &a, &b);
    printf("Before swapping: a = %d, b = %d\n", a, b);
    a = a + b;  // a now holds the sum of the original values of a and b
    b = a - b;  // b now holds the original value of a
    a = a - b;  // a now holds the original value of b
    printf("After swapping: a = %d, b = %d\n", a, b);



    return 0;
}


