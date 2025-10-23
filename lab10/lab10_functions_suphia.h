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


// this function takes the input of the text file and then outputs 
// another  text file that capitalizes the first character 
// of each sentence and capitalizes all lowercase i's if it by itself

string CapitalizedLetters( string& text,  ofstream& out){
    bool capitalizeNext = true;
 
        // loop through each character in the string

        for ( int x = 0; x < text.length(); x++){
            char current = text[x];
            // if its the first character of the string or a space, then capitalize it
            if ( capitalizeNext && isalpha(current) ){ // checking for first letter the sentence
                text[x] = toupper(text[x]); // convert the character to uppercase 
                capitalizeNext = false;
            }
           else if ( current == 'i'){
                bool alone = true;
                
                if (x > 0 && isalpha(text[x-1])){
                    alone = false;
                }
                    if ( x < text.length() && isalpha(text[x+1])){
                        alone = false;
                    }
                    if (alone) {
                    text[x] = 'I';
                }
            }
           
            if (current == '.' || current == '?' || current == '!')
            {
                text[x] = toupper(text[x]);
                capitalizeNext = true;
            }
        }
        return text; // return the modified string
}

// i want to first get a line of input 
int TexttoText_File (string& filename, ifstream& input, ofstream& out ) {

// Checks if file is opened and proceeds to go into a while loop, if failed it will display the error.
if( !input ) {             
        cout << " ERROR: could not read file." << endl;    
        return 1;
    }
    string line;
    while ((getline ( input, line))) {
        // process each line 
        string processedLine = CapitalizedLetters(line, out);
        out << processedLine << endl;
        cout << "Outputted to output file: " << processedLine << endl;

    }
    input.close();       // close all files
    //out.close(); 
    return 0;
}

