/*
    * Name : Muhammad F. Khan
    * Class : PROG12974 1234_56789, Fall 2019 
    * Assignment : Assignment #3 â€“ Book Manager
    * Date : November 29, 2019 
    * Program : assignment4_khan.c
    * Description : a book managing program 
*/

// Imports
#include <stdio.h>  // Standard I/O
#include <stdlib.h> // Standard Library
#include <string.h> // For string function
#include <ctype.h>  // Type checking
#include <unistd.h> // For checking if file exists

// Definations
#define MAX_BOOKS 100                     // max number of books
#define DB_FILE_NAME "books_database.csv" // file to read from
#define MAX_READ_BUFFER 19400    //  (3 + 1 + 45 + 45 + 100) * 100 = 19400 bytes

// STRUCT
struct book
{
    int id;
    int category;
    char title[45];
    char author[45];
    char note[100];
} database[MAX_BOOKS];

// ARRAY OF CATEGORIES
char Categories[6][12] = {"IGNORE", "Arts", "Languages", "Computers", "Novels", "Others"};

// function definations
/*
 * NAME: menu();
 * DEFINATION: print menu to screen
 * ARGUMENTS: None
 * RETURNS: None
*/
void menu(); // prints  menu

/*
 * NAME: checkFileExistance();
 * DEFINATION: checks if a file exists aka accessible or not
 * ARGUMENTS: None
 * RETURNS:
 *  0 - If file is found aka accessible
 *  1 - If file is not found aka not accessible
*/
int checkFileExistance(); // checks if file exists

/*
 * NAME: readFromFile();
 * DEFINATION: Reads data from file
 * ARGUMENTS: [ARRAY OF STRUCTS(book)] database array, [INTEGER] position
 * RETURNS: position aka the number of elements in array
*/
int readFromFile(struct book database[], int position); // reads data from file

/*
 * NAME: findBookByID();
 * DEFINATION: Finds book by given in database array
 * ARGUMENTS: [ARRAY OF STRUCTS(book)] database array, [INTEGER] position, [INTEGER] book id
 * RETURNS:
 *  0 - if book is found
 *  1 - if book not found
*/
int findBookByID(struct book database[], int position, int id); // reads data from file

/*
 * NAME: listAllBooks();
 * DEFINATION: Lists all books in database array
 * ARGUMENTS: [ARRAY OF STRUCTS(book)] database array, [INTEGER] position, [INTEGER] starting point 
 * RETURNS: NONE
*/
void listAllBooks(struct book database[], int position, int start);

/*
 * NAME: writeBooksToFile();
 * DEFINATION: writes passed book to file "books_database.csv"
 * ARGUMENTS: [ARRAY OF STRUCTS(book)] database array, [INTEGER] position of the book
 * RETURNS: 
 *  0 - if saved successfully
 *  1 - if not saved successfully
*/
void writeBooksToFile(struct book database[], int position);

/*
 * NAME: addBook();
 * DEFINATION: adds book to database array and file "books_database.csv"
 * ARGUMENTS: [ARRAY OF STRUCTS(book)] database array, [INTEGER] position of the next book
 * RETURNS: New position[index] value [Integer]
*/
int addBook(struct book database[], int position);

/*
 * NAME: addBook();
 * DEFINATION: adds book to database array and file "books_database.csv"
 * ARGUMENTS: [Char] String from which the newline '\n' character needs to be removed
 * RETURNS: None
*/
void removeNewLineCharacter(char *string);

/*
 * Description: Converts String from uppercase to lowercase
 * Parameters: A string of lowercase characters (string)
 * Returns: None
*/
void lowerCaseString(char *string);

/*
 * NAME: returnBookIndex();
 * DEFINATION: retruns book index from  within the database array
 * ARGUMENTS: [ARRAY OF STRUCTS(book)] database array, [INTEGER] position of the next book, [INTEGER] id of the book to look for 
 * RETURNS: 
 *  n - the index of the book in database array
 *  -1 - if the book is not found
*/
int returnBookIndex(struct book database[], int position, int id);

