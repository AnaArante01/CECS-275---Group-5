/*
* This C++ program creates two sets of alphabets. One is regular (7 x 5) and one is bolded (8 x 8).
* This program allows the user to enter a message and display their message using the created alphabets.
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/
// herro
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Student{
    string name;
    double gpa;
};
struct Course{
    string name;
    string meetingDate;
    int totalStudents;
    Student* students;
};

#include "functions.h"

int* createArray(int size);
void printArray(int* arr, int size);
void printClassInfo(Course& course){
    cout << course.name << endl;
    cout << course.meetingDate << endl;
    cout << course.totalStudents << endl;
    cout << course.students[0].name << endl;
    cout << course.students[0].gpa << endl;
}

int main(){

    Student student1;
    student1.name = "Ana";
    student1.gpa = 3.0;

    Course cecs275;
    cecs275.name = "CECS 275";
    cecs275.meetingDate = "MW";
    cecs275.totalStudents = 40;
    cecs275.students = new Student[cecs275.totalStudents];
    cecs275.students[0] = {student1};

    //cout << cecs275.name << endl;
    //cout << cecs275.meetingDate << endl;
    //cout << cecs275.totalStudents << endl;
    //cout << cecs275.students[0].name << endl;
    //cout << cecs275.students[0].gpa << endl;
    printClassInfo(cecs275);


    // To increase the size of an array
    // Rule of thumb: any time you use new, you must use delete
    srand(time(0));
    int size = 10;
    int* arr = createArray(size);
    printArray(arr,size);
    int* temp = new int[2 * size] {0};
    printArray(temp, 2 * size);
    cout << endl;
    for (int i = 0; i < size; ++i){
        temp[i] = arr[i];
    }
    printArray(temp, 2 * size);
    cout << endl;
    delete [] arr;
    size *= 2;
    arr = temp;
    printArray(arr, size);
    cout << endl;
    delete [] temp;

    return 0;

}

    int *createArray(int size){
        int* arr = new int[size];
        for (int i = 0; i < size; ++i){
            arr[i] = rand() % 100 + 1;
        }
        return arr;
    }





