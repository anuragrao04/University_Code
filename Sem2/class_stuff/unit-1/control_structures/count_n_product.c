#include <stdio.h>
int main(int argc, char const *argv[]) {
    int n;
    int count = 0;
    scanf("%d", &n);
    
    for(int i = n; i > 1; i--){
        for(int j = n; j > 1; j-- ){
            if(i * j == n && i != 1 && j != 1){
                // if equal numbers, count twice. because they should iterate twice. doesn't make sense but that's what the teacher told-
                if(i == j){
                    count += 2; 
                }else{
                    count++;
                }
                
            }
        }
    }

    printf("Count: %d\n", count);
}
