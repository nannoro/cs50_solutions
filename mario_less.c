/**
 * This is my implementation of Mario (less comfortable) from cs50 2018
**/

//Include all required header files
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Declare 'piramid heigh' variable in a scope and ask user for a number
    int heigh;
    do
    {
        heigh = get_int("Input pyramid height (positive number!): ");
    }
    while (heigh > 23 || heigh < 0);

    //Generating the piramid
    for (int line = 0; line < heigh; line++)
    {
        for (int spaces = heigh - line; spaces > 1; spaces--)
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
