#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    printf("a: ");
    scanf("%d", &a);
    if(a % 7 == 0){
        printf("Divisible by 7\n");
    } else{
        printf("Not divisible by 7\n");
    }
    return 0;
}
