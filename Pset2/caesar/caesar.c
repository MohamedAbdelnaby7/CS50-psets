#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

string encrypt(string text, int k);

int main(int argc, string argv[])
{
    int key;
    if (argc == 2)
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key");
                return 1;
            }
        }
    }
    else 
    {
        printf("Usage: ./caesar key");
        return 1;
    } 
    key = atoi(argv[1]);
    string text = get_string("plaintext: ");
    printf("ciphertext: %s\n", encrypt(text, key));
}

string encrypt(string text, int k)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        k > 26 ? k %= 26 : false;
        if (isalpha(text[i]))
        {
            if (text [i] <= 90)
            {
                text[i] = (text[i] + k) % 90;
                if (text[i] < 65)
                {
                    text[i] += 64;
                }
            }
            else
            {
                text[i] = (text[i] + k) % 122;
                if (text[i] < 97)
                {
                    text[i] += 96;
                }

            }
        }
    }
    return text;
}