int main(void)
{
    // VARIABLES
    char userInput[45];    // holding userinput
    int option;            // holds user menu option
    int i;                 // holds book id
    int position = 0;      // next position/index to save new book
    int flag = 1;          // for keeping the program running
    int y_n_option;        // holds if the users want to delete the book or not
    int bookIndex;         // holds the index of the book
    int tempIntValue;      // holds temporary integer values
    char tempCharValue[4]; // holds temporary char/string values

    printf("=== Book Manager ===\n"); // program name prompt
    menu();                           // printing the menu

    while (flag)
    { // loop infintely - unless user wants to exit
        // ATTEMPT TO READ DATABASE - READ AT EACH ITERATION TO KEEP THE DATABASE UPDATE
        position = readFromFile(database, position); // new position

        printf("\nEnter your choice: "); // input prompt
        fgets(userInput, 3, stdin);      // reading userInput
        option = atoi(userInput);        // char to int
        // Possible Options
        if (option == 0)
        { // if the user wants to exit
            flag = 0;
            printf("=== THANK YOU, BYE-BYE!\n");
            exit(0);
        }
        else if (option == 1)
        {
            printf("=== LIST ALL BOOKS ===\n");
            position = readFromFile(database, position); // new position is returned if a items are appended to array
            listAllBooks(database, position, 0);         // printing all items in array
        }
        else if (option == 2)
        {
            printf("=== ADD A NEW BOOK ===\n");
            position = addBook(database, position); // add new book
        }
        else if (option == 3)
        {
            printf("=== DELETE A BOOK ===\n");                   // prompt
            printf("=== Enter book ID to delete ( 1 - 100 ): "); // prompt
            fgets(tempCharValue, 4, stdin);                      // reading user input from standard input
            // validatiing if input is between 1 and 100
            tempIntValue = atoi(tempCharValue); // casting char/string to integer
            if (1 <= tempIntValue && tempIntValue <= 100)
            { // between 1-100 inclusive
                if (findBookByID(database, position, tempIntValue) == 0)
                {                                                                  // if a match is found for the book
                    bookIndex = returnBookIndex(database, position, tempIntValue); // getting book index
                    listAllBooks(database, bookIndex + 1, bookIndex);              // printing book details
                    printf("=== Are you sure (Y/N): ");                            // prompt
                    y_n_option = getchar();                                        // reading character from standard input
                    // fgets(tempCharValue, 3, stdin); // reading userinput from standard input
                    if (y_n_option == 'y' || y_n_option == 'Y')
                    {
                        // set that struct id to NULL
                        database[bookIndex].id = 0;
                        // in the writeTOFile function make sure you don't write NULL id elements
                        writeBooksToFile(database, position);
                        printf("=== Book Deleted.\n"); // prompt
                    }
                    while (getchar() != '\n')
                        ;
                }
                else
                {                                                           // if book does not exist
                    printf("=== Book #%d does not exist.\n", tempIntValue); // prompt
                }
            }
        }
        else if (option == 4)
        {
            printf("=== SEARCH A BOOK BY ID ===\n");
            printf("=== Enter Book ID to search (1 - 100): "); // prompt
            fgets(tempCharValue, 4, stdin);                    // reading user input from standard input
            tempIntValue = atoi(tempCharValue);                // casting from char/string to integer
            if (tempIntValue >= 1)
            { // between 1-100 inclusive
                if (tempIntValue <= 100)
                {
                    if ((bookIndex = returnBookIndex(database, position, tempIntValue)) != -1)
                    {
                        listAllBooks(database, position, bookIndex);
                    }
                    else
                    {
                        printf("=== Book #%d does not exist.\n", tempIntValue); // prompt
                    }
                }
                else
                {
                    printf("=== Invlaid Book ID\n");
                }
            }
            else
            {
                printf("=== Invalid Book ID\n");
            }
        }
        else if (option == 5)
        {           // if the user wants to view the menu again
            menu(); // calling the menu function again
        }
        else
        {
            printf("== Incorrect choice!\nEnter 0 to view the menu agian.\n");
        }
    }
}

