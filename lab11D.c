/* 
Author: tobi akere (tobiakere@my.unt.edu)
Date: 12/05/2024
Instructor: Dr. Amar Maharjan
Description: This program reads distances in meters from an input file, converts them 
to feet using a macro, and writes the results to an output file specified by a command-line 
argument. It demonstrates the use of file I/O, macros, and command-line arguments in C.
*/

#include <stdio.h>
#include <stdlib.h>

#define METERS_TO_FEET 3.28084
#define convert(x) ((x) * METERS_TO_FEET)

int main(int argc, char *argv[]) {
    // Check if exactly one command-line argument is passed
    if (argc != 2) {
        printf("Error: Please provide exactly one output file name as a command-line argument.\n");
        return 1;
    }

    // Open the input file for reading
    FILE *inputFile = fopen("meters.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file 'meters.txt'.\n");
        return 1;
    }

    // Open the output file for writing
    FILE *outputFile = fopen(argv[1], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file '%s'.\n", argv[1]);
        fclose(inputFile); // Close input file before exiting
        return 1;
    }

    double meters, feet;

    // Read values from the input file and write converted values to the output file
    while (fscanf(inputFile, "%lf", &meters) != EOF) {
        feet = convert(meters);
        fprintf(outputFile, "%.3f\n", feet);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion completed. Results written to '%s'.\n", argv[1]);
    return 0;
}
