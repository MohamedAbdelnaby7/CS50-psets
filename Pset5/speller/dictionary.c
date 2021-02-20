// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 16384;

// Hash table
node *table[N];
int words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char copy[strlen(word) + 1];
    strcpy(copy, word);
    char *p = copy;
    for ( ; *p != '\0'; p++) *p = tolower(*p);

    unsigned int key = hash (copy);
    node *temp = table[key];
    while (temp != NULL)
    {
        if (strcmp (copy, temp->word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c = 0;

    while (c == *word++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char buffer[LENGTH];
    while(fscanf(file, "%s", buffer) != EOF)
    {
        unsigned int key = hash(buffer);
        node *nodal = malloc(sizeof(node));
        if (nodal == NULL)
        {
            return false;
        }
        strcpy(nodal->word, buffer);
        if (table[key] != NULL)
        {
            nodal->next = table[key];
        }
        table[key] = nodal;
        words++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}