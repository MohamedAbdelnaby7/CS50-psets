#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    bool valid = false;
    int cardLength ;
    long num, cardNumber; // num will be a copy of the cardnumber 

    cardLength = 0;
    cardNumber = get_long("Number: ");
    num = cardNumber;

    while (num != 0) // calculation number of digits 
    {
        num /= 10;     
        ++cardLength;
    }
    valid = (cardLength == 15) || (cardLength == 16) || (cardLength == 13); // make sure number of credit is right
    if (valid)
    {
        valid = false;
        int operation [cardLength];
        int i = 0, k = 0;
        num = cardNumber;
        while (num > 0) //seperating cardnumber into individual digits
        {
            int digit = num % 10;
            operation[i++] = digit;
            num /= 10;
        }

        int sum = 0;
        //int evens[cardLength / 2];
        for (i = 0; i < cardLength; i++)
        {
            if (i % 2 == 0)
            {
                sum += operation[i];
                //printf("%i\n", sum);
            }
            else 
            {
                int mux = operation[i] * 2;
                while (mux > 0)
                {
                    int digit = mux % 10;
                    sum += digit;
                    mux /= 10;
                }
                //printf("%i\n", sum);
            }
        }
        /*for (i = 0; i < cardLength/2 - 1; i++)
        {
            while (evens[i] > 0)
            {
                int digit = evens[i] % 10;
                sum += digit;
                evens[i] /= 10;
            }
        }*/
        bool continuing = sum % 10 == 0 ? true : false;
        //printf("%d" , valid);

        if (continuing)
        {
            if (cardLength == 13)      //(cardLength == 16 && ((cardNumber / (long)pow(10, 15)) == 4)))
            {
                if ((cardNumber / (long)pow(10, 12)) == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (cardLength == 15)
            {
                int last_two = cardNumber / (long)pow(10, 13);
                if (last_two == 34 || last_two == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (cardLength == 16)
            {
                int last_two = cardNumber / (long)pow(10, 14);
                if (last_two == 51 || last_two == 52 || last_two == 53 || last_two == 54 || last_two == 55)
                {
                    printf("MASTERCARD\n");
                } 
                else if ((cardNumber / (long)pow(10, 15)) == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
