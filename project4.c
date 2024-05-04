#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//WORD GUESS
int main()
{
    char word[21]; 
    printf("Enter a word (max 20 letters): ");
    scanf("%20s", word);
    
    int length = strlen(word);
    char arr[length];
    int attempts = length+5;

    for (int i = 0; i < length; i++)
    {
        arr[i] = '-';
    }

    for (int j = 0; j < length; j++)
    {
        printf("%c ", arr[j]);
    }
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    // Sozun uzunlugu sayda userden input telebi
    for (int k = 0; k < length; k++)
    {
        char character;
        printf("\nEnter a char: ");
        scanf(" %c", &character);

        attempts--;

        bool found = false;
        for (int l = 0; l < length; l++)
        {
            if (character == word[l])
            {
                found = true;
                arr[l] = character;
            }
        }

        if (found)
        {
            printf("CONGRATS! Found letter: %c\nYou have %d attempts left.\n", character, attempts);
        }
        else
        {
            printf("You failed, continue to guess.. You have %d attempts left.\n", attempts);
        }

        // Print current state of the word
        for (int m = 0; m < length; m++)
        {
            printf("%c ", arr[m]);
        }

        // Check if the word has been completely guessed
        bool allGuessed = true;
        for (int n = 0; n < length; n++)
        {
            if (arr[n] == '-')
            {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed)
        {
            printf("\nCongratulations! You guessed the word.\n");
            break;
        }
    }

    return 0;
}