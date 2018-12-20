/*************************************************************
 * Hello!
 * This code solves CS50 pset1 named "Cash".
 * In case you are stuck and looking for a
 * solution for that particulary pset feel
 * free to take a look.
 * ALso feel free to comment or share your own version!
*************************************************************/

//Include all required header files
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Declare 'amount of cash' variable in desired scope, and ask user to input there positive 'double'
    double cash;
    
    do
    {
        cash = get_double("How much change is due: ");
    }
    while (cash < 0);

    //Change 'double' cash to 'int' (cents) and round it off AND declare variable 'coins' for number of coins needed
    int CASH = round(cash * 100), coins = 0;

    //How many 25c should i give?
    for (; CASH >= 25; CASH -= 25) { coins++; }
    //How many 10c should i give?
    for (; CASH >= 10; CASH -= 10) { coins++; }
    //How many 5c should i give?
    for (; CASH >= 5; CASH -= 5) { coins++; }
    //How many 1c should i give?
    for (; CASH >= 1; CASH--) { coins++; }

    //Print the amount of coins needed to give change
    printf("%d\n", coins);
}
