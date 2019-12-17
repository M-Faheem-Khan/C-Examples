/*
    * Name : Muhammad F. Khan
    * Class : PROG12974 1234_56789, Fall 2019 
    * Assignment : Assignment #1 – Guess Number
    * Date : September 26, 2019 
    * Program : assignment1_khan.c
    * Description : a program that plays a random number guessing game (10 - 30)
*/

//  Imports
#include <stdio.h>  // Standard Input/Output
#include <stdlib.h> // Standard Library
#include <time.h>   // Time

// main function - where the game runs
int main(void)
{
    srand(time(NULL)); // random number gen seed
    // Declaring + Initalizing Variables
    int MAGICNUMBER = 10 + rand() % 21; // random number
    int flag = 0;                       // flag for the while loop
    // userInput variable will be initalized when the user enter input
    int userInput; // to hold the user inputs (0/1);

    // LOOP FOR THE GAME
    while (userInput != MAGICNUMBER)
    {
        // some information that the user need to know to play
        printf("Guess a magic number between 10 and 30\n"); // guess range
        // exit / give up options
        printf("Enter your guess (0-Exit / 1-Give Up): ");
        scanf("%d", &userInput); // getting user input
        if (userInput == 0)      // if the user wants to quit the game
        {
            printf("See you next time!");
            exit(0); // calling the exit function to exit the function
        }
        else if (userInput == 1) // if the user gives up
        {
            // printing the magic number
            printf("The magic number is %d\n", MAGICNUMBER);
            // checking if the user want to continue playing the game
            printf("Do you want to play agian? (0 - No / 1-yes):");
            scanf("%d", &userInput);
            if (userInput == 0)
            {
                printf("See you next time!");
                exit(0); // calling the exit function to quit the game
            }
            else
            {
                main();
            }
        }
        else if (userInput < MAGICNUMBER) // if the user guesses a number lower than MAGICNUMBER
        {
            printf("Your guess is too low\n");
        }
        else if (userInput > MAGICNUMBER) // if the user guesses a number higher than the MAGICNUMBER
        {
            printf("Your guess is too high\n");
        }
    }
    printf("Yes, the number is %d, Good Job!\n", MAGICNUMBER);
    main(); // calling the main function again to start the game agian
}
