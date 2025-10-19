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
#include <string>
#include <vector>
#include <cctype>
#include <bitset>

using namespace std;

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


