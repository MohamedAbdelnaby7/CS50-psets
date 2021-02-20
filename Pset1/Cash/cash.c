#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float change;
    int coin_number = 0;
    do
    {
        change = get_float("Change owed: ");
        change = round(change * 100);
    }
    while (change > 0 ? false : printf("Change owed: foo\n"));
    while (change > 0)
    {
        if (change >= 25)
        {
            change -= 25;
        }
        else if (change >= 10)
        {
            change -= 10;
        }
        else if (change >= 5)
        {
            change -= 5;
        }
        else
        {
            change --;
        }
        coin_number++;
    }
    printf("%i\n", coin_number);
}
