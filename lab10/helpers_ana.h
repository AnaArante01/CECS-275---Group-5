/*
* This C++ header file contains functions to help check the functionality of the main program
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>

// Function Prototypes
void print2DArray(char** arr, int rows);


/*
* This function prints the contents of a 2D character array
* @param arr The 2D array to print
* @param rows The number of rows in the array
*/
void print2DArray(char** arr, int rows)
{
    if (arr == nullptr) {
        std::cout << "Array is null" << std::endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        if (arr[i] != nullptr) {
            std::cout << arr[i] << std::endl;
        }
    }
}