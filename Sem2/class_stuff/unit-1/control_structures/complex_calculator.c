#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    char operation; 
    
    printf("Enter first complex number (a b): ");
    scanf("%d %d", &a, &b);
    printf("Enter second complex number (c d): ");
    scanf("%d %d", &c, &d);
    printf("What operation do you want to perform (+, -, *): ");
    scanf(" %c", &operation);
    

    switch(operation){
        case '+':
            printf("%d+%di\n", a+c, b+d);
            break;
        case '-':
            printf("%d+%di\n", a-c, b-d);
            break;
        case '*':
            printf("%d+%di\n", a*c - b*d, a*d + b*c);
            break;
        default:
            printf("Unrecognised Operator, Quiting\n");
            break;
    }

    return 0;
}
