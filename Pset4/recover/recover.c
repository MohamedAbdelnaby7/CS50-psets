#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image");
        return 1;
    }
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Can't open the file %s\n", infile);
        return 2;
    }
    
    uint8_t buffer [512];
    FILE *outptr = NULL;
    int imageNumber = 0;
    char newimage [8];
    
    while (true)
    {
        size_t streamedBytes = fread(buffer, sizeof(uint8_t), 512, inptr);
        if (streamedBytes == 0 && feof(inptr))
        {
            break;
        }
        
        bool isJPG = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
        if (isJPG && (outptr != NULL))
        {
            fclose(outptr);
            imageNumber++;
        }
        if (isJPG)
        {
            sprintf(newimage, "%03i.jpg", imageNumber);
            outptr = fopen(newimage, "w");
        }
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), streamedBytes, outptr);
        }
    }
    fclose(inptr);
    fclose(outptr);
}
