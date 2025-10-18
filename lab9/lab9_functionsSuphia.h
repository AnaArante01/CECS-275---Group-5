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


string Conversion_Binary(int *charData, int rows, int cols ){
// u have to start with some sort of input 
// take a string , run it with calculations based off of an int then convert tghat intoa string of binary values,
// the pointers are accessing the data within the const so the data that is inputted the value inside that is what were are pointing too
// i can only use pointers and arrays only
string binaryString = "";
// loop through each row of the character pattern
for ( int row = 0; row < rows; row++){
    // get the hex value at current row 
    int hexValue = *(charData + row);

    // for each row eaxamine each bit from left to right (msb to lsb)
    // start from the leftmost bit (cols-2) and work down to bit 0
    for (int bit = cols -1; bit >= 0; bit--){
            // access the hex value at current row using pointer arithmetic
            // * (charData + row) gets the hex value  at the current row
            // Example: if charData points to letter 'A' and row=0, 
            // *(charData + 0) gives us 0x08 (first row of letter A)
            
            // Create a bit mask using left shift: (1 << bit)
            // This creates a binary number with only one bit set at position 'bit'
            // Example: (1 << 3) creates 0b00001000 = 8 in decimal
            
            // Use bitwise AND (&) to test if the specific bit is set
            // *(charData + row) & (1 << bit) returns non-zero if bit is set, 0 if not
            // Example: 0x08 & (1 << 3) = 0b00001000 & 0b00001000 = 0b00001000 (true)
            //          0x08 & (1 << 2) = 0b00001000 & 0b00000100 = 0b00000000 (false)
            
        if (hexValue & (1 << bit)) {
          binaryString += "1";
          cout << "**";
        } else { 

            binaryString += "0";
            cout << "  ";
        }
    }
    cout << endl;
        
  }
  return  binaryString;
}
// this function will divide the strings by rows and columns 
void RegAlphabet (int *charData, int rows, int cols ) {

    for (int row = 0; row < rows; row++){
        int hexValue = *(charData + row);
        for ( int bit = cols - 1; bit >= 0; bit--){

        }

    }



}

void BoldAlphabet (int *charData, int rows, int cols){

}
// Function Prototypes
void print1DArray(int* arr, int size);

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
void print1DArray(int* arr, int size){
    for (int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
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
void printBinaryAlphabet(ostream &out, const vector<vector<string>> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        out << "Letter " << static_cast<char>('A' + i) << ":\n";
        for (const auto &row : arr[i]) out << row << '\n';
        out << '\n';
    }
}

