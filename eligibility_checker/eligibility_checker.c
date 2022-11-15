/* DOCUMENTATION:
    name_of_file: eligibility_checker_app.c
    author: ADE OMOTOSHO
    date_created: 06/11/2022
    description: "An app that checks if a citizen is eligible to vote in the upcoming election".
*/
//LINKS
#include <stdio.h>
#include <stdbool.h>

//DEFINATION
#define MIN_VOTING_AGE 18

//DECLARATIONS
int age;
char name[50];
bool checkEligibility(int age);

//MAIN FUNCTION
int main() {
    // Write C code here
    printf("Welcome to eligibility checker!\n");
    printf("Enter your first name: ");
    scanf("%s", name);
    
    printf("enter your age, %s: ", name);
    scanf("%d", &age);
    if(checkEligibility(age)){
        printf("Congratulations %s, you are eligible to vote!", name);
    }else{
        printf("Oops %s!, you are not eligible to vote.", name);

    }
    
    return 0;
}

//SUBPROGRAM
bool checkEligibility(int age){
    if(age < MIN_VOTING_AGE){
        return false;
    }else{
        return true;   
    }
}