#include <stdio.h>

int count(int numberRange){
    for (int i = 1; i <= numberRange; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int numberRange;
    printf("enter the number N: ");
    scanf("%d", &numberRange);
    count(numberRange);
    return 0;
}
