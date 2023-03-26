#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    do {
        if (num1 > num2) {
            num1 -= num2;
        } else if(num1 < num2) {
            num2 -= num1;
        }
    } while (num1 != num2);
    

    printf("GCD is %d\n", num1);
    return 0;
}
