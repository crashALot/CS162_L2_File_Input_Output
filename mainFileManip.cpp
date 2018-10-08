/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: This program reads a file filled with letters, counts 
*               the letter frequencies in the file, and writes the 
*               results to a new file.
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "fileManip.hpp"

int main ()
{
    std::string fileName; // Stores user specified file name needed for input
    std::ifstream ifs;
    int* arrayAddress=NULL; // Pointer to array of int used for counting
    int arrayCount[26]={0};
    arrayAddress=arrayCount;
    // Prompt user for file name needed with program
    std::cout << "Please enter which file you would like to open: " << std::endl;
    std::cin >> fileName;
    // Open file for use with filestream object
    ifs.open(fileName.c_str(), std::ifstream::in);
    // Verify if file exists within local directory
    if (ifs)
    {
            count_letters(ifs,arrayAddress);
    }
    else
    {
        while (!ifs)
        {
            std::cout << "There was a problem opening the requested file, please re-enter the file name: " << std::endl;
            std::cin >> fileName;
            ifs.open(fileName.c_str());
        }
        count_letters(ifs,arrayAddress);
    } 
    return 0;
}