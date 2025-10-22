/*
* This C++ program takes a text file and produces another text file that capitalizes the first character
* of each sentence and capitalizes all lowercase i's if it is by itself.
* 
* Example:
* Input: "c++ is fun. my friends and i are enjoying this assignment."
* Output: "C++ is fun. My friends and I are enjoying this assignment."
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

using namespace std;

// Function Prototypes
void displayMainMenu();


/*
* This function returns an integer in the range [lower, upper]
* 
* @param lower // lower bound
* @param upper // upper bound
* @return an integer in [lower , upper]
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*
*/
void displayMainMenu()
{
    cout << "Welcome! Choose between the following options: " << endl;
    cout << "1. Create a text file to capitaliza the first character of each sentence and all individual i's" << endl;
    cout << "2. Input a text file to output to us_states_population_formatted.txt" << endl;
}