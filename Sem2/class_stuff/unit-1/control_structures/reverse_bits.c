#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    unsigned int n;
    int binary[32]; //to store the binary representation of n
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    int bits_occupied = 0; //stores number of bits actually occupied out of 32 by the input number
    int num = n;
    while(num > 0){
        bits_occupied++;
        num = num >> 1;
    }
    

    for(int i = 0; n>0; i++){
        binary[i] = n%2; //store remainder (0 or 1) in array
        n = n/2; //update n to next quotient
    }

    int reversed_int = 0;

    printf("Binary representation in reverse: ");

    for(int i = 0; i <= bits_occupied; i++){
        printf("%d", binary[i]);
        reversed_int += binary[i] * pow(2, bits_occupied-i); //calculate integer equivalent
    }

    printf("\n");
    printf("Reversed Integer: %d \n", reversed_int);

    return 0;
}
