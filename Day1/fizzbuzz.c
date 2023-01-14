#include <stdio.h>

int main()
{
    // run a for loop from 1 too 100
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            // if number is multiple of 5 and 3 print "FizzBuzz"
            printf("%i: FizzBuzz\n", i);
        }
        else if (i % 3 == 0)
        {
            // if number is multiple of 3 print "Fizz"
            printf("%i: Fizz\n", i);
        }
        else if (i % 5 == 0)
        {
            // if number is multiple of 5 print "Buzz"
            printf("%i: Buzz\n", i);
        }
        else
        {
            // print all other numbers normally
            printf("%i\n", i);
        }
    }

    return 0;
}