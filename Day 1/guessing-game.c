#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

int main(void)
{
    int r_number = rand() % 100 + 1;
    printf("Guess the random number between 1 and 100:\n");

    int guess;
    bool correct = false;

    while (correct == false)
    {
        scanf("%d", &guess);
        if (guess > r_number)
        {
            printf("too high, try again!\n");
        }
        else if (guess < r_number)
        {
            printf("too low, try again!\n");
        }
        else
        {
            printf("you guessed it correctly!\n");
            correct = true;
        }
    }

    return 0;
}