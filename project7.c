#include <stdio.h>
#include <string.h>
/*
register
1.login
2.qeydiyyat
3.exit

2 secilibse ad gmail ve password goturulur.
qeyd! gmail evvelden var idise- evvelden qeydiyyatdan kecilibse o mail ile siz artiq qeydiyyatdan kecibsiniz yazilacaq.
yoxdursa, qeydiyyatdan kecdiniz yazilsin


1 secilibse gmail ve password goturulur.
eger evvelden qeydiyyatdan kecilibse siz hesaba daxil oldunuz.
yoxdusa da 'qeydiyyatdan kecin' yazilsin

*/
#define MAX_LOGGER 50
#define CAPACITY 50
struct Login
{
    char gmail[CAPACITY];
    char password[CAPACITY];
} users[MAX_LOGGER];
int listOfChoices()
{
    printf("Choose an option: \n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}
int main()
{
    strcpy(users[0].gmail,"sebnemnezerli@gmail.com");
    strcpy(users[0].password,"12345");
    strcpy(users[1].gmail,"sebnemnezerli2@gmail.com");
    strcpy(users[1].password,"123456");
    strcpy(users[2].gmail,"sebnemnezerli3@gmail.com");
    strcpy(users[2].password,"1234567");
    strcpy(users[3].gmail,"sebnemnezerli4@gmail.com");
    strcpy(users[3].password,"12345678");
    strcpy(users[4].gmail,"sebnemnezerli5@gmail.com");
    strcpy(users[4].password,"123456789");
    switch (listOfChoices())
    {
    case 1:
        printf("Enter your gmail: ");
        char Gmail[CAPACITY];
        scanf("%s", &Gmail);
        printf("Enter your password: ");
        char passWord[CAPACITY];
        scanf("%s", &passWord);
        for (int i = 0; i < MAX_LOGGER; i++)
        {
            if (strcmp(users[i].gmail, Gmail)==0 && strcmp( users[i].password , passWord)==0)
            {
                printf("Logged in successfully.\n");
                break;
            }
            else
            {
                printf("Invalid gmail or password.\n");
                printf("Please register first.\n");
                break;
            }
        }
    case 2:
        printf("Enter your gmail: ");
        char Gmail[CAPACITY];
        scanf("%s", Gmail);
        printf("Enter your password: ");
        char passWord[CAPACITY];
        scanf("%s", passWord);
        for (int i = 0; i < MAX_LOGGER; i++)
        {
            if (strcmp(users[i].gmail,Gmail)==0 && strcmp(users[i].password ,passWord)==0)
            {
                printf("You are already logged in.\n");
                break;
            }
            else{
                for(int i=0;i<MAX_LOGGER;i++){
                    if(strcmp(users[i].gmail,Gmail)!=0){
                        strcpy(users[i].gmail,Gmail);
                        strcpy(users[i].password,passWord);
                    }
                }
            }
        }
        break;
        case 3:
            printf("Goodbye.\n");
            break;
    }
    return 0;
}