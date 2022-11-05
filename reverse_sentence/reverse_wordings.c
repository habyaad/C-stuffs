#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char sentence[1000];
    printf("enter your sentence: ");
    fgets(sentence, 999, stdin);
    int lengthOfSentence = strlen(sentence)-1; //-1 to remove the last null characte.r

    for (int i = 0; i < lengthOfSentence; i++)
    {
        printf("%c", sentence[lengthOfSentence-i-1]);
    }    
    
}
