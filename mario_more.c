/**
 * This is my implementation of Mario (more comfortable) from cs50 2018
 *           #  #
 *          ##  ##      First program using while / for loops
 *         ###  ###     asking user for input
 *        ####  ####    and then drawing a pyramid like this
 *       #####  #####
**/

//Include all required header files
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Declare 'pyramid heigh' variable in desired scope,
    int height;

    //Ask user for positive number lower than 23 and assign it to that variable,
    do
    {
        height = get_int("Input pyramid heigh: ");
    }
    while (height > 23 || height < 0);

    //Generating the piramid
    for (int line = 0; line < height; line++)
    {
        //Print spaces and then hashes for first pyramid
        for (int spaces1 = height - line; spaces1 > 1; spaces1--)
        {
            printf(" ");
        }
        for (int hashes1 = 0; hashes1 < line + 1; hashes1++)
        {
            printf("#");
        }

        //Print the 'gap'
        printf("  ");

        //Print hashes for the second pyramid
        for (int hashes2 = 0; hashes2 < line + 1; hashes2++)
        {
            printf("#");
        }
        
        //Switch to second row
        printf("\n");
    }
}
