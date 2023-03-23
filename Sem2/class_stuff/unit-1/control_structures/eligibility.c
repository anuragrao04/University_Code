#include <stdio.h>

int main() {
    int math, physics, chemistry, total;
    
    printf("Enter marks in math: ");
    scanf("%d", &math);
    printf("Enter marks in physics: ");
    scanf("%d", &physics);
    printf("Enter marks in chemistry: ");
    scanf("%d", &chemistry);
    
    total = math + physics + chemistry;
    
    if (math >= 65 && physics >= 50 && chemistry >= 55 && (total >= 190 || math + physics >= 140)) {
        printf("The candidate is eligible for admission.\n");
    } else {
        printf("The candidate is not eligible for admission.\n");
    }
    
}
