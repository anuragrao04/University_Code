#include <stdio.h>

int main(int argc, char const *argv[])
{
    float x, y;
    int a, b, c;
    char c1, c2;
    scanf("%d%d%d", &a, &b, &c);
    scanf("%d, %d, %d", &a, &b, &c);
    scanf("%f%f", &x, &y);
    scanf("%c%c", &c1, &c2);
    int n = printf("one\n");
    int m = printf("1000\n");
    printf("a is %d\n", a);
    printf("b is %d\n", b);
    printf("c is %d\n", c);
    printf("x is %f\n", x);
    printf("y is %f\n", y);
    printf("c1 is %c\n", c1);
    printf("c2 is %c\n", c2);
    printf("n is %d\n", n);
    printf("m is %d\n", m);
    return 0;
}
