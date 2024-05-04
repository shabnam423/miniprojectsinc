#include <stdio.h>
#include <string.h>
//QUIZ
struct Question
{
    char answer[2];
    char question[300];
};

int main()
{
    int rights = 0;
    printf("for following questions use capital letters [A/B/C/D]\n");
    struct Question questions[3] = {{"A", "1.Who is the creator of the C language?\nA)Dennis Ritchie\nB)Ken Thompson\nC)Brian Kernighan\nD)Guido van Rossum\n"},
                                    {"A", "2.What does the 'printf' function do in C?\nA)It prints a string to the screen\nB)It prints a number to the screen\nC)It prints a character to the screen\nD)It prints a boolean to the screen\n"},
                                    {"D", "3.Which of the following is not a C data type?\nA)char\nB)int\nC)float\nD)double\n"}};

    
    for (int i = 0; i < 3; i++)
    {
        char userinput[2];
        printf("%s", questions[i].question);
        printf("Your answer: " );
        gets(userinput);
        if (strcmp(userinput, questions[i].answer) == 0)
        {
            rights++;
        }
    }
    printf("You have %d right answers and %d wrong answers", rights, 3 - rights);
    return 0;
}
