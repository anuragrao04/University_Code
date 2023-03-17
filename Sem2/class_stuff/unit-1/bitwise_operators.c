#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Multiplication By 2
    int a = 2;
    printf("2 * 2 is: %d\n", a<<1);
    

    // Division By 2
    int b = 4;
    printf("4 / 2 is %d\n", b>>1);

    // Even Or Odd
    int c = 3;
    (c&1) == 0 ? printf("even\n"): printf("odd\n");
}
