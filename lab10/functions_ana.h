/*
* This C++ program takes a text file and produces another text file that capitalizes the first character
* of each sentence and capitalizes all lowercase i's if it is by itself.
* 
* Example Case 2:
* Input: Alabama,AL,4447100
* Output: Alabama  AL  4,447,100
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
void displayMainMenu();
void print2DArray(char** arr, int rows);


/*
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
    std::cout << "Welcome! Choose between the following options: " << std::endl;
    std::cout << "1. Create a text file to capitaliza the first character of each sentence and all individual i's" << std::endl;
    std::cout << "2. Input a text file to output to us_states_population_formatted.txt" << std::endl;
}



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
char** getAllStates(std::ifstream &input, int numRows)
{
    const int maxChar = 100;
    char** allStates = new char*[numRows]; // Declare 2D array pointer to get all states

    for (int i = 0; i < numRows; ++i){
        allStates[i] = new char[maxChar];
        allStates[i][0] = '\0';
    }

    int i = 0;
    while (input.getline(allStates[i], maxChar) && i < numRows - 1){
        ++i;
    }

    return allStates;
}


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
// first have to create a 2D array of all of the input file
void statesPopulation(char* line, char* state, char* abbrev, char* pop)
{
    /*
    int count = 0;  // Loop counter
    
    std::ifstream input("inputfile.txt");
    if (!input.is_open()) {
        std::cerr << "Error opening inputfile.txt" << std::endl;
        return;
    }
    
    while (input.getline(maxChar) && count < 50) {
        // Process the line here
        count++;
    }
    
    input.close();
    */
}



