/*
ROT Encryption

Author: Paulo Mota
Language: C

DESCRIPTION: A simple program to encrypt strings of text,
using a ROT cypher (ex.: ROT13, Caesar Cypher). Each character
in the string is "shifted" by <key> positions in the alphabet.

USAGE: Run the program, passing the key as an argument. Key must
be an integer, and refers to the number of characters to "rotate".
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h> // non-standard lib, shorthands for user input, ex.: GetString()
                        
int main(int argc, string argv[])
{
    // Variable prototypes
    int rotKey = 0;
    int checkKey = 0; // May instead use boolean (bool), defaulted at false
    string message = "";
    
    // Validating argument input
    do
    {
        if(argc != 2) // Program runs only if a single argument is present
        {
            printf("The argument you entered is not valid, please try again.\n");
            return 1;
        }
        else // If argument is valid, proceed with respective typecasting (char to int)
        {
            rotKey = atoi(argv[1]);
            checkKey = 1;
        }
    }
    while(checkKey != 1);
    
    // Retrieving, processing and printing the message (case-sensitive)
    message = GetString();

    for(int i = 0, x = strlen(message); i < x; i++)
    {
        if(isalpha(message[i])) // If char is alphabetical, shift and print
        {
            if(islower(message[i]))
            {
                printf("%c", ((((message[i] - 97) + rotKey) % 26) + 97));
            }
            else  // isupper(message[i])
            {
                printf("%c", ((((message[i] - 65) + rotKey) % 26) + 65));
            }
        }
        else // If char is non-alphabetical print as-is, to preserve punctuation
        {
            printf("%c", message[i]);
        }
    }
    
    // End the program, keeping output clean
    printf("\n");
    return 0;
}