#include <stdio.h>
#include <math.h>

int Methods()
{
    printf("\n1. Subtraction\n");
    printf("2. Sum\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Root\n");
    printf("0. Stop\n");
}
int choose(int method, int first, int second)
{
    if (method == 1)
    {
        return first - second;
    }
    else if (method == 2)
    {
        return first + second;
    }
    else if (method == 3)
    {
        return first * second;
    }
    else if (method == 4)
    {
        return first / second;
    }
    else if (method == 5)
    {
        return pow(first, second);
    }
    else if (method == 6)
    {
        return pow(first, 1.0 / second);
    }
}
int main()
{
    int method;
    int first;
    int second;
    while (1)
    {
        Methods();
        printf("Enter what to do: ");
        scanf("%d", &method);

        if (method == 0){
            printf("Stopped.");
        break;
        }

        printf("enter the first number: ");
        scanf("%d", &first);
        printf("enter the second number: ");
        scanf("%d", &second);

        printf("The result is: %d", choose(method, first, second));
    }
    return 0;
}