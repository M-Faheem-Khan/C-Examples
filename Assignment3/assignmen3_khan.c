/*
    * Name : Muhammad F. Khan
    * Class : PROG12974 1234_56789, Fall 2019 
    * Assignment : Assignment #1 – Student Record
    * Date : November 14, 2019 
    * Program : assignment3_khan.c
    * Description : a program that allows user to enter student information and then interact with it
*/

// Imports
#include <stdio.h>  // Standard I/O
#include <stdlib.h> // Standard Library
#include <string.h> // String Manipulation
#include <ctype.h>  // Type Checking

// Constants
// BUFFER SIZES
#define NUMBER_OF_STUDENTS 10  // up 999 999 999 students
#define STUDENT_NAME_LENGTH 50 // up 50 characters in name
#define STUDENT_MARKS_LENGTH 5 // up to 6 characters for marks 9.999
#define STUDENT_ID_LENGTH 9    // usually school ids are 9 characters long

// Function declarations
/*
 * Description: Converts String from lowercase to uppercase
 * Parameters: A string of lowercase characters (string)
 * Returns: None
*/
void upperCaseString(char *string);

/*
 * Description: Searchs for Substring in Student Names array, given id, and marks array as well
 * Parameters:
    * StudentIds [Integer] - holds student ids
    * StudentName [Chars] - holds student names (array that will be searched)
    * StudentMarks [Double] - holds student marks
 * Returns: None
*/
void searchStudent(int StudentIds[], char StudentNames[][50], double StudentMarks[], int numberOfStudents);

/*
    Prints Help to screen for search 
    Arguments: None
    Returns: None
*/
void printSearchHelp();

// main function
int main(void)
{
    // Variable Declaration + Initalization
    char userOptionString[2]; // for holding users menu option
    char userOption;          // holding the actual value as int
    // MENU
    printf("Student Records\n"); // About Program
    printf("MENU\n");            // Menu Prompt

    // reading user input
    while (1)
    {
        printf("1 - Start\n2 - Help\n3 - Exit\n: "); // Options
        fgets(userOptionString, 2, stdin);           // reading user input
        userOption = atoi(userOptionString);         // casting user input to integer from string
        // Possible Options
        if (userOption == 1) // populate student information
        {
            while (getchar() != '\n')
                ; // for handling invalid userInput

            printf("=== OPTION 1 Selected: Start ===\n");
            // Variables declarations and initalizations
            char numberOfStudentsString[NUMBER_OF_STUDENTS]; // temporarily holding user input
            int numberOfStudents;                            // for holding number of student: INTEGER

            // Reading the number of students
            printf("=== Enter the number of students: ");             // prompt
            fgets(numberOfStudentsString, NUMBER_OF_STUDENTS, stdin); // reading line
            // converting number of students from string to integer
            numberOfStudents = atoi(numberOfStudentsString);

            // Declaring Arrays to hold student information so I don't have to memory management later
            // char StudentIds[numberOfStudents][STUDENT_ID_LENGTH];
            int StudentIds[numberOfStudents];
            char StudentNames[numberOfStudents][STUDENT_NAME_LENGTH];
            double StudentMarks[numberOfStudents];
            double average = 0;

            // Actual Program - How the program works
            printf("=== HELP ===.\n");
            // help prompt
            printf("=== You can enter 0 to exit.\n");
            // help prompt
            printf("=== Enter id, name, and mark seperated by a comma(,).\n");
            // help prompt
            // Loop for getting individual student information
            for (int i = 0; i < numberOfStudents;)
            {
                // Variables Declarations + Initalization
                int userInputLength = STUDENT_ID_LENGTH + STUDENT_NAME_LENGTH + STUDENT_MARKS_LENGTH; // max length of characters allowed
                char userInput[userInputLength];                                                      // holding user input
                char *token;                                                                          // for holding the split string
                // counter to keep a track of Id(integer), Name(string/char), Mark(double)
                int counter = 1;

                // prompt - adding +1 easier to read for users
                printf("Student #%d: ", (i + 1));
                fgets(userInput, userInputLength, stdin); // reading user input
                // splitting the string
                token = strtok(userInput, ",");
                // splitting tokens
                while (token != NULL) // looping through the token
                {
                    if (counter == 1) // Student Id: Integer
                    {
                        // Checking if the student id is a integer
                        int idSize = strlen(token); // student id size
                        int count = 0;              // for keep track id char count

                        // validating if the user enter integer
                        for (int p = 0; p < idSize; p++)
                        {
                            if (isdigit(token[p]))
                            {            // checking the string is token
                                count++; // count for id character
                            }
                            else
                            {
                                // if the current character is not a digit - print error
                                // stopping here to save resources
                                printf("=== Error: Student Id must be an integer!\n"); // error prompt
                                i -= 1;                                                // counting back so the count does not offset entire array
                                break;                                                 // breaking the for loop if student id is not a integers
                            }
                        }

                        // if the entered id is all integer / digit
                        // using counter to see if every single character in the int was a actual digit
                        if (count == idSize)
                        {
                            // casting student id fromt string to integer form
                            StudentIds[i] = atoi(token);
                        }
                    }
                    else if (counter == 2) // Student Name: String
                    {
                        // copying string to array
                        strcpy(StudentNames[i], token);

                        // converting string to upper case
                        upperCaseString(StudentNames[i]);
                    }
                    else if (counter == 3) // Student Mark: Float
                    {
                        // casting double from char/string
                        char *ptr; // temporary Pointer
                        // casting char to double
                        StudentMarks[i] = strtod(token, &ptr);
                        // adding student mark to average
                        average += StudentMarks[i];
                    }

                    // spliting token
                    // setting null token
                    token = strtok(NULL, ",\n");
                    // incrementing token
                    counter++;
                }
                i++; //incementing for each student
            }

            // Printing Student Information
            printf("---------------------------- LIST OF ALL STUDENTS ----------------------------\n");
            printf("------------------------------------------------------------------------------\n");
            printf("#   %-10s %-40s %s\n", "ID", "Name", "Mark"); // printing padded row
            printf("------------------------------------------------------------------------------\n");
            // Printing Student rows
            for (int k = 0; k < numberOfStudents; k++)
            {
                printf("%-3d %-10d ", k, StudentIds[k]); // printing padded row
                printf("%-40s ", StudentNames[k]);
                printf(" %-10.2f\n", StudentMarks[k]); // printing padded row
            }
            printf("------------------------------------------------------------------------------\n");
            printf("Average %53.2f\n", average / numberOfStudents); // printing padded average
            printf("------------------------------------------------------------------------------\n");

            // call search student function
            searchStudent(StudentIds, StudentNames, StudentMarks, numberOfStudents);
            break;
        }
        else if (userOption == 2) // help
        {
            // printing the help
            printf("=== User Selected Help\n");
            printf("About: This program allows users to interact with entered students information.\n");
            printf("1 - Start: Allows you to populate student information & interact with it\n");
            printf("2 - Help: Prints this help\n");
            printf("3 - Exit: Exit the program\n\n");
        }
        else if (userOption == 3) // exit the program
        {
            printf("=== See you next time! ===\n");
            exit(0);
        }
        else
        {
            // if invalid option or input is entered
            printf("=== Invalid Input! ===\n");
        }
        while (getchar() != '\n')
            ; // for handling invalid userInput
    }
}

