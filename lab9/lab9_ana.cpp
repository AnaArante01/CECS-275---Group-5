/*
* This C++ program creates two sets of alphabets. One is regular (7 x 5) and one is bolded (8 x 8).
* This program allows the user to enter a message and display their message using the created alphabets.
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

// Header Files
#include "functions.h"

using namespace std;

// Define variables
const int rows = 26;    // 26 letters in the alphabet
const int columns = 8;  // the width of the letters is 8 bits


// Convert a 2D array of hex values (26 letters x 8 columns) into
// a vector where each letter is represented by 8 strings of 8 bits.
// Example: result[0][3] is the 4th row (string of 8 chars) of letter A.
vector<vector<string>> hexToBinaryString(const int alphabet[][columns])
{
    vector<vector<string>> binaryArray;

    for (int i = 0; i < rows; ++i) {
        vector<string> letterRows;

        for (int j = 0; j < columns; ++j) {
            unsigned int value = static_cast<unsigned int>(alphabet[i][j]) & 0xFFu;
            string bits = "";

            // build 8-bit string from MSB to LSB
            for (int b = 7; b >= 0; --b) {
                if ( (value >> b) & 1u ) bits += '1';
                else bits += '0';
            }

            letterRows.push_back(bits);
        }

        binaryArray.push_back(letterRows);
    }

    return binaryArray;
}

int main()
{
    ofstream out;
    out.open("test_ana.txt");

    const int BoldAlphabet[rows][columns] = {   // don't know if we have to make it a pointer
        // Bold A
        { 0x3C, 0x66, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3 },
        // Bold B
        { 0xFE, 0xC1, 0xFE, 0xFF, 0xFF, 0xE3, 0xC3, 0xFE },
        // Bold C
        { 0x7E, 0xFF, 0xC3, 0xC0, 0xC0, 0xC3, 0xFF, 0x7E },
        // Bold D
        { 0xFE, 0xC7, 0xC3, 0xC3, 0xC3, 0xC3, 0xC7, 0xFE },
        // Bold E
        { 0xFF, 0xFF, 0xC0, 0xFC, 0xFC, 0xC0, 0xFF, 0xFF },
        // Bold F
        { 0xFF, 0xFF, 0xC0, 0xFC, 0xFC, 0xC0, 0xC0, 0xC0 },
        // Bold G
        { 0x7E, 0xFF, 0xC3, 0xC0, 0xC7, 0xC3, 0xFF, 0x7E },
        // Bold H
        { 0xC3, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3 },
        // Bold I
        { 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF },
        // Bold J
        { 0x3F, 0x3F, 0x0C, 0x0C, 0xCC, 0xCC, 0xFC, 0x78 },
        // Bold K
        { 0xC3, 0xC6, 0xCC, 0xF0, 0xD8, 0xCC, 0xC6, 0xC3 },
        // Bold L
        { 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF },
        // Bold M
        { 0xC3, 0xEF, 0xFB, 0xD3, 0xC3, 0xC3, 0xC3, 0xC3 },
        // Bold N
        { 0xC3, 0xF3, 0xFB, 0xDF, 0xCF, 0xC3, 0xC3, 0xC3 },
        // Bold O
        { 0x7E, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0x7E },
        // Bold P
        { 0xFE, 0xFF, 0xC3, 0xFF, 0xFE, 0xC0, 0xC0, 0xC0 },
        // Bold Q
        { 0x7E, 0xFF, 0xC3, 0xC3, 0xDB, 0xFF, 0x7F, 0x18 },
        // Bold R
        { 0xFE, 0xFF, 0xC3, 0xFF, 0xFE, 0xDC, 0xCE, 0xC7 },
        // Bold S
        { 0x7E, 0xFF, 0xC3, 0x78, 0x1E, 0xC3, 0xFF, 0x7E },
        // Bold T
        { 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18 },
        // Bold U
        { 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x3C },
        // Bold V
        { 0x66, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x3C, 0x18 },
        // Bold W
        { 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xDB, 0x7E, 0x66 },
        // Bold X
        { 0xC3, 0x66, 0x3C, 0x18, 0x18, 0x3C, 0x66, 0xC3 },
        // Bold Y
        { 0xC3, 0xE7, 0x7E, 0x3C, 0x18, 0x18, 0x18, 0x18 },
        // Bold Z
        { 0xFF, 0xFF, 0x07, 0x0E, 0x38, 0xE0, 0xFF, 0xFF }
    };

    
    auto bin = hexToBinaryString(BoldAlphabet);

    for (size_t letter = 0; letter < bin.size(); ++letter) {
        out << "Letter " << static_cast<char>('A' + letter) << ":\n";
        for (const auto &row : bin[letter]) {
            out << row << '\n';
        }
        out << '\n';
    }

    // Uses printBinaryAlphabet in functions.h file
    //auto bin = hexToBinaryString(BoldAlphabet);
    //printBinaryAlphabet(out, bin);

    out.close();

    return 0;   // End of program
}