/*
 * Hello!
 * This code solves CS50 pset2 named "vigenere".
 * Poor implementation and a good example of, what's comming out simply patching one but after another working with debugger
 * However the code is working. 
 * TODO rewrite
 */

 //Include all required header files
#include <stdio.h>
#include <ctype.h>
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

    //Declare string array 'key', put user input into it
    string key = argv[1];
    int nrkey[strlen(key)];
    int keylenght = strlen(key);
    //Change string of charaters to numbers from 0 - 25, that's important for the main for loop
    for ( int i = 0; i < strlen(key); i++)
    {
        if ( islower(key[i]) )
        {
            nrkey[i] = key[i] - 'a';
        }
        else if ( isupper(key[i]) )
        {
            nrkey[i] = key[i] - 'A';
        }
    }

    //Check for numeric characters, if they occur print ERROR return '1'
    for (int i = 0; i < strlen(key); i++)
    {
        if ( isdigit(key[i]) )
        {
            printf("ERROR\n");
            return 1;
        }
    }

    //Ask user for a string to encipher
    string message = get_string("plaintext: ");

    //Start to encrypt
    printf("ciphertext: ");
    for (int i = 0, j = 0; i < strlen(message); i++)
    {
        //Print lower case letter
        if ( islower(message[i]) )
        {
            printf("%c", ( message[i] - 'a' + nrkey[j] ) % ('z' - 'a' +1) + 'a');
            if ( j >= keylenght - 1)
            {
                j = 0;
            }
            else
            {
                j++;
            }
        }
        //Print upper case letters
        else if ( isupper(message[i]) )
        {
            printf("%c", ( message[i] - 'A' + nrkey[j] ) % ('Z' - 'A' +1) + 'A');
            if ( j >= keylenght - 1)
            {
                j = 0;
            }
            else
            {
                j++;
            }
        }
        //Print other characters
        else
        {
            printf("%c", message[i]);
        }
    }
    //New line
    printf("\n");
}
