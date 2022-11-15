#include <stdio.h>
#include <string.h>

void main(int argc, char* argv[])
{

FILE* file = fopen("adam.in", "r");

char steps[100];
int step_counter = 0;
int number_of_lines = fgetc(file) - '0'; // to cast the char to int 
int line_counter = 0;
while (fgets(steps, sizeof(steps), file))
{
    if (line_counter>0 && line_counter < number_of_lines) // to scrap out the first line and omit the last line
    {
        for(int i=0; i<strlen(steps)-1; i++){
            if (steps[i] == 'D')
            {
                break;
            }else{
                step_counter = step_counter +1;
            }    
            }
            printf("%d\n", step_counter);
            step_counter = 0;
    }else if (line_counter == number_of_lines)//for the last line
    {
        for(int i=0; i<strlen(steps); i++){
            if (steps[i] == 'D')
            {
                break;
            }else{
                step_counter = step_counter +1;
            }    
        }
        printf("%d\n", step_counter);
        step_counter = 0;
    }
    
    line_counter++; //move to the next line
}
}