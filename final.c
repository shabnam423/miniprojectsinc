// Features:
// 1- Book Structure: Define a structure to represent books, including attributes like title,
// author, genre, price, and quantity.  ++
// 2- Book Inventory: Create an array to store information about available books in the shop.  ++
// 3- Add New Book: Implement functionality to add a new book to the inventory. Prompt the
// user to input details such as title, author, genre, price, and quantity.     ++
// 4- Display All Books: Allow the user to display all books in the inventory, showing details
// such as title, author, genre, price, and quantity.   ++
// 5- Search Books: Implement functionality to search for books by title, author, or genre.
// Display the details of matching books.   ++
// 6- Update Book Details: Allow the user to update the details of existing books, such as
// price and quantity.  ++
// 7- Sell Books: Implement functionality to sell books to customers. Prompt the user to
// select a book from the inventory and specify the quantity to sell. Update the quantity of
// the book in the inventory accordingly.   ++
// 8- View Sales Report: Provide an option to view a sales report, showing total sales revenue
// and the quantity of each book sold.
// 9- Save and Load Data: Add functionality to save the book inventory and sales data to a
// file, allowing users to persist data between sessions.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Red "\x1b[31m"
#define Yellow "\x1b[33m"
#define Blue "\x1b[34m"
#define Magenta "\x1b[35m"
#define Cyan "\x1b[36m"
#define Gray "\x1b[90m"
#define Light_Red "\x1b[91m"
#define Green "\x1b[32m"
#define Reset "\x1b[0m"

#define MAX_BOOKS 50
struct Book
{
    char title[50];
    char author[50];
    char genre[50];
    float price;
    int quantity;
};
int List(int choice);
void ShowBooks(struct Book bookArray[MAX_BOOKS]);
int UpdateBookDetails(struct Book bookArray[MAX_BOOKS]);
int UpdateBookDetails(struct Book bookArray[MAX_BOOKS])
{
    int choice;
    int i;

    printf("Enter the index of the book you want to update: ");
    scanf("%d", &i);

    if (i < 0 || i >= MAX_BOOKS)
    {
        printf("Invalid book index.\n");
        return 0;
    }
    if (strcmp(bookArray[i].title, "") == 0)
    {
        printf("Book not found.\n");
        return 0;
    }
    printf("Enter 1 to update price, 2 to update quantity: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter the new price: ");
        scanf("%f", &bookArray[i].price);
    }
    else if (choice == 2)
    {
        printf("Enter the new quantity: ");
        scanf("%d", &bookArray[i].quantity);
    }
    else
    {
        printf("Invalid choice.\n");
        return 0;
    }
}

int List(int choose)
{
printf("***************************************************\n");
    printf("1. Display all Books: \n");
    printf("2. Add New Book \n");
    printf("3. Search Books: \n");
    printf("4. Update Book Details \n"); // only price & quantity
    printf("5. Sell Books \n");
    printf("6. View Sales Report \n");
    printf(Red "7. Exit \n" Reset);
    printf("Choose an option: \n");
    scanf("%d", &choose);
    if(choose == 7){
        printf(Cyan"Thank you for using our program!\n"Reset);
        exit(0);
    }
    return choose;
}
void ShowBooks(struct Book bookArray[MAX_BOOKS])
{ 
    for (int i = 0; i < MAX_BOOKS; i++)
    {
        if(bookArray[i].quantity != 0){
        printf(Light_Red"Book %d: "Reset, i + 1);
        printf("\"%s\" by %s, Genre: %s, Price: $%.2f, Quantity: %d\n", bookArray[i].title, bookArray[i].author, bookArray[i].genre, bookArray[i].price, bookArray[i].quantity);
    }
    }
}

