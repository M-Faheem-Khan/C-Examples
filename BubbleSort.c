#include <stdio.h>

void bubble_sort(int sequence[], int sequence_length)
{
	// sorting
    for (int i = 0; i < sequence_length; i++)
    {
        for (int j = 0; j < sequence_length - 1; j++)
        {
            if (sequence[j] > sequence[j + 1])
            {
                int temp = sequence[j];
                sequence[j] = sequence[j + 1];
                sequence[j + 1] = temp;
            }
        }
    }

    // Printing Sorted Array
    for (int i = 0; i < sequence_length; i++)
    {
        printf("%d ", sequence[i]);
    }

    puts("");
};

int main(void) {
	int sequence_length;
	printf("How many integers do you want to enter: ");
	scanf("%d", &sequence_length);
	// arr initaliztion
	int sequence [sequence_length];
	// populating user input
	printf("Enter %d integers: ", sequence_length);
	for (int i=0; i<sequence_length; i++){
		scanf("%d", &sequence[i] );
	}
	// calling bubble sort function
	bubble_sort(sequence, sequence_length);
}
