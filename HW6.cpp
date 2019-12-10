/* ======================================================================================= */
/* ======================================================================================= */
// Class: CS-1C
// Creator: Joshua Yang
// Contact: joshuayang0324@gmail.com
// Professor: Kath
// Date: 2/16/19
/* ======================================================================================= */
// Rules/Algorithm: Write a program that uses a random number generator to generate
// a three digit integer that allows the user to perform the following operation.
// 1. Sum the digits
// 2. Triple the number
// 3. Reverse the digitis
// b. Use an enum, typedef, and string variable
// c. Store 10 random numbers in an array
// d. Sort the array
// e. Write the array to an external file
// f. Call a function to read the external file
// g. Print the array in a function
// Use the command script to capture your interaction compiling and running 
// the program, including all operations, as shown below:
/* ======================================================================================= */
// Work: 
// CS1C Spring 2019 TTH HW-1 50pts Due: Th 1/24/2019
// cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ script hw01.scr
// Script started, file is hw01.scr
// cs1c@cs1c-VirtualBox ~/cs1c/hw01 $ date
// ... 
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ Is -1
// ... 
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ make all
// ...
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ Is -1
// ...
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ ./hw01
// ...//print out parts a, d & g above
// cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ exit
// Script done, file is hw01.scr
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ make tar
// ...
// Submit the tar package file hw01.tar by Thursday January 24, 2019.
/* ======================================================================================= */
/* ======================================================================================= */
// Code:


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string recursiveString(string &s, int l, int r)
{

    if (l >= r)
        return "";
    else
    {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        recursiveString(s, l + 1, r - 1);
    }
    return s;
}

string recursiveStringFor(const string &s, int l, int r)
{
    if (l >= r)
        return s;
    string result = s;
    for (int i = l, j = r; i < j; i++, j--)
    {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    return result;
}

int main()
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string input1, input2, input3;
    input1 = input2 = input3 = alphabet;
    int start, stop;
    string line;
    getline(cin, line);
    stringstream ss1(line);
    ss1 >> start;
    ss1.ignore();
    ss1 >> stop;
    ss1.clear();
    string extra1 = recursiveStringFor(input1, start, stop);
    string output1 = recursiveString(input1, start, stop);
    getline(cin, line);
    stringstream ss2(line);
    ss2 >> start;
    ss2.ignore();
    ss2 >> stop;
    string extra2 = recursiveStringFor(input2, start, stop);
    string output2 = recursiveString(input2, start, stop);
    string extra3 = recursiveStringFor(input3, 0, 25);
    string output3 = recursiveString(input3, 0, 25);
    cout << output1 << endl;
    cout << output2 << endl;
    cout << output3 << endl;
    cout << endl << "Extra path:" << endl;
    cout << extra1 << endl;
    cout << extra2 << endl;
    cout << extra3 << endl;
    return 0;
}

