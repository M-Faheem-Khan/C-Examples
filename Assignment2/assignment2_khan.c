/*
    * Name : Muhammad F. Khan
    * Class : PROG12974 1234_56789, Fall 2019 
    * Assignment : Assignment #2 – Stream Processing
    * Date : September 10, 2019 
    * Program : assignment2_khan.c
    * Description : a program that performs various tasks on a stream of incoming data. 
*/

#include <stdio.h>

/*
 * Description: This function will display the main menue of the program.
 */
void printMenu();

/*
 * Description: This function will read non-negative integers entered on the
 * 	command line until a negative number is encountered. The function will
 * 	then return the largest non-negative integer read from the stream or -1 
 *  if no non-negative integer is read.
 * Parameters: None
 * Returns: The largest non-negative integer encountered in the stream 
 *          or -1 if no non-negative integer is read.
 */
int stream_max();

/*
 * Description: This function will read non-negative integers entered on the
 * 	command line until a negative number is encountered. The function will
 * 	then return an integer representing the number of odd positive numbers
 * 	read from the stream.
 * Parameters: None
 * Returns: A count of the odd positive numbers read from the stream.
 */
int count_odds();

/*
 * Description: This function will take an integer and check if the number
 *    is a prime number or not.
 * Parameters: An integer to check prime
 * Returns: 1 if the number is prime or 0 otherwise.
*/
int is_prime(int num);

/*
 * Description: This function will read non-negative integers entered on the
 * 	command line until a negative number is encountered. The function will
 * 	then return an integer representing the number of prime numbers
 * 	read from the stream. 0 and 1 are NOT considered prime numbers.
 * Parameters: None
 * Returns: A count of the number of prime numbers read from the stream.
*/
int count_primes();

/*
 * Description: This function will read a number floating point numbers entered
 * 	on the command line. The quantity parameter will indicate how many floating
 * 	point numbers should be read. The function should allow positive and
 * 	negative numbers to be read from the command line. The function will then
 * 	return a float representing the average of the numbers read from the stream
 * 	rounded to two decimal places.
 * Parameters: An integer representing the number of numbers to read from the
 * 	stream.
 * Returns: A float reprsenting the average from the numbers read from the stream
 * 	rounded to two decimal places.
*/
float calc_average(int n);

/*
 * Description: This function takes an array of integers and initializes each
 * 	element in the array to -1. 
 * Parameters: An integer array and an integer representing the sequence length.
 * Returns: None
*/
void init_sequence(int sequence[], int sequence_length);

/*
 * Description: This function takes an array of integers containing
 * 	sequence_length number of integers. The function should print each
 * 	number, separated by a space, to the command line, followed by
 * 	a new line.
 * Parameters: An integer array and a sequence_length (i.e. the number of
 * 	elements in the array).
 * Returns: None
*/
void print_sequence(int sequence[], int sequence_length);

/*
 * Description: This function sorts an array of integers from lowest
 * 	to highest using bubble sort. The number of elements in the array is 
 *  given by the the sequence_length parameter.
 * Parameters: An integer array and a sequence_length (i.e. the number of
 * 	elements in the array).
 * Returns: None
*/
void bubble_sort(int sequence[], int sequence_length);

/*
 * Description: This function uses the linear search algorithm to search
 * 	an array of integers for the num parameter. The function should print the
 *  position at where num is found in the sequence, or a message if num is not
 *  found. The function should return the number of comparisons required to 
 *  find the number, if successful. If the number is not found, the function 
 *  should return a -1.
 * Parameters: An integer array, a sequence_length (i.e. the number of elements
 *  in the array), and a number to search for.
 * Returns: The number of comparisons required to locate the number if
 * 	it was found. -1 if the number was not found.
*/
int linear_search(int sequence[], int sequence_length, int num);