// Converting string from lowercase to uppercase
void upperCaseString(char *string)
{
    // Convert to upper case
    while (*string)                       // while there is a string
    {                                     // iterating over each char and covnerting it to uppercase
        *string = toupper((char)*string); // convert string to uppercase
        string++;                         // incrementing string index
    }
}

// printing help for search 
void printSearchHelp()
{
    // Help Prompts
    printf("=== Search Help\n"); 
    printf("=== You can Search for Student by student names\n");
    printf("=== If you want to search everything that contains Q or q add a backslash. Only for single character\n");
    printf("=== EXAMPLE: If you want to search Quincy enter Quincy\n");
    printf("=== EXAMPLE: If you want to search Q enter \\Q\n");
    printf("=== To Quit the program enter Q or q\n");
}

// Search for substring
void searchStudent(int StudentIds[], char StudentNames[][50], double StudentMarks[], int numberOfStudents)
{
    int flag = 1;          // flag to keep the loop running
    char searchString[50]; // to store users search parameters
    // Search Loop
    while (flag)
    {
        // declaring variables here becuase it will reinitalize
        double average = 0.0;           // holds average
        int numberOfStudentsFound = 1;  // number of students found when searching
        printf("=== Search: ");         // Prompts
        // reading user input for search query
        fgets(searchString, 50, stdin); 
        
        // validating the search
        // checking for newline character
        if (searchString[strlen(searchString) - 1] == '\n') 
        {
            // replacing newline character with line terminator
            searchString[strlen(searchString) - 1] = '\0'; 
        }
        upperCaseString(searchString);  // Convert the user input to uppercase
        // if the user wants to quit - double negative
        if (!strcmp(searchString, "Q")) 
        {
            printf("=== See you next time! ===\n"); // exit prompt
            exit(0);                                // exiting
        }
        else
        {
            // checking if the string contains \Q in the string
            if (strcmp("\\Q", searchString) == 0) 
            {
                strcpy(searchString, "Q");        // removing the backslash
            }
            // search for q
            // Printing Student Information
            printf("\n---------------------------- LIST OF ALL STUDENTS ----------------------------\n");
            printf("------------------------------------------------------------------------------\n");
            printf("#   %-10s %-40s %s\n", "ID", "Name", "Mark"); // printing padded row
            printf("------------------------------------------------------------------------------\n");
            for (int k = 0; k < numberOfStudents; k++)
            {
                if (strstr(StudentNames[k], searchString))
                {
                    // printing student information
                    // printing padded row
                    printf("%-3d %-10d ", (k + 1), StudentIds[k]); 
                    // the student name
                    printf("%-40s ", StudentNames[k]);
                    // printing padded row
                    printf(" %-10.2f\n", StudentMarks[k]);
                    // adding the student mark to the average
                    average += StudentMarks[k];
                    // incrementing for every student found
                    numberOfStudentsFound++;
                }
            }

            // printing the selected student Average
            printf("------------------------------------------------------------------------------\n");
            printf("Average %53.2f\n", (average / numberOfStudentsFound)); // printing padded average
            printf("------------------------------------------------------------------------------\n");
        }
    }
}