/* 
Author: tobi akere (tobiakere@my.unt.edu)
Date: 12/05/2024
Instructor: Dr. Amar Maharjan
Description: This program reads a text file (specified by the user) using C-style file I/O. 
It counts the number of lines, words, and characters (excluding whitespaces) in the file. 
The program demonstrates the use of file pointers, file reading with `getc`, and basic 
text parsing in C.
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char filename[100];
    FILE *fp;
    char ch;
    int lines = 0, words = 0, chars = 0;
    int in_word = 0;

    // Prompt user for filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 1;
    }

    // Read the file one character at a time
    while ((ch = getc(fp)) != EOF) {
        // Count non-whitespace characters
        if (!isspace(ch)) {
            chars++;
        }

        // Count lines
        if (ch == '\n') {
            lines++;
        }

        // Count words
        if (isspace(ch)) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    // If the last character was part of a word, increment word count
    if (in_word) {
        words++;
    }

    // Close the file
    fclose(fp);

    // Display results
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters (excluding whitespaces): %d\n", chars);

    return 0;
}