int main(void)
{
    int userInput = '1';    // intializing
    int sequence[30];       // array with size 30
    int sequenceLength = 0; // intial array length
    printMenu();            // calling the print menu function to print the menu
    while (userInput != 0)  // run until the user enter 0 to quit the program
    {
        printf("=== Choose a Task: "); // choose a task prompt
        scanf("%d", &userInput);       // reading the users input - Check if its a valid integer
        if (userInput == 1)            // if the user choose option #1 - Max Int from Stream
        {
            int maxValue = stream_max();                      // getting the largest integer
            printf("The Largest Integer is: %d\n", maxValue); // printing the largest integer
        }
        else if (userInput == 2) // if the user chooses option #2 - Count Odds in a given Stream
        {
            // store the number of odds ints in a given stream
            int odds = count_odds(); 
            // print the number of odds
            printf("The number of odd integers is: %d\n", odds); 
        }
        else if (userInput == 3) // if the user chooses option #3 - Prime Count
        {
            int primes = count_primes(); // storing the number of odss
            // printing the number of primes
            printf("The number of primes integers is: %d\n", primes); 
        }
        else if (userInput == 4) // if the user chooses option #4 - Float Avg.
        {
            int floatCount; // number of floats the user wants to enter 
            printf("=== Enter the number of real numbers: "); // input prompt
            scanf("%d", &floatCount); // reading user input
            if (floatCount > 0) // check to see if the user enterd a positive number
            {
                // input prompt
                printf("=== The average of the real numbers is: %0.2f\n", calc_average(floatCount)); // calculating the float average.
            }
            else
            {
                puts("=== The number of real numbers must be a positive integer.");
            }
        }
        else if (userInput == 5)
        {
            printf("=== Enter the number of the elements: ");
            scanf("%d", &sequenceLength);
            if (sequenceLength > 0)
            {
                init_sequence(sequence, sequenceLength);
            }
            else
            {
                puts("=== The number of real numbers must be a positive integer.");
            }
        }
        else if (userInput == 6)
        {
            if (sequenceLength > 0)
            {
                print_sequence(sequence, sequenceLength);
            }
            else
            {
                puts("=== First Enter a sequence of integer!");
            }
        }
        else if (userInput == 7)
        {
            bubble_sort(sequence, sequenceLength);
        }
        else if (userInput == 8)
        {
            if (sequenceLength > 0)
            {
                int num;
                printf("=== Enter an integer to search: ");
                scanf("%d", &num);
                if (num > 0)
                {
                    int steps = linear_search(sequence, sequenceLength, num);
                    printf("=== Number %d was %s in the array\n", num, steps > 0 ? "found" : "not");
                    printf("=== Number of steps in searching %d\n", steps);
                }
            }
        }
        else if (userInput == 9)
        {
            printMenu();
        }
        else if (userInput < 0 || userInput > 9)
        { // if the user input is not between 0 & 9
            printf("=== Invalid Input\n");
        }
        // for infinate loop because of the invalid input
        while (getchar() != '\n')
            ;
    }
    printf("Thank You. See you again!!\n"); // goodbye statement
}

// FUNCTION BODIES BELOW

// Description: This function will display the main menue of the program.
void printMenu()
{
    puts("======================================================");
    puts("0 - Exit");
    puts("1 - Find the Largest Integer");
    puts("2 - Find the Number of Odd Integers");
    puts("3 - Find the Number of Prime Integers");
    puts("4 - Find the Average of Real Numbers");
    puts("5 - Load the Sequence Array of Integers");
    puts("6 - Print the Sequence Array of Integers");
    puts("7 - Sort the Sequence Array using Bubble Sort");
    puts("8 - Search the Sequence Array using Linear Search");
    puts("9 - Print the Menu");
    puts("======================================================");
}

// Description: Find the largest integer from given integers
int stream_max()
{
    // declaring & initalizing variables
    int max = 0, userInputStream;
    printf("=== Enter a sequence of non-negative integers (-1 to stop): "); // input prompt
    scanf("%d", &userInputStream);                                          // reading the first integer
    while (userInputStream != -1)                                           // reading the whole things as a loop
    {
        if (userInputStream > max) // check if the input is more than max then set max eqaul to the input
        {
            max = userInputStream;
        }
        scanf("%d", &userInputStream); // reading the next integer
    }
    return max; // returning the max integer
};

