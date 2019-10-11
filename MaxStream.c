#include <stdio.h>

int main(void) {
	printf("Max Integer Finder\n");
    // declaring & initalizing variables
    int max = 0, userInputStream;
    printf("Enter a sequence of non-negative integers (-1 to stop): "); // input prompt
    scanf("%d", &userInputStream); // reading the first integer
    while (userInputStream != -1)  // reading the whole things as a loop
    {
        if (userInputStream > max) // check if the input is more than max then set max eqaul to the input
        {
            max = userInputStream;
        }
        scanf("%d", &userInputStream); // reading the next integer
    }
    printf("The Largest Integer is %d", max); 
}
