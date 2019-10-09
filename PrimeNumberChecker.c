#include <stdio.h>

int prime_number_checker(int num){
	if (num > 1) {
		for (int i = 2; i < (num / 2 + 1); i++)
        	{
            	if ((num % i) == 0)
            	{
               		return 0;
            	}
        	}
        return 1;
	} else {
		return 0;
	}
}

int main(void) {
	int userInput;
	printf("Prime number check: ");
	scanf("%d", &userInput);
	// check if the numer is prime
	int isPrime = prime_number_checker(userInput);
	if (isPrime == 1) {
		puts("Is a prime");
	} else {
		puts("Is not a prime");
	}
}
