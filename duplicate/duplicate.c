#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    FILE *file = fopen("files.in", "r");
    int number_of_tests;
    int test;
    fscanf(file, "%d", &number_of_tests); // read the first line to get the number of test cases
    for (int i = 0; i < number_of_tests; i++)
    {
        fscanf(file, "%d", &test); // to get the number of files in each test case.
        char file_names[test][11]; // array to store all file names
        int file_id[test];         // array to store all file IDs
        char single_file[11];      // string of file name

        for (int j = 0; j < test; j++)
        {

            int num;
            fscanf(file, "%s", single_file);
            int existence_index;
            // check if a file name exists in the array of file names
            for (int i = 0; i < test; i++)
            {
                if (strcmp(file_names[i], single_file) == 0)
                {
                    existence_index = i; // return the index of where it exists
                    break;
                }
                else
                {
                    existence_index = -1; // return -1 if it doesn't exist
                }
            }
            if (existence_index == -1) // if it doesn't exist, add the file name and id to their respective array.
            {
                strcpy(file_names[j], single_file);
                fscanf(file, "%d", &file_id[j]);
            }
            else // if it exists before, replace the file id at the index
            {
                fscanf(file, "%d", &num);
                if (file_id[existence_index] <= num)
                {
                    /* if the file existing is older, do nothing */
                }
                else
                {
                    file_id[existence_index] = num; // if the file existing is newer, replace the id with the older one
                }
                file_id[j] = -1; // add -1 as the id of repeated files
            }
        }
        int temp = 0;
        //sort the file id array in ascending order
        for (int i = 0; i < test; i++)
        {
            for (int j = i + 1; j < test; j++)
            {
                if (file_id[i] > file_id[j])
                {
                    temp = file_id[i];
                    file_id[i] = file_id[j];
                    file_id[j] = temp;
                }
            }
        }
        // print the ids except the repeated file ids(-1)
        for (int x = 0; x < test; x++)
        {
            if (file_id[x] != -1)
            {
                printf("%d ", file_id[x]);
            }
        }
        printf("\n");
    }
}