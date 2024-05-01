// Features:
// 1- Book Structure: Define a structure to represent books, including attributes like title,
// author, genre, price, and quantity.
// 2- Book Inventory: Create an array to store information about available books in the shop.
// 3- Add New Book: Implement functionality to add a new book to the inventory. Prompt the
// user to input details such as title, author, genre, price, and quantity.
// 4- Display All Books: Allow the user to display all books in the inventory, showing details
// such as title, author, genre, price, and quantity.
// 5- Search Books: Implement functionality to search for books by title, author, or genre.
// Display the details of matching books.
// 6- Update Book Details: Allow the user to update the details of existing books, such as
// price and quantity.
// 7- Sell Books: Implement functionality to sell books to customers. Prompt the user to
// select a book from the inventory and specify the quantity to sell. Update the quantity of
// the book in the inventory accordingly.
// 8- View Sales Report: Provide an option to view a sales report, showing total sales revenue
// and the quantity of each book sold.
// 9- Save and Load Data: Add functionality to save the book inventory and sales data to a
// file, allowing users to persist data between sessions.

#include <stdio.h>

struct Book
{
    char title[50];
    char author[50];
    char genre[50];
    float price;
    int quantity;
};
int main()
{

    return 0;
}
