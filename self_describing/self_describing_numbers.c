#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check and return how many times a number exist in an array of numbers
int check(char *check, int checker, bool isLast)
{
    int length;
    if (isLast)
    {
        length = strlen(check);
    }
    else
    {
        length = strlen(check) - 2;
    }

    int j, count = 0;
    for (j = 0; j < length; j++)
    {
        if (check[j] - '0' == checker)
        {
            count++;
        }
    }
    return count;
}
void main(int argc, char const *argv[])
{
    char number[12];
    FILE *file = fopen("self.in", "r"); // read the input file
    int counter = 0;
    int number_of_test = fgetc(file) - '0'; // read the first line(test case line)
    while (fgets(number, 12, file))
    {
        // condition to check from the second line(skip the number of test case line) to the second to the last line because of the new line character they have
        if (counter > 0 && counter < number_of_test)
        {
            int correct = 0;
            for (int i = 0; i < strlen(number) - 2; i++)
            {
                if (check(number, i, false) == number[i] - '0')
                {
                    correct++; // if the number of the ith index in the array is equal to the ith value, increment count
                }
                else
                {
                    break; // else stop.
                }
            }
            if (correct == strlen(number) - 2)
            {
                printf("self-describing\n"); // if it is correct for all the numbers in the array, then it is self-describing
            }
            else
            {
                printf("not self-describing\n"); // else it is not.
            }
        }
        else if (counter == number_of_test)
        { // condition for the last line which has no new line character after it
            int correct = 0;
            for (int i = 0; i < strlen(number); i++)
            {
                if (check(number, i, true) == number[i] - '0')
                {
                    correct++;
                }
                else
                {
                    break;
                }
            }
            if (correct == strlen(number))
            {
                printf("self-describing\n");
            }
            else
            {
                printf("not self-describing\n");
            }
        }
        counter++;
    }
}
