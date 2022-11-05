#include <stdio.h>

int main(){
    int studentsNumber;
    printf("enter the number of students: ");
    scanf("%d", &studentsNumber);
    
    getchar();//to remove the /n kept in the buffer so it doesn't interfere with fgets.

    char name[studentsNumber][50];

    for (int i = 0; i < studentsNumber; i++)
    {
        printf("enter the name of student %d: ", i+1);
        fgets(name[i], 40, stdin);
    }
    printf("Student name(s): \n");
    for (int i = 0; i < sizeof(name)/sizeof(name[0]); i++)
    {
        printf("%s", name[i]);
    }
    
    
    return 0;
}