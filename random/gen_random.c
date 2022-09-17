// Test file to check random number generation without specified seed 

#include <stdio.h>


int main() {
        unsigned int random;
        random = rand();
        printf("%u", random);

}
