#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
        if (n > 8){
            n = -1;
        }    
    }
    while (n < 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - (i + 2) ; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        for (int s = 0; s < 2; s++)
        {
            printf(" ");
        }
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}

