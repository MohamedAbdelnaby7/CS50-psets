#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / (float)3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg; 
        }
    } 
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    sepiaRed = sepiaGreen = sepiaBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed  + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed  + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            
            sepiaRed > 255 ? sepiaRed = 255 : 0;
            sepiaGreen > 255 ? sepiaGreen = 255 : 0;
            sepiaBlue > 255 ? sepiaBlue = 255 : 0;
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = width - 1; j < width / 2; j++, k--)
        {
            temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;
        }
    } 
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avgR, avgG, avgB, n;
    RGBTRIPLE copy[height][width];
    
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            copy[k][l] = image[k][l];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avgR = avgG = avgB = n = 0;
            
            for (int row = -1; row < 2; row++)
            {
                for (int column = -1; column < 2; column++)
                {
                    if (i + row < 0 || i + row >= height || j + column < 0 || j + column >= width)
                    {
                    }
                    else
                    {
                        avgR += copy[i + row][j + column].rgbtRed;
                        avgG += copy[i + row][j + column].rgbtGreen;
                        avgB += copy[i + row][j + column].rgbtBlue;
                        n++;
                    }
                }
            }
            image[i][j].rgbtRed = round(avgR / (float)n);
            image[i][j].rgbtGreen = round(avgG / (float)n);
            image[i][j].rgbtBlue = round(avgB / (float)n);
        }
    } 
    return;
}
