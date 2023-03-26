#include <stdio.h>

int main() {
    int rows, i, j, space;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    // Upper half of the diamond
    for(i = 1; i <= rows; i++) {
        // Spaces before the first star
        for(space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        // First star
        printf("*");
        
        // Spaces between the stars
        for(j = 1; j < 2 * (i - 1); j++) {
            printf(" ");
        }
        
        // Last star
        if(i != 1) {
            printf("*");
        }
        
        printf("\n");
    }
    
    // Lower half of the diamond
    for(i = rows - 1; i >= 1; i--) {
        // Spaces before the first star
        for(space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        // First star
        printf("*");
        
        // Spaces between the stars
        for(j = 1; j < 2 * (i - 1); j++) {
            printf(" ");
        }
        
        // Last star
        if(i != 1) {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}
