/* 
Author: Tobi akere (tobiakere@my.unt.edu)
Date: 12/5/2024
Instructor: Dr. Amar Maharjan
Description: This program uses a dynamically allocated 2D array to store test scores 
of students and calculates their average scores. The number of students and tests 
per student are determined at runtime. Averages are stored in a dynamically allocated 
1D array and displayed. Dynamic memory is properly deallocated before termination.
*/

#include <iostream>
using namespace std;

// Function to input grades and calculate averages
void getGrades(int** grades, int number_of_students, double* average) {
    for (int i = 0; i < number_of_students; ++i) {
        int number_of_tests;
        cout << "How many tests for student #" << i + 1 << "? ";
        cin >> number_of_tests;

        // Allocate memory for the number of tests for this student
        grades[i] = new int[number_of_tests];

        // Input test scores
        int total = 0;
        for (int j = 0; j < number_of_tests; ++j) {
            cout << "Enter score for test #" << j + 1 << ": ";
            cin >> grades[i][j];
            total += grades[i][j];
        }

        // Calculate and store average
        average[i] = static_cast<double>(total) / number_of_tests;
    }
}

// Function to display averages
void dispAverage(double* average, int number_of_students) {
    for (int i = 0; i < number_of_students; ++i) {
        cout << "Average for student #" << i + 1 << ": " << average[i] << endl;
    }
}

int main() {
    int number_of_students;

    cout << "How many students? ";
    cin >> number_of_students;

    // Allocate memory for 2D array and 1D array
    int** grades = new int*[number_of_students];
    double* average = new double[number_of_students];

    // Get grades and calculate averages
    getGrades(grades, number_of_students, average);

    // Display averages
    dispAverage(average, number_of_students);

    // Free allocated memory
    for (int i = 0; i < number_of_students; ++i) {
        delete[] grades[i];
    }
    delete[] grades;
    delete[] average;

    return 0;
}
