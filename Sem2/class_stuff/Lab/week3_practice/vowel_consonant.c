#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char a;
    int vowel = 0;
    printf("Enter the Character: ");
    scanf(" %c", &a);
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    for(int i = 0; i < sizeof(vowels)/sizeof(vowels[0]); i++){
        if(tolower(a) == vowels[i]){
            vowel = 1;
            break;
        }
    }

    vowel? printf("vowel\n") : printf("not a vowel\n");

    return 0;
}

