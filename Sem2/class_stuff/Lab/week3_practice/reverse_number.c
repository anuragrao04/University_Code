#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    int reverse = 0;
    while(n){
        int temp = n % 10;
        reverse = reverse * 10 + temp;
        n /= 10;
    }
    printf("Reverse is %d\n", reverse);
    return 0;
}
