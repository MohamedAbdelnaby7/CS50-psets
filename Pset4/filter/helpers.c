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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int8_t gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2}, 
        {-1, 0, 1}
    }; 
    int8_t gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
        
    };
    
    int gxR, gxG, gxB, gyR, gyG, gyB, gR, gG, gB;
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
            gxR = gxG = gxB = gyR = gyG = gyB = 0;
            for (int row = 0; row < 3; row++)
            {
                for (int column = 0; column < 3; column++)
                {
                    if (i + row - 1 < 0 || i + row - 1  >= height || j + column - 1 < 0 || j + column - 1 >= width)
                    {
                    }
                    else
                    {
                        gxR += (gx[row][column] * copy[i + row - 1][j + column - 1].rgbtRed);
                        gxG += (gx[row][column] * copy[i + row - 1][j + column - 1].rgbtGreen);
                        gxB += (gx[row][column] * copy[i + row - 1][j + column - 1].rgbtBlue);
                        gyR += (gy[row][column] * copy[i + row - 1][j + column - 1].rgbtRed);
                        gyG += (gy[row][column] * copy[i + row - 1][j + column - 1].rgbtGreen);
                        gyB += (gy[row][column] * copy[i + row - 1][j + column - 1].rgbtBlue);
                    }
                }
            }
            gR = round(sqrt(pow(gxR, 2) + pow(gyR, 2))); 
            gG = round(sqrt(pow(gxG, 2) + pow(gyG, 2))); 
            gB = round(sqrt(pow(gxB, 2) + pow(gyB, 2))); 
            
            gR > 255 ? gR = 255 : 0;
            gG > 255 ? gG = 255 : 0;
            gB > 255 ? gB = 255 : 0;
            
            image[i][j].rgbtRed = gR;
            image[i][j].rgbtGreen = gG;
            image[i][j].rgbtBlue = gB;
        }
    } 
}
