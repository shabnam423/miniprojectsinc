//fix tryout.c then copy it here

#include <stdio.h>
#include <string.h>
int main()
{

    int attempts;
    char word[20];
    int found; // the elements that have been found

    printf("Enter a word(max 20 elements)");
    scanf("%s", &word);
    found = 0;
    attempts = strlen(word);
    int length = strlen(word);
    char foundletters[length];
    while (found != strlen(word))
    {
        for (int i = 0; i < attempts; i++)
        {
            char character;
            printf("Enter a character: ");
            scanf("%c", character);
            attempts--;

            if (character == word[i])
            {

                printf("Well done! You found a letter!\nAttemps left:%d", attempts);
                word[i] = foundletters[i];

            }
        }
    }


return 0;
}