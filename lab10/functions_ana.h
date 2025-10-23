/*
* This C++ program takes a text file and produces another text file that adds spaces and commas between the
* state, abbreviation, and population number.
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
void statesPopulation(char** &arrStates, int numStates);


/*
* This function does not return anything and only displays the main menu
*
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*
*/
void displayMainMenu()
{
    std::cout << "\nWelcome! Choose between the following options: " << std::endl;
    std::cout << "1. Create a text file to capitaliza the first character of each sentence and all individual i's" << std::endl;
    std::cout << "2. Input a text file to output to us_states_population_formatted.txt" << std::endl;
}

/*
* This function returns a 2D array pointer that stores everything from inputfile.txt
*
* @param input   // input from file
* @param numRows // number of rows in the file
* @return allStates // char 2D array pointer
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
* This function returns an integer in the 
* 
* @param lower // lower bound
* @param upper // upper bound
* @return an integer in [lower , upper]
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*
*/
void statesPopulation(char** &arrStates, int numStates)
{
    // Open output file once before the loop
    std::ofstream out("us_states_population.txt");
    
    for (int i = 0; i < numStates; ++i) {

        char* line = arrStates[i];
        const int stateSize = 64;   // Number of bytes reserved for state name
        const int abbrevSize = 8;   // Number of bytes reserved for abbreviation
        const int popSize = 32;     // Number of bytes reserved for population size

        char state[stateSize] = {};
        char abbrev[abbrevSize] = {};
        char pop[popSize] = {};

        int position = 0;
        int writePos = 0;

        // Get state name
        while (line[position] != ',' && writePos < stateSize - 1) {
            state[writePos++] = line[position++];
        }
        state[writePos] = '\0';
        if (line[position] == ','){
            ++position; // skip comma
        } 

        // Get abbreviation
        writePos = 0;
        while (line[position] != ',' && writePos < abbrevSize - 1) {
            abbrev[writePos++] = line[position++];
        }
        abbrev[writePos] = '\0';
        if (line[position] == ',') ++position; // skip comma

        // Get population
        writePos = 0;
        while (writePos < popSize - 1) {
            pop[writePos++] = line[position++];
        }
        pop[writePos] = '\0';

        // Format population with commas
        char formattedPop[popSize] = "";
        char tempPop[popSize] = "";
        strcpy(tempPop, pop);
        int len = strlen(tempPop);
        
        // Work from right to left, copying digits and adding commas
        int readPos = len - 1;     // Position in original number
        int writeP = popSize - 2;  // Position in formatted number (leave room for null)
        int digitCount = 0;
        
        while (readPos >= 0 && writeP >= 0) {
            if (digitCount > 0 && digitCount % 3 == 0) {
                formattedPop[writeP--] = ',';
            }
            formattedPop[writeP--] = tempPop[readPos--];
            digitCount++;
        }
        
        // Shift result to beginning of formattedPop
        int startPos = writeP + 1;
        if (startPos > 0) {
            memmove(formattedPop, formattedPop + startPos, strlen(formattedPop + startPos) + 1);
        }

        // Write formatted output for state, abbreviation, and formatted population with commas
        out << std::setw(15) << state 
            << std::setw(8)  << abbrev 
            << std::setw(15) << formattedPop << std::endl;
    }

    std::cout << endl;
    std::cout << "Formatted output printed successfully! Please check us_states_population.txt" << std::endl;

    // Close file once after all states are written
    out.close();
}




