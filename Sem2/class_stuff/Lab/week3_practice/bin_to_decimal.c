#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int binary;
    int n = 0;
    int result = 0;
    printf("Enter the binary value: ");
    scanf("%d", &binary);
    while(binary){
        int last_bit;
        last_bit = binary % 10;
        result += last_bit * pow(2, n);
        n++;
        binary /= 10;
    }
    printf("Integer value: %d\n", result);
    return 0;
}
