/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: This file contains the necessary functions which count
*               and output data to user specific files.
*********************************************************************/
#include <iostream> 
#include <fstream>
#include <string>
#include "fileManip.hpp"

/********************************************************************* 
** Description: void count_letters(std::ifstream &ifs, int* arrayCount)
*               No return. Accepts the address of file stream object 
*               and pointer to int array as arguments. File stream 
*               object is used to manipulate text file while array
*               pointer is used to store count values of individual
*               letter in text file.
*********************************************************************/
void count_letters(std::ifstream &ifs, int* arrayCount)
{
    char letterIn, finalOut;
    int stringLength;
    std::string singleLine;
    // Terminate loop only when end of file is reached
    while (!ifs.eof())
    {
        std::getline(ifs, singleLine, '\n'); // Move entire row of file text into file stream object, delimit when 'newline' character reached
        stringLength=singleLine.length();
        // Evaluate each letter in single file string object and increment specific counter in array
        for (int i=0; i<stringLength; i++)
        {
            if (isalnum(singleLine[i])) // Eliminiate punctuation and spaces from evaluation
            {
                letterIn=singleLine[i];
                finalOut=tolower(letterIn); // Ensure every letter is converted to lowercase
                arrayCount[finalOut-'a']++;
            }                       
        }
        std::ofstream ofs;
        output_letters(ofs, arrayCount);
        // Make sure each counter in the array is reset to 0
        for (int i=0; i<26; i++)
        {
            arrayCount[i]=0;
        }
    }
    ifs.close();
}

/********************************************************************* 
** Description: void output_letters(std::ofstream &ofs, int* arrayCount)
*               No return. Accepts filestream object and pointer to
*               array as arguments. File stream object will be used to
*               output formatted data to file. Pointer to the counter
*               array is used to retrieve data used in output.
*********************************************************************/
void output_letters(std::ofstream &ofs, int* arrayCount)
{
    char letter;
    int static count=1;
    std::string userFileName;
    //Prompt user to name frequency count of inidvidual paragraph
    std::cout << "Please enter a name for the #" << count++ << " frequency counter file" << std::endl;
    std::cin >> userFileName;
    ofs.open(userFileName.c_str()); 
    // Output properly formatted frequency count to user specified file
    for (int i=0; i<=('z'-'a'); i++) 
    {
        letter='a'+i;
        ofs << letter << ": " << arrayCount[i] << std::endl;
    }
    ofs.close();
}