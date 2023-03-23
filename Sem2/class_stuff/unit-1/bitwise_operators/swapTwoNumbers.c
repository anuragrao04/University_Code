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
    
    return 0;
}


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