#include <cs50.h>
#include <stdio.h>
#include <math.h>

int numberofletters(string text);
int numberofwords(string text);
int numberofsentences(string text);
int Coleman_Liau(float l, float w, float s);

int main(void)
{
    int letterNumber, wordNumber, sentenceNumber, grade;
    string text = get_string("Text: ");
    letterNumber = numberofletters(text);
    wordNumber = numberofwords(text);
    sentenceNumber = numberofsentences(text);
    grade = Coleman_Liau((float)letterNumber, (float)wordNumber, (float)sentenceNumber);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int numberofletters(string text)
{
    int n = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            n++;
        }
    }
    return n;
}

int numberofwords(string text)
{
    int n = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            n++;
        }
    }
    return n;
}

int numberofsentences(string text)
{
    int n = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            n++;
        }
    }
    return n;
}

int Coleman_Liau(float l, float w, float s)
{
    l = 100 * l / w;
    s = 100 * s / w;
    return round(0.0588 * l - 0.296 * s - 15.8);
}