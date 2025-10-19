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
#include "functions_ana.h"

using namespace std;

// Define variables
const int rows = 26;    // 26 letters in the alphabet
const int columns = 8;  // the width of the letters is 8 bits

// Convert a 2D array of hex values (26 letters x 8 columns) into
// a vector where each letter is represented by 8 strings of 8 bits.
// Example: result[0][3] is the 4th row (string of 8 chars) of letter A.
vector<vector<string>> hexToBinaryString(const int (*alphabet)[columns])
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

/****** Structures ******/
struct Picture{
    char ch;    // letter
    unsigned char* bytes;   // array of 8 bytes
};

struct Font{
    int ROW;    // 8 rows
    int COL;    // 8 columns
    Picture* letters;   // static array of pictures
};


int main()
{
    ofstream out;
    out.open("test_ana.txt");
    
    Font regular;
    regular.ROW = 7;
    regular.COL = 5;
    regular.letters = new Picture[rows];
    
    Font bold; 
    bold.ROW = 8;
    bold.COL = 8;
    bold.letters = new Picture[rows];

    //  this array is the size of regular letters 
    // 26 rows and 8 columns ( 8x8 letters)
    // REGULAR ALPHABET
    const int Reg_AlphData[rows][columns]= {
        // letter A
        { 0x08, 0x02, 0x14, 0x22, 0x3E,  0x22, 0x22, 0x22},
        // letter B
        { 0x7C, 0x42, 0x42, 0x7C, 0x42, 0x42, 0x42, 0x7C},
        // letter C
        { 0x1C, 0x22, 0x40, 0x40, 0x40, 0x40, 0x22, 0x1C},
        // letter D 
        { 0x7C, 0x42, 0x41, 0x41, 0x41, 0x41, 0x42, 0x7C},
        // letter E
        { 0x7E, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40},
        // letter  F
        { 0x7E, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40},
        // letter G
        { 0x7C, 0x40, 0x40, 0x40, 0x4E, 0x4A, 0x42, 0x7C},
        // letter H
        { 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42},
        // letter I 
        { 0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7C},
        // letter J
        { 0x7E, 0x18, 0x18, 0x18, 0x18, 0x58, 0x58, 0x78},
        // letter K
        { 0x22, 0x24, 0x28, 0x30, 0x28, 0x24, 0x22, 0x21},
        // letter L
        { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3E},
        // letter M 
        { 0x81, 0xC3, 0xA5, 0x99, 0x81, 0x81, 0x81, 0x81},
        // letter N
        { 0x81, 0xC1, 0xA1, 0x91, 0x89, 0x85, 0x83, 0x81},
        // letter O 
        { 0x3C, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3C},
        // letter P 
        { 0x3C, 0x22, 0x21, 0x22, 0x3C, 0x20, 0x20, 0x20},
        // letter Q
        { 0x7E, 0xC3, 0x81, 0x81, 0x81, 0xCB, 0x64, 0x3A},
        // letter R
        { 0x7C, 0x42, 0x42, 0x42, 0x7C, 0x50, 0x4C, 0x42},
        // letter S
        { 0x38, 0x44, 0x40, 0x40, 0x38, 0x04, 0x44, 0x38},
        // letter T 
        { 0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},
        // Letter U
        { 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7E},
        // Letter V
        { 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x24, 0x18},
        // letter W 
        { 0x81, 0x81, 0x81, 0x81, 0x81, 0x99, 0xA5, 0xC3},
        // letter X
        { 0x81, 0x42, 0x24, 0x18, 0x24, 0x42, 0x81, 0x81}, 
        // letter Y
        { 0x81, 0x42, 0x24, 0x18, 0x18, 0x18, 0x18, 0x18},
        // letter Z 
        { 0xFE, 0x06, 0x04, 0x08, 0x10, 0x60, 0x40, 0x7F}
    };

    for (int i = 0; i < rows; ++i){
        regular.letters[i].ch = 'A' + i;
        regular.letters[i].bytes = new unsigned char[columns];
        for (int j = 0; j < columns; ++j){
            regular.letters[i].bytes[j] = Reg_AlphData[i][j];
        }
    }
    
    // BOlD ALPHABET
    const int BoldAlphabet[rows][columns] = {  
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

    for (int i = 0; i < rows; ++i){
        bold.letters[i].ch = 'A' + i;
        bold.letters[i].bytes = new unsigned char[columns];
        for (int j = 0; j < columns; ++j){
            bold.letters[i].bytes[j] = BoldAlphabet[i][j];
        }
    }

    string message;
    cout << "Enter a message: ";
    getline(cin, message);
    
    bool getIndex(char ch, int& index){
        if (ch >= 'A' && ch <= 'Z'){
            index = ch - 'A';
            return true;
        }
        if (ch >= 'a' && ch <= 'z'){
            index = ch - 'a';
            return true;
        }
        // If not a letter, return false
        return false;
    }

    void getMessage(const Font& font, const string& message,
                    const char* on, const char* off, int spacing)
    {
        for (int r = 0; r < font.ROW; ++r){
            for (size_t i = 0; i < message.size(); ++i){
                char ch = message[i];
                int index;
                bool valid = getIndex(ch, index);
            
                if (ch == ' '){
                    for (int c = 0; c < font.COL; ++c)
                    {
                        cout << off;
                    }
                    cout << string(spacing * 2, ' ');
                    continue;
                }

                if (valid){
                    unsigned char byte = font.letter[index].bytes[r];
                    int divisor = 128;  // 2^7 = MSB

                    for (int c = 0; c < font.COL; ++c){
                        int bit = (byte / divisor) % 2; // divide by 128, 64, 32, etc.
                        if (bit == 1){
                            cout << on;
                        }
                        else[
                            cout << off;
                        ]

                        divisor /= 2;
                    }
                }
            }
        }
    }
    
    /*
    auto bin = hexToBinaryString(BoldAlphabet);

    for (size_t letter = 0; letter < bin.size(); ++letter) {
        out << "Letter " << static_cast<char>('A' + letter) << ":\n";
        for (const auto &row : bin[letter]) {
            out << row << '\n';
        }
        out << '\n';
    }
    */


    out.close();

    return 0;   // End of program
}