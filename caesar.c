#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // atoi converts ascii chars to ints
    int k = atoi(argv[1]);

    if (k <= 0)
    {
        printf("Key must be positive number\n");
        return 1;
    }

    if (k >= 1)
    {
        printf("Success\n");
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // character classicication function
        if islower(plaintext[i])
        {
            // ci = (pi + k) % 26
            printf("%c", (plaintext[i] - 'a' + k) % 26 + 'a');
        }
        // character classification function
        else if (isupper(plaintext[i]))
        {
            // adapted formula for uppercase characters
            printf("%c", (plaintext[i] - 'A' + k) % 26 + 'A');
        }

        else
        {
            printf("%c", plaintext[i]);
        }


    }
    printf("\n");
    return 0;

}

