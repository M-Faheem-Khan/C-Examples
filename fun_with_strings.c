// IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// CONSTANTS
#define INPUT_BUFFER 64 // user input buffer limit

// FUNCTION DECLARATIONS
/*
 * Description: Prints MENU
 * Arguments: None
 * Returns: None
*/
void menu();

int main(void)
{
    // VARIABLE DECLARATIONS + INITIALIZATIONS
    int selectedOption;                 // users selected option
    char userInput[INPUT_BUFFER];       // for holding userInput
    char secondUserInput[INPUT_BUFFER]; // for holding second userInput

    printf("=== STRING MANIPULATION ===\n"); // About Program Prompt
    menu();                                  // Calling print function

    while (1) // run infitely 
    {

        printf(": ");
        // reading user input
        fgets(userInput, INPUT_BUFFER, stdin);
        selectedOption = atoi(userInput); // casting userInput from char to integer
        if (selectedOption == 0)
        {
            menu();
        }
        else if (selectedOption == 1)
        {
            printf("=== Convert String to Lower Case ===\n"); // option prompt
            printf("String: ");                               // input prompt
            fgets(userInput, INPUT_BUFFER, stdin);            // reading user input

            // UPPER CASE TO LOWER CASE
            for (int i = 0; i < strlen(userInput); i++)
            {
                userInput[i] = tolower(userInput[i]);
            }

            // printing new string
            printf("=== NEW STRING ===\n"); // new string prompt
            printf("%s\n", userInput);      // printing new string
        }
        else if (selectedOption == 2)
        {
            printf("=== Convert String to Upper Case ===\n"); // option prompt
            printf("String: ");                               // input prompt
            fgets(userInput, INPUT_BUFFER, stdin);            // reading user input

            // LOWER CASE TO UPPER CASE
            for (int i = 0; i < strlen(userInput); i++)
            {
                userInput[i] = toupper(userInput[i]);
            }

            // printing new string
            printf("=== NEW STRING ===\n"); // new string prompt
            printf("%s\n", userInput);      // printing new string
        }
        else if (selectedOption == 3)
        {
            printf("=== CONCAINATE TWO STRINGS ===\n"); // option prompt
            printf("String 1: ");                       // input prompt
            fgets(userInput, INPUT_BUFFER, stdin);      // reading first user input

            printf("String 2: ");                        // input prompt
            fgets(secondUserInput, INPUT_BUFFER, stdin); // reading second user input

            strcat(userInput, secondUserInput); // concatinating both strings
            // userInput + secondUserInput

            // printing new string
            printf("=== NEW STRING ==="); // new string prompt
            printf("%s\n", userInput);    // printing new string
        }
        else if (selectedOption == 4)
        {
            printf("=== SEE YOU AGAIN!! ===\n");
            exit(0);
        }
    }
}

// MENU
void menu()
{
    // MENU OPTION PROMPTS
    printf("=== MENU ===\n");
    printf("0 - To view this menu again\n");
    printf("1 - Convert String to Lower Case\n");
    printf("2 - Convert String to Upper Case\n");
    printf("3 - Concatinate Two String\n");
    printf("4 - Exit\n");
}