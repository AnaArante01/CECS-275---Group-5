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



// i want to first get a line of input 
int TexttoText_File (string& filename, ifstream& input, ofstream& out ) {
// prompt the user to enter the filename and open the file.

// Checks if file is opened and proceeds to go into a while loop, if failed it will display the error.
if( !input ) {             
        cout << " ERROR: could not read file." << endl;    
        return 1;
    }
    string line;
    while ((getline ( input, line))) {
        out << line << endl;
    }
    input.close();       // close all files
    out.close(); 
    return 0;
}