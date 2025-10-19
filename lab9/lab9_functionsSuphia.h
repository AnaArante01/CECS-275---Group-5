/*
* This C++ program contains the functions to create two sets of alphabets.
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>  // Make sure this is included
#include <vector>
#include <cctype>
#include <bitset>
using namespace std;


void PrintRegAlphabet (int *charData, int rows, int col, string& message ) {
// i want it to read the users input message and display it using our letters in regular 
// when user inputs a message it will first loop through the characters through the message 
vector<int> letterIndices;
for (char ch : message) {
    ch = toupper(ch);
    if (ch >= 'A' && ch <= 'Z'){
        letterIndices.push_back(ch - 'A');
    }
}
for (int row = 0; row < 5; row++) { // For each row of the letters
    for (int letterIdx : letterIndices) {  // For each letter in the message
        // Print the current row of this letter
            // Check if the bit at position 'col' is set (1) in the current row of the letter
            // This uses bitwise AND to test if a specific bit position contains a 1 or 0
            int hexValue = *(charData + (letterIdx * col) + row);
            for ( int col = 5; col >= 0; col--){
            if (hexValue & (1 << col)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << " ";  // Add space between letters
    }
    cout << endl;  // New line after each row
    }
  }
void PrintBoldAlphabet (int *charData, int rows, int col, string& message ){
// i want it to read the users input message and display it using our letters in regular 
// when user inputs a message it will first loop through the characters through the message 
vector<int> letterIndices;
for (char ch : message) {
    ch = toupper(ch);
    if (ch >= 'A' && ch <= 'Z'){
        letterIndices.push_back(ch - 'A');
    }
}
for (int row = 0; row < 8; row++) { // For each row of the letters
    for (int letterIdx : letterIndices) {  // For each letter in the message
            // Print the current row of this letter
            // Check if the bit at position 'col' is set (1) in the current row of the letter
            // This uses bitwise AND to test if a specific bit position contains a 1 or 0
            int hexValue = *(charData + (letterIdx * col) + row);
            for ( int bit = 7; bit >= 0; bit--){
            if (hexValue & (1 << bit)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << " ";  // Add space between letters
    }
    cout << endl;  // New line after each row
    }
  }

