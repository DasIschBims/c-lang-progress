#include <stdio.h>
#include <stdlib.h>

// why are there noo bools ._ .
typedef enum
{
    false,
    true
} bool;

// note to self: so there are bool with stdbool.h

int main()
{
    // generate a random number from 1 - 100
    int r_number = rand() % 100 + 1;
    printf("Guess the random number between 1 and 100:\n");

    int guess;
    bool correct = false;

    // while the guess is incorrect, repeat until it is correct
    while (correct == false)
    {
        // get user input and set it to the "int guess"
        scanf("%d", &guess);
        if (guess > r_number)
        {
            // too high
            printf("too high, try again!\n");
        }
        else if (guess < r_number)
        {
            // too low
            printf("too low, try again!\n");
        }
        else
        {
            // on correct guess congratulate and set the bool to true to end the while loop
            printf("you guessed it correctly!\n");
            correct = true;
        }
    }

    return 0;
}