int main()
{
    struct Book soldBook[MAX_BOOKS];
    struct Book bookArray[MAX_BOOKS];
    int soldBookindex = 0;
    strcpy(bookArray[0].title, "The Great Gatsby");
    strcpy(bookArray[0].author, "F. Scott Fitzgerald");
    strcpy(bookArray[0].genre, "Fiction");
    bookArray[0].price = 10.99;
    bookArray[0].quantity = 5;

    strcpy(bookArray[1].title, "To Kill a Mockingbird");
    strcpy(bookArray[1].author, "Harper Lee");
    strcpy(bookArray[1].genre, "Fiction");
    bookArray[1].price = 9.99;
    bookArray[1].quantity = 3;

    strcpy(bookArray[2].title, "Pride and Prejudice");
    strcpy(bookArray[2].author, "Jane Austen");
    strcpy(bookArray[2].genre, "Fiction");
    bookArray[2].price = 7.99;
    bookArray[2].quantity = 2;

    strcpy(bookArray[3].title, "The Catcher in the Rye");
    strcpy(bookArray[3].author, "J.D. Salinger");
    strcpy(bookArray[3].genre, "Fiction");
    bookArray[3].price = 8.99;
    bookArray[3].quantity = 1;
    printf(Magenta "Welcome to the Book Store!\n" Reset);
    
    // char choose=WantToContinue();
    // if(choose=='y'){
    // while (choose == 'y'){

    while(1){
        int choice;
        int choose;
        
        choice=List(choose);
        if (choice == 1)
        {
            ShowBooks(bookArray);
        }
        else if (choice == 2)
        {
            int i;
            printf("Enter the number of books you want to add: ");
            scanf("%d", &i);
            if (i > 45)
            {
                printf("Book not added. Please enter a valid number of books. \n");
                scanf("%d", &i);
            }
            for (int j = 0; j < i; j++)
            {
                printf("Enter the details of book %d:\n", j + 1);
                printf("Title: ");
                scanf("%s", bookArray[j].title);
                printf("Author: ");
                scanf("%s", bookArray[j].author);
                printf("Genre: ");
                scanf("%s", bookArray[j].genre);
                printf("Price: ");
                scanf("%f", &bookArray[j].price);
                printf("Quantity: ");
                scanf("%d", &bookArray[j].quantity);
                printf("\n");
            }
        }
        else if (choice == 3)
        {
            printf("Enter 1 to search by title, 2 to search by author, 3 to search by genre: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the title of the book you want to search: ");
                char title[50];
                scanf("%s", title);
                for (int i = 0; i < MAX_BOOKS; i++)
                {
                    if (strcmp(title, bookArray[i].title) == 0)
                    {
                        printf("\"%s\" by %s, Genre: %s, Price: $%.2f, Quantity: %d\n", bookArray[i].title, bookArray[i].author, bookArray[i].genre, bookArray[i].price, bookArray[i].quantity);
                    }
                }
            }
            else if (choice == 2)
            {
                printf("Enter the author of the book you want to search: ");
                char author[50];
                scanf("%s", author);
                for (int i = 0; i < MAX_BOOKS; i++)
                {
                    if (strcmp(author, bookArray[i].author) == 0)
                    {
                        printf("\"%s\" by %s, Genre: %s, Price: $%.2f, Quantity: %d\n", bookArray[i].title, bookArray[i].author, bookArray[i].genre, bookArray[i].price, bookArray[i].quantity);
                    }
                }
            }
            else if (choice == 3)
            {
                printf("Enter the genre of the book you want to search: ");
                char genre[50];
                scanf("%s", genre);
                for (int i = 0; i < MAX_BOOKS; i++)
                {
                    if (strcmp(genre, bookArray[i].genre) == 0)
                    {
                        printf("\"%s\" by %s, Genre: %s, Price: $%.2f, Quantity: %d\n", bookArray[i].title, bookArray[i].author, bookArray[i].genre, bookArray[i].price, bookArray[i].quantity);
                    }
                }
            }
            else
            {
                printf("Invalid choice. Please try again and enter a valid choice: \n");
                scanf("%d", &choice);
            }
        }
        else if (choice == 4)
        {
            UpdateBookDetails(bookArray);
        }
        else if (choice == 5)
        {
            ShowBooks(bookArray);
            int i;

            printf("Select the index of the book you want to sell: ");
            scanf("%d", &i);
            if (i < 0 || i >= MAX_BOOKS)
            {

                printf("Invalid book index.\n");
                printf("Try again...\nSelect the index of the book you want to sell: ");
                scanf("%d", &i);
            }

            // kitabin indexin goturduk-indi sat-yeni sil o kitabi.
            // if choice==6:     //6. View Sales Report
            /*soldBook arrayini for icine aliriq ve ve ordaki melumatlari file icine yaziriq*/

            soldBook[soldBookindex] = bookArray[i - 1];
            soldBookindex++;
            bookArray[i - 1].quantity--;
            for (int j = i; j < MAX_BOOKS; ++j)
            {
                strcpy(bookArray[j].title, bookArray[j + 1].title);
                strcpy(bookArray[j].author, bookArray[j + 1].author);
                strcpy(bookArray[j].genre, bookArray[j + 1].genre);
                bookArray[j].price = bookArray[j + 1].price;
                bookArray[j].quantity = bookArray[j + 1].quantity;
            }
        }
        else if (choice == 6)
        {
            FILE *file;
            file = fopen("text.txt", "a");
            for (int i = 0; i < soldBookindex; i++)
            {
                fprintf(file, "%s %s %s %.2f %d\n", soldBook[i].title, soldBook[i].author, soldBook[i].genre, soldBook[i].price, soldBook[i].quantity);
            }
            fclose(file);
        }
        
        ShowBooks(bookArray);
    }
    return 0;
}