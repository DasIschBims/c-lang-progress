#include <stdio.h>
#include <string.h>

int main()
{
    // create an array to hold the string
    char str[100];
    printf("Enter a string to be reversed:\n");
    // store the string while also including spaces, scanf doesn't do that
    fgets(str, sizeof(str), stdin);

    // get the length of the string and create an array to hold it
    int length = strlen(str);
    char revstr[length];

    // reverse it using a for loop
    for (int i = 0; i < length; i++)
    {
        revstr[i] = str[length - 1 - i];
    }

    // actually learned smth, if i remove this it prints until it finds an invalid memory location
    // note to self: add this for security in important stuff
    revstr[length] = '\0';
    // print out the reversed string
    printf("Your reversed string is:\n%s\n", revstr);

    return 0;
}