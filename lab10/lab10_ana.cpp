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

int main(){

    // Define variables
    string choice;

    // Display Main Menu
    displayMainMenu();
    cout << "Enter choice: " << endl;
        // cin.get has overloads for reading a single character or a char buffer, but not a std::string.
        // Use getline to read a full line into a std::string.
        getline(cin, choice);
    // Placeholder: handle the user's menu choice here.
    // e.g. if (choice == "1") { ... } else if (choice == "Q") { ... }
*** End Patch
    return 0;
}