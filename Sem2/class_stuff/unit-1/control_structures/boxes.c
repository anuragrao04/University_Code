#include <stdio.h>

#define TUNNEL_HEIGHT 41

int main(int argc, char const *argv[])
{
    float length, width, height;
    printf("Enter length, width and height of your box: ");
    scanf("%f %f %f", &length, &width, &height);
    if(height >= TUNNEL_HEIGHT){
        printf("Box won't pass through!\n");
    } else{
        float volume = length * width * height;
        printf("Box will pass through, the volume is: %0.3f\n", volume);
    }

    return 0;
}
