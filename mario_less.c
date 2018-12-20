/**
 * This is my implementation of Mario (less comfortable) from cs50 2018
**/

//Include all required header files
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Declare 'pyramid height' variable in a scope and ask user for a number
    int height;
    do
    {
        height = get_int("Input pyramid height (positive number!): ");
    }
    while (height > 23 || height < 0);

    //Generating the pyramid
    for (int line = 0; line < height; line++)
    {
        for (int spaces = height - line; spaces > 1; spaces--)
        {
            printf(" ");
        }
        for (int hashes = 0; hashes < line + 2; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
