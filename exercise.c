#include <stdio.h>

float squareRoot(float num) {
    float guess = num / 2;
    float tolerance = 0.0001; 
    
    while ((guess * guess - num) > tolerance || (num - guess * guess) > tolerance) {
        guess = (guess + num / guess) / 2;
    }
    
    return guess;
}

int main() {
    float num;
    printf("Enter a number: ");
    scanf("%f", &num);
    
    if (num < 0) {
        printf("Square root of a negative number is not real.\n");
    } else {
        printf("Square root of %.2f is %.5f\n", num, squareRoot(num));
    }
    
    return 0;
}
