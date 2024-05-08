#include <stdio.h>

int main()
{
  switch (listOfChoices())
    {
    case 1:
    {
        printf("Enter your gmail: ");
        char Gmail[CAPACITY];
        scanf("%s", Gmail);
        printf("Enter your password: ");
        char passWord[CAPACITY];
        scanf("%s", passWord);
        int found = 0;
        for (int i = 0; i < MAX_LOGGER; i++)
        {
            if (strcmp(users[i].gmail, Gmail) == 0 && strcmp(users[i].password, passWord) == 0)
            {
                printf("Logged in successfully.\n");
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("Invalid gmail or password.\n");
            printf("Please register first.\n");
        }
        break;
    }
    case 2:
    {
        printf("Enter your gmail: ");
        char Gmail[CAPACITY];
        scanf("%s", Gmail);
        printf("Enter your password: ");
        char passWord[CAPACITY];
        scanf("%s", passWord);
        int registered = 0;
        for (int i = 0; i < MAX_LOGGER; i++)
        {
            if (strcmp(users[i].gmail, Gmail) == 0)
            {
                printf("You are already registered.\n");
                registered = 1;
                break;
            }
        }
        if (!registered)
        {
            int emptySlot = -1;
            for (int i = 0; i < MAX_LOGGER; i++)
            {
                if (users[i].gmail[0] == '\0')
                {
                    emptySlot = i;
                    break;
                }
            }
            if (emptySlot != -1)
            {
                strcpy(users[emptySlot].gmail, Gmail);
                strcpy(users[emptySlot].password, passWord);
                printf("You have been registered.\n");
            }
            else
            {
                printf("No more space for registration.\n");
            }
        }
        break;
    }
    case 3:
        printf("Goodbye.\n");
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }
    return 0;
}
