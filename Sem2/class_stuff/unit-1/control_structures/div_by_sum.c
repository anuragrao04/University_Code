#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum, number;
    printf("Enter the number: ");
    scanf("%d", &number);

    sum = 0;
    while (number > 0){
        sum += number % 10;
        number /= 10;
    }
    if(number % sum == 0){
        printf("Number is divisible by the sum of its digits\n");
    } else{
        printf("Number is not divisible by the sum of its digits");
    }

    return 0;
}
