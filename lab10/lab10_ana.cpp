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

// Function Prototypes from functions_ana.h


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



        }
        case 2: // User chooses to input a text file to output to us_states_population_formatted.txt
        {
            // Define variable for the name of the text file
            string textFile;
            int rows = 51;   // 50 states
            int cols = 1;    // get each line

            cout << "Enter the name of the text file: " << endl;
            cin >> textFile;
            ifstream in(textFile);

            char** states = getAllStates(in, rows);
            print2DArray(states, 51);

            // Free up memory
            for (int i = 0; i < 51; i++){
                delete[] states[i];
            }
            delete[] states;






        }



    }











    return 0;
}