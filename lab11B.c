/* 
Author: tobi akere (tobiakere@my.unt.edu)
Date: 12/05/2024
Instructor: Dr. Amar Maharjan
Description: This program calculates the running average of doubles entered by the user. 
It dynamically allocates memory using `malloc` and expands it as needed using `realloc`. 
The program displays the cumulative list of numbers and their updated average after each 
entry. The loop terminates based on the user's decision. 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    double* numbers = (double*)malloc(sizeof(double)); // Allocate memory for one double
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int count = 0;
    double sum = 0.0;
    char choice;

    do {
        double num;
        printf("Enter a number: ");
        scanf("%lf", &num);

        // Update memory with realloc for the next number
        numbers = (double*)realloc(numbers, (count + 1) * sizeof(double));
        if (numbers == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        numbers[count] = num;
        sum += num;
        count++;

        // Display all numbers and their average
        printf("Numbers entered so far: ");
        for (int i = 0; i < count; i++) {
            printf("%.2lf ", numbers[i]);
        }
        printf("\nCurrent average: %.2lf\n", sum / count);

        // Ask user if they want to enter more numbers
        printf("Do you want to enter another number? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume newline
    } while (choice == 'y' || choice == 'Y');

    // Free the allocated memory
    free(numbers);

    return 0;
}
