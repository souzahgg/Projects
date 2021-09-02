// Program to use greedy algorithm to determine minimum number of coins for a change

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    // Asking user for the change
    float change;
    do
    {
        change = get_float("How much change is owed: ");
    }
    while (change < 0);

    // converting fraction to integer
    int cents = round(100 * change);

    // Keeping track of number of coins
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int penny_count = 0;
    float change_remain = cents;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // Calculating how many coins according to greed algorithm
    if (cents >= quarter)
    {
        change_remain = (change_remain / quarter);
        quarter_count = trunc(change_remain);
        change_remain = round((change_remain - quarter_count) * quarter);
    }

    if (change_remain >= dime)
    {
        change_remain = (change_remain / dime);
        dime_count = trunc(change_remain);
        change_remain = round((change_remain - trunc(change_remain)) * dime);
    }

    if (change_remain >= nickel)
    {
        change_remain = (change_remain / nickel);
        nickel_count = trunc(change_remain);
        change_remain = round((change_remain - trunc(change_remain)) * nickel);
    }

    if (change_remain >= penny)
    {
        penny_count = change_remain;
    }

    // Printing result
    int coin_count = (quarter_count + dime_count + nickel_count + penny_count);

    printf("Number of Quarters: %i\n", quarter_count);
    printf("Number of Dimes: %i\n", dime_count);
    printf("Number of Nickels: %i\n", nickel_count);
    printf("Number of Pennies: %i\n", penny_count);
    printf("Total Coins: %i\n", coin_count);
}