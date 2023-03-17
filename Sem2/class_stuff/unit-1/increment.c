#include <stdio.h>

int main(int argc, char const *argv[])
{
    int b = 5;
    b -= --b - b--;
    printf("%d\n", b);
    return 0;
}