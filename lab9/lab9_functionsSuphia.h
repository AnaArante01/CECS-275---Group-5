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
    vector<char> letters;
    for (char ch : message) {
        ch = toupper(static_cast<unsigned char>(ch));
        if ((ch >= 'A' && ch <= 'Z') || (ch == ' ')){
            letters.push_back(ch);
        }
    }
    for (int row = 0; row < 7; row++) { // For each row of the letters
        for (char ch : letters){
            if (ch == ' '){
                cout << "  ";
                continue;
            }
    
            int letterIdx = (ch - 'A');
            int hexValue = *(charData + (letterIdx * col) + row);

            for (int bit = 5; bit >= 0; bit--){
                if (hexValue & (1 << bit)){
                    cout << "\033[48;2;255;105;180m*\033[0m";
                }
                else{
                    cout << " ";
                }
            }
            cout << " ";
        }
        cout << endl;
    }
}


void PrintBoldAlphabet (int *charData, int rows, int col, string& message ){
// i want it to read the users input message and display it using our letters in regular 
// when user inputs a message it will first loop through the characters through the message 
    vector<int> letters;
    for (char ch : message) {
        ch = toupper(static_cast<unsigned char>(ch));
        if ((ch >= 'A' && ch <= 'Z') || (ch == ' ')){
            letters.push_back(ch);
        }
    }

    for (int row = 0; row < 8; row++){
        for (char ch : letters){
            if (ch == ' '){
                cout << "  ";
                continue;
            }

            int letterIdx = (ch - 'A');
            int hexValue = *(charData + (letterIdx * col) + row);

            for (int bit = 7; bit >= 0; bit--){
                if (hexValue & (1 << bit)){
                    cout << "\033[48;2;255;105;180m*\033[0m";
                }
                else{
                    cout << " ";
                }
            }
            cout << " ";
        }
        cout << endl;
    }
}