// Description: Count all odd integers from given integers
int count_odds()
{
    // declaring & initalizing variables
    int userInputStream, odds = 0;
    printf("=== Enter a sequence of non-negative integers (-1 to stop): "); // input prompt
    scanf("%d", &userInputStream);                                          // reading user input
    while (userInputStream != -1)
    {
        if ((userInputStream % 2) != 0) // check if the integer is odd
        {
            odds += 1; // incrementing odd counter by 1, to keep a track of all odds
        }
        scanf("%d", &userInputStream); // reading the next integer
    }
    return odds; // returning the count of all odd integers
};

// Description: Checks if the given integer is a prime or not
int is_prime(int num)
{
    if (num > 1) // make sure all integers are more than 1
    {
        for (int i = 2; i < (num / 2 + 1); i++) // loop of numbers to use to mod the given integer
        {
            if ((num % i) == 0) // if the integer mod i equals 0; integer is not prime
            {
                return 0; // return 0
            }
        }
        return 1; // if the integer is prime
    }
    else // if the integer is less than 1
    {
        return 0; // if the integer is not prime
    }
};

// Description: Calculates the number of primes from a given stream
int count_primes()
{
    // declaring and initalizing variables
    int userInputStream;
    int primes = 0;
    printf("=== Enter a sequence of non-negative integers (-1 to stop): "); // input prompt
    while (userInputStream != -1) // keep going until user enters -1
    {
        if (userInputStream > 0) // making sure user only enters positive values
        {

            if (is_prime(userInputStream) == 1) // check if the number is prime
            {
                primes += 1; // if prime increment 
            }
        } 
        scanf("%d", &userInputStream); // reading user input
    }
    return primes; // returning the number of primes
}

// Description: Calculates the average of given floats from a stream
float calc_average(int n) 
{
    // declaring & intializing variables
    float userInputStream;
    float sum = 0;
    printf("=== Enter %d real numbers: ", n); // input prompt
    for (int i = 0; i < n; i++) // looping to read user input 
    {
        scanf("%f", &userInputStream); // reading users input
        sum += userInputStream; // add user input
    }
    return (sum / n); // returning the average
}

// Description: Populates passed array
void init_sequence(int sequence[], int sequence_length)
{
    printf("=== Enter %d integers: ", sequence_length); // input prompt
    for (int i = 0; i < sequence_length; i++) // looping to read user input
    {
        scanf("%d", &sequence[i]); // populating array 
    }
};

// Description: Prints Passed Array
void print_sequence(int sequence[], int sequence_length)
{
    printf("The current sequence is: "); // prompt
    for (int i = 0; i < sequence_length; i++) // looping over each arrey element
    {
        printf("%d ", sequence[i]); // printing array element
    }
    puts(""); // new line after loop
};

// Description: Using Bubble Sort to sort passed array
void bubble_sort(int sequence[], int sequence_length) 
{
    for (int i = 0; i < sequence_length; i++) // outer loop
    {
        for (int j = 0; j < sequence_length - 1; j++) // inner loop
        {
            if (sequence[j] > sequence[j + 1]) // comparing values
            {
                int temp = sequence[j]; // holding current elements value
                sequence[j] = sequence[j + 1]; // swaping values
                sequence[j + 1] = temp; // swaping values
            }
        }
    }
    // printing array
    print_sequence(sequence, sequence_length); 
};

// Description: Performs linear search on array
int linear_search(int sequence[], int sequence_length, int num)
{
    for (int i = 0; i < sequence_length; i++) // loop
    {
        if (sequence[i] == num) // checking if the value of current index match
        {
            return i; // if so return number of steps to match
        }
    }
    return -1; // if search item not found in array
};