/*
* This C++ program takes a text file and produces another text file that capitalizes the first character
* of each sentence and capitalizes all lowercase i's if it is by itself.
* 
* Example Case 1:
* Input: "c++ is fun. my friends and i are enjoying this assignment."
* Output: "C++ is fun. My friends and I are enjoying this assignment."
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
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

#include "functions_ana.h"
#include "helpers_ana.h"
#include "lab10_functions_suphia.h"

// Function Prototypes from functions_ana.h
void displayMainMenu();
void statesPopulation(char** &arrStates, int numStates);

// Function Prototypes from helpers_ana.h
void print2DArray(char** arr, int rows);

int main(){

    // Define variables
    int choice;

    // Display Main Menu
    displayMainMenu();
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1: // User chooses to create a text file to capitaliza the first character of each sentence and all individual i's
        {

                            
                string filename;
                string text;

                cout << " Enter score file name: ";
                cin >> filename;

                ifstream input(filename);
                ofstream out("output_suphia.txt"); 
                TexttoText_File(filename, input, out);
                CapitalizedLetters(text, out);
                    return 0;
        }

        
        case 2: // User chooses to input a text file to output to us_states_population_formatted.txt
        {
            // Define variable for the name of the text file
            string textFile;
            int rows = 51;   // 50 states

            // Prompt user to enter the name of the input file
            cout << "Enter the name of the text file: ";
            cin >> textFile;
            ifstream in(textFile);

            // Define 2D array of all the states, abbreviations, and populations
            char** states = getAllStates(in, rows);

            // Function to format the state names, abbreviations, and populations with commas
            statesPopulation(states, rows);

            // Free up memory
            for (int i = 0; i < 51; i++){
                delete[] states[i];
            }
            delete[] states;

        }

    }

    return 0;
}