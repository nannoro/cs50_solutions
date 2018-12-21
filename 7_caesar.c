/*
 * Hello!
 * This code solves CS50 pset2 named "caesar".
 */

//Include all required header files
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    //If executed without any command-line arguments or with more than one, print an error message, return '1'
    if (argc != 2)
    {
        printf("ERROR\n");
        return 1;
    }

    //Declare variable 'key' = user flag input and ask user for a string to encipher
    int k = atoi(argv[1]);
    string message = get_string("plaintext: ");

    //Start to encrypt
    printf("ciphertext: ");
    for (int i = 0; i < strlen(message); i++)
    {
        //Print lower case letter and wrap it up if i exceeded number of letters in alphabet
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            printf("%c", (message[i] - 'a' + k) % 26 + 'a');
        }
        //Print upper case letter and wrap it up if i exceeded number of letters in alphabet
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            printf("%c", (message[i] - 'A' + k) % 26 + 'A');
        }
        //Print other characters
        else
        {
            printf("%c", message[i]);
        }
    }
    //Remember about a new line
    printf("\n");
    return 0;
}
