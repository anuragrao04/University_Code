#include <stdio.h>

int main(int argc, char const *argv[])
{
    int rows;
    int n = 1;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(int i = 1;  i <= rows; i++){
        for(int j = 0; j <= rows-i; j++){
            printf(" ");
        }
        for(int j = 1; j <= i; j++){
            printf("%d ", n);
            n++;
        }
        printf("\n");
        
    }
    return 0;
}