// PRINTING MENU
void menu()
{
    // MENU PROMPTS
    printf("====== MAIN ======\n");
    printf("0 - Exit Program\n");
    printf("1 - List all Books\n");
    printf("2 - Add a New Book\n");
    printf("3 - Delete a Book\n");
    printf("4 - Search a Book by ID\n");
    printf("5 - Show this menu again\n");
    printf("==================\n");
}

// CHECKING IF FILE EXISTS
int checkFileExistance()
{
    if (access(DB_FILE_NAME, F_OK) != -1)
    {
        return 0; // file exists
    }
    return 1; // file doesn't exist
}

// FIND BOOK ID
int findBookByID(struct book database[], int position, int id)
{
    // iterating over all elements in database array in an attempt to find the book
    for (int i = 0; i < position; i++)
    {
        if (database[i].id == id)
        {
            return 0; // if book found
        }
    }
    return 1; // if book not found
}

void listAllBooks(struct book database[], int position, int start)
{
    int i; // starting point
    if (position > 0)
    { // if there are books in database array
        for (i = start; i <= position - 1; i++)
        { // loop over each book
            if (database[i].id > 0)
            {
                printf("---------------------------------------------\n");
                printf("%-25s %d\n", "ID:", database[i].id);                         // prompt
                printf("%-25s %s\n", "Category:", Categories[database[i].category]); // prompt
                printf("%-25s %s\n", "Title:", database[i].title);                   // prompt
                printf("%-25s %s\n", "Author:", database[i].author);                 // prompt
                printf("%-25s %s\n", "Note:", database[i].note);                     // prompt
            }
        }
        printf("---------------------------------------------\n"); // ending divider prompt
    }
    else
    {
        // file does not exist aka no data exists
        printf("=== NO BOOKS FOUND IN DATABASE ===\n");
    }
}

// READ DATA FROM FILE
int readFromFile(struct book database[], int position)
{
    if (checkFileExistance() == 0)
    { // if file exists
        // DECLARE + INITALIZE VARIABLES
        FILE *fp = fopen(DB_FILE_NAME, "r"); // open file in read mode
        char data[MAX_READ_BUFFER];          // for holding file data - reserving memory incase there are all 100 books in database
        char *lines;                         // holds indivdual lines
        char *token;                         // holds individual token

        // read the entire data
        while (fgets(data, MAX_READ_BUFFER, fp) != NULL)
        { // read until end
            // split each line at newline '\n' character
            lines = strtok(data, "\n"); // tokenize each line;
            while (lines != NULL)
            { // iterate over each line
                // initialing [allow & count] here because I want it re-initalize each iteration aka for each line
                int count = 0;              // to keep a track of token. wheather it is id,category,title,author or note [1 - 4]
                int allow = 1;              // flag to allow adding to current book to database
                token = strtok(lines, ","); // split each line at ,
                while (token != NULL)
                {
                    if (count == 0)
                    {
                        if (findBookByID(database, position, atoi(token)) == 1)
                        {              // if book is not found
                            allow = 0; // using 0 as index
                        }
                    }

                    if (allow == 0)
                    { // if the flag is true aka book does not exists in array
                        // add book to array
                        if (count == 0)
                        {
                            database[position].id = atoi(token); // id
                        }
                        else if (count == 1)
                        {
                            database[position].category = atoi(token); // category
                        }
                        else if (count == 2)
                        {
                            strcpy(database[position].title, token); // title
                        }
                        else if (count == 3)
                        {
                            strcpy(database[position].author, token); // author
                        }
                        else if (count == 4)
                        {
                            strcpy(database[position].note, token); // note
                            position++;                             // incrementing the position [index]
                        }
                    }
                    token = strtok(NULL, ",");
                    count++; // incrementing the count
                }
                lines = strtok(NULL, "\n");
            }
        }
        fclose(fp); // closing the file after reading
    }
    // return original position value if no new items were added
    return position;
}

// WRITE DATA TO FILE
void writeBooksToFile(struct book database[], int position)
{
    // Variables - Declaration + Initialization
    char *data = "%d,%d,%s,%s,%s,\n";      // pattren
    FILE *file = fopen(DB_FILE_NAME, "w"); // file
    for (int i = 0; i <= position; i++)
    {
        if (database[i].id >= 1)
        {
            // write to file with arugment - Formatting
            fprintf(file, data, database[i].id, database[i].category, database[i].title, database[i].author, database[i].note);
        }
    }
    fclose(file); // write to file
}

