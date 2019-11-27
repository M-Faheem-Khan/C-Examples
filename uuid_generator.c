// DESCRIPTION: Generate Random UUID
// IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // random number seed
    char charSet[17] = "0123456789ABCDEF-"; // character set
    char uuid[37]; // hold uuid
    int randNumber = 0; // holds random number
    
    printf("UUID GENERATOR\n"); // prompt
    
    for (int i=0; i<36; i++) { // iterate 36 times because we need 32 hex values and 4 seperaters "-" hypens
        randNumber = rand() % 16; // moding by 16 because we need value between 0 and 16
        uuid[i] = charSet[randNumber]; // assigning random character
        if (i == 8 || i == 13 || i == 18 || i == 23) { // 
            uuid[i] = '-'; // assigning delimiter/seperator
        }
    }
    
    uuid[36] = '\0'; // assigning null character at the end of the uuid
    printf("UUID: %s\n", uuid); // printing uuid
}
