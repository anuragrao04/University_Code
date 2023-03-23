#include <stdio.h>

int main() {
    int rows, i, j, space;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    

    for(i = 1; i <= rows; i++) {
    
        for(space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        printf("*");
        

        for(j = 1; j < 2 * (i - 1); j++) {
            printf(" ");
        }
        

        if(i != 1) {
            printf("*");
        }
        
        printf("\n");
    }
    

    for(i = rows - 1; i >= 1; i--) {
    
        for(space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        printf("*");
        
        for(j = 1; j < 2 * (i - 1); j++) {
            printf(" ");
        }
        
        if(i != 1) {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}
