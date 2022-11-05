#include <stdio.h>
#include <math.h>

int main()
{
    float xSquaredCoefficient;
    float xCoefficient;
    float constantNumber;

    printf("enter the value of the co-effiecient of x-squared: ");
    scanf("%f", &xSquaredCoefficient);

    printf("enter the value of the co-effiecient of x: ");
    scanf("%f", &xCoefficient);
 
    printf("enter the value of the constant: ");
    scanf("%f", &constantNumber);

    float determinant = pow(xCoefficient, 2) - (4*xSquaredCoefficient*constantNumber);

    if(determinant < 0.0){
        printf("Cannot solve, the quadratic equation does not have a real answer!\n");
    }else{
        float firstRoot = (-(xCoefficient) + sqrt(determinant))/(2*xSquaredCoefficient);
        float secondRoot = (-(xCoefficient) - sqrt(determinant))/(2*xSquaredCoefficient);
    
        printf("your roots are %.2f and %.2f", firstRoot, secondRoot);
    }
    

    return 0;
}
