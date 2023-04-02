#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 1;
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    for(int i = 1; i <= rows; i++){
        if(i%2 == 0){
            n = 0;
        } else{
            n = 1;
        }
        for(int j = 1; j <= i; j++){
            printf("%d ", n);
            if(n){
                n = 0;
            } else{
                n = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