// ADD NEW BOOK
int addBook(struct book database[], int position)
{
    // Variables - Declaration + Initialization
    int flag = 1;           // Flag for running the add new book while loop
    int tempIntValue;       // temporarily holds integer value
    char tempCharValue[45]; // temporarily holds char/string value of length 45

    while (flag)
    {
        // BOOK ID
        printf("=== Enter new Book ID (1-100): ");
        fgets(tempCharValue, 4, stdin);     // read userinput from standard input
        tempIntValue = atoi(tempCharValue); // casting from char/string to int
        if (tempIntValue >= 0)
        { // between 1-100 inclusive
            if (tempIntValue <= 100)
            {
                // Assigning BOOK ID
                database[position].id = tempIntValue; // assigning id to a position in database array
                while (1)
                {
                    // BOOK CATEGORY
                    printf("=== Enter Category Number [1-Arts; 2-Languages; 3-Computers; 4-Novels; 5-Others]: ");
                    fgets(tempCharValue, 45, stdin);    // reading user input from standard input
                    tempIntValue = atoi(tempCharValue); // casting char/string to int
                    // while (getchar() != '\n');
                    if (tempIntValue > 0)
                    { // between 1-5 inclusive
                        if (tempIntValue < 6)
                        {
                            database[position].category = tempIntValue; // assigning category-id to position in database array

                            // BOOK TITLE
                            printf("=== Enter Book Name: ");
                            fgets(tempCharValue, 45, stdin);                 // reading user input from standard input [book title]
                            removeNewLineCharacter(tempCharValue);           // removing newline character from string
                            strcpy(database[position].title, tempCharValue); // copying newline character removed string to title

                            // BOOK AUTHOR
                            printf("=== Enter Book Author: ");
                            fgets(tempCharValue, 45, stdin);                  // reading user input from standard input [book title]
                            removeNewLineCharacter(tempCharValue);            // removing newline character from string
                            strcpy(database[position].author, tempCharValue); // copying new line character removed string to author
                            // BOOK NOTE
                            printf("=== Enter Book Note: ");
                            fgets(tempCharValue, 100, stdin);               // reading user input from standard input [book title]
                            removeNewLineCharacter(tempCharValue);          // removing newline character from string
                            strcpy(database[position].note, tempCharValue); // copying new line character removed string to note

                            // write books to file
                            writeBooksToFile(database, position); // writting all books to file
                        }
                        else
                        {
                            printf("=== Invalid BooK Category ===\n"); // Invalid input
                            database[position].id = 0;                 // assigning id to a position in database array
                        }
                    }
                    else
                    {
                        printf("=== Invalid BooK Category ===\n"); // Invalid input
                        database[position].id = 0;                 // assigning id to a position in database array
                    }
                    break; // breaking loop
                }
            }
            else
            {
                printf("=== Invalid BooK Category ===\n"); // Invalid input
            }
            break; // breaking loop
        }
        else
        {
            printf("=== Invalid BooK ID ===\n"); // Invalid input
        }
    }
    position++;      // incrementing position
    return position; // returning the new position
}

// REPLACING NEWLINE '\n' CHARACTER WITH TERMINATOR '\0' CHARACTER FROM STRING
void removeNewLineCharacter(char *string)
{
    if (string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0'; // replacing the last character with line terminator
    }
}

void lowerCaseString(char *string)
{
    // Convert to upper case
    while (*string)                       // while there is a string
    {                                     // iterating over each char and covnerting it to uppercase
        *string = tolower((char)*string); // convert string to uppercase
        string++;                         // incrementing string index
    }
}

int returnBookIndex(struct book database[], int position, int id)
{
    for (int i = 0; i <= position; i++)
    {
        if (database[i].id == id)
        {             // if the book is found
            return i; // return the current iteration number
        }
    }
    return -1; // if the book is not found
}