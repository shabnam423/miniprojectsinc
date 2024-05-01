/*
kitapxana


 siyahi secim    -choice




----------------

1.kitab elave edin    -add
2.siyahini goster (kitab)  -show
3.umumi sayi  - book_count
4.sehife sayi en cox olani gostermek   -max
5.kitablar arasinda axtaris       -search
6.programdan cixmaq   -exit

-----------------
kitabin adini:
muellifini
sehife sayini daxil edin
----------
kitablarin adlari txt faylinda olacaq

*/

#include <stdio.h>

struct Books
{
    char name[50];
    char author_name[100];
    int page_count;
}book1 = {"Annihilation","VanderMeer",195},
book2 = {"1Q84","Haruki",1000}
;
int Choice(int choice)
{
    printf("Choose from down below:");
    printf("1.Add a book");
    printf("2.Show the list of books");
    printf("3.Show the number of books");
    printf("4.Which one has the most pages?");
    printf("5.Search through the books");
    printf("6.Quit");

    scanf("%d", choice);
    return choice;
}

int main()
{
    int choice;
    int exit = 6;
    int page;
    char nameOfbook[20];
    char nameOfauthor[30];
    int inputbooks;

    Choice(choice);
    while (choice != 6)
    {
        printf("%d", Choice(choice));
    }
    if (choice = 1)
    {
        printf("Enter the number of books you want to add: ");
        scanf("%d", &inputbooks);
        printf("Add the name of the book: ");
        scanf("%s", &nameOfbook);
        printf("Enter the author: ");
        scanf("%s", &nameOfauthor);
        printf("Enter the size of the book: ");
        scanf("%d", &page);

    }

    return 0;
}
/*
#include <stdio.h>

struct Books
{
    char name[50];
    char author_name[100];
    int page_count;
};

int Choice()
{
    int choice;
    printf("\nChoose from below:\n");
    printf("1. Add a book\n");
    printf("2. Show the list of books\n");
    printf("3. Show the number of books\n");
    printf("4. Which one has the most pages?\n");
    printf("5. Search through the books\n");
    printf("6. Quit\n");

    scanf("%d", &choice);
    return choice;
}

void SaveBooksToFile(struct Books books[], int numBooks)
{
    FILE *file = fopen("books.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numBooks; i++)
    {
        fprintf(file, "%s;%s;%d\n", books[i].name, books[i].author_name, books[i].page_count);
    }

    fclose(file);
}

int main()
{
    struct Books books[100];

    int choice;
    int numBooks = 0;
    int i;

    do
    {
        choice = Choice();

        switch (choice)
        {
        case 1:
            printf("Enter the number of books you want to add: ");
            int inputBooks;
            scanf("%d", &inputBooks);

            for (i = 0; i < inputBooks; i++)
            {
                printf("Enter the name of book %d: ", numBooks + 1);
                scanf("%s", books[numBooks].name);
                printf("Enter the author of book %d: ", numBooks + 1);
                scanf("%s", books[numBooks].author_name);
                printf("Enter the page count of book %d: ", numBooks + 1);
                scanf("%d", &books[numBooks].page_count);

                numBooks++;
            }

           
            SaveBooksToFile(books, numBooks);
            printf("Books saved to file.\n");
            break;

        case 2:
            printf("\nList of books:\n");
            for (i = 0; i < numBooks; i++)
            {
                printf("%d. %s by %s, %d pages\n", i + 1, books[i].name, books[i].author_name, books[i].page_count);
            }
            break;

        case 3:
            printf("\nNumber of books: %d\n", numBooks);
            break;

               case 4:
            if (numBooks > 0)
            {
                int maxPagesIndex = 0;
                for (i = 1; i < numBooks; i++)
                {
                    if (books[i].page_count > books[maxPagesIndex].page_count)
                        maxPagesIndex = i;
                }
                printf("\nThe book with the most pages is %s by %s with %d pages.\n", books[maxPagesIndex].name, books[maxPagesIndex].author_name, books[maxPagesIndex].page_count);
            }
            else
            {
                printf("\nNo books added yet.\n");
            }
            break;

        case 5:
            // Add search functionality
            break;

        case 6:
            printf("\nExiting program.\n");
            break;

        default:
            printf("\nInvalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

*/