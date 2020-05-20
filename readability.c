#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");
    // creates variables for word, sentence and char amount
    int numwords, nsentences, nletters;
    // sets the base value of these variables to 0
    numwords = nsentences = nletters = 0;
    // sets parameters for loop, including introducing strlen usage by creating variable len
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        // introduces isalpha function to check for alphabetic characters in user input
        if (isalpha(s[i]))
        {
            nletters++;
        }

        // in the case of i == 0 being a character, we can also add 1 to our word count OR we can incriment another 1 to nwords if i is not the last charcater, not a blank space and i + 1 is not a blank space

        if ((i == 0 && s[i] != ' ') || (i != len - 1 && s[i] == ' ' && s[i + 1] != ' '))
        {
            numwords++;
        }

        // adds 1 to nsentences if any of these "sentence finishers" are found
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            nsentences++;

        }
    }
    // creates the variable for L, which is the average number of letters per 100 words
    float L = (nletters / (float) numwords) * 100;
    // variable for average number of sentences per 100 words
    float S = (nsentences / (float) numwords) * 100;
    // variable for Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
