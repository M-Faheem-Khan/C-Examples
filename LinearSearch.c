#include <stdio.h>

int linearSearch(int arr[], int arrLength, int searchValue){
	  // Linear Search
  for (int i=0; i<(arrLength-1); i++){
	  // Searching for each value
	  if (arr[i] == searchValue) {
		  printf("Found at Index %d\n", i);
		  break;
	  }
  }
  printf("Not Found in Array\n");
  return 0;
}

int main(void) {
  printf("Linear Search\n");
  int arrLength = 10;
  int arr[10] = {2, 1, 9, 3, 4, 5, 7, 8, 0 };
  int searchValue;
  printf("Search: ");
  scanf("%d", &searchValue);
  linearSearch(arr, arrLength, searchValue);

  return 0;
}
