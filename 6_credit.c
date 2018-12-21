/*************************************************************
 * Hello!
 * This code solves CS50 pset1 named "Credit".
 * In case you are stuck and looking for a
 * solution for that particulary pset feel
 * free to take a look.
 * Also feel free to comment or share your own version!
*************************************************************/

//Include all required header files
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Initiate variables for card number, number lenght and checksum in desired scope
    long cardnumber, checksum = 0, numberlenght = 0;

    //Ask user for a positive card number
    do
    {
        cardnumber = get_long_long("What is your credit card number?\n");
    }
    while (cardnumber < 0);

    //Increase number lenght to true value, using 'long' counter
    for (long counter = cardnumber; counter != 0; numberlenght++)
    {
        counter /= 10;
    }


    //Calculate checksum
    //Starting with second-to-last digit, multiply every other digit
    for (long which_even_digit = 0, digit = 0; which_even_digit < numberlenght / 2; which_even_digit++)
    {
        digit = cardnumber % (long) pow(100,which_even_digit + 1) / (pow(100,which_even_digit + 1) / 10);
        if (digit >= 5)
        {
            checksum = checksum + ((digit * 2) % 10) + (digit * 2 / 10);
        }
        else
        {
        checksum = checksum + 2 * digit;
        }
        //printf("Even digit: %ld\n", checksum);
    }
    //Add remaining digits to the checksum
  for (long which_odd_digit = 0, digit = 0, cardnumber2 = cardnumber; which_odd_digit < (numberlenght / 2) + 1; which_odd_digit++)
    {
        digit = cardnumber2 % 10;
        checksum = checksum + digit;
        //printf("Odd digit: %ld\n", digit);
        cardnumber2 /= 100;
    }

    //printf("Checksum: %ld\n", checksum);

    //Check if card number is invalid
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (numberlenght == 15 && (cardnumber / 10000000000000 == 34 || (cardnumber / 10000000000000 == 37)))
        {
            printf("AMEX\n");
        }
        if (numberlenght == 16 && (cardnumber / 100000000000000 >= 51 && cardnumber / 100000000000000 <= 55))
        {
            printf("MASTERCARD\n");
        }
        if ((numberlenght == 13 && cardnumber / 1000000000000 == 4) || (numberlenght == 16 && cardnumber / 1000000000000000 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
