#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);


    // using while loop
    while (num1 != num2) {
        if (num1 > num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
    }



    printf("GCD is %d\n", num1);


    return 0;
}



