/*
    Name: hello_world.c
    Author: Muhammad F. Khan
    Version: 1.0
    Description: Adding two integers in C Programming Language
*/

// Imports
#include <stdio.h> // for input and output operations

// main function
void main(){
    // Declaring Variables
    int integer1; // for storing first int
    int integer2; // for storing second int
    int sum; // variable to store the sum of both integers

    // getting the two integers from user
    // integer 1
    printf("Please Enter Integer 1 \n:"); // prompt
    scanf("%d", &integer1); // reading integer

    // integer 2
    printf("Please Enter Integer 1 \n:"); // prompt
    scanf("%d", &integer2); // read integer

    sum = integer1 + integer2;
    printf("Sum is %d\n", sum);
}