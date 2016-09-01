#include "Exercise1_MissingAlphabet.h"
#include <locale>
#include <string>
#include <fstream>
#include <iostream>

Exercise1_MissingAlphabet::Exercise1_MissingAlphabet()
{
    //ctor
}

Exercise1_MissingAlphabet::~Exercise1_MissingAlphabet()
{
    //dtor
}

//Converts the String to LowerCase
void Exercise1_MissingAlphabet::getLowerCase()
{
    std::locale loc;
    for(int i=0 ; i<SourceString.length() ; i++){
        if((SourceString[i] >='A') && SourceString[i] <='Z'){
            SourceString[i] = tolower(SourceString[i],loc);
        }
    }
}

//checks for the presence of all the Alphabets
int Exercise1_MissingAlphabet::CheckForAllCharacters(int PositionOfArray)
{
    for(int i=PositionOfArray ; i<NUMBEROFALPHABETS ; i++)
    {
        if(ReferenceArray[i]==false)
        {
            return PositionOfArray;
        }
    }
    return 0;
}

//Returns the string from the Console
void Exercise1_MissingAlphabet::ReadingFromConsole()
{
    std::cout << "Enter the String" << std::endl;

    std::cin.ignore();
    getline(std::cin,SourceString);
}

//Returns the string from the File that it reads
void Exercise1_MissingAlphabet::ReadingFromFile()
{
    std::cout << "Enter the File name to read From" << std::endl;
    std::string FileName;
    //Reading the file name
    std::cin >> FileName;

    std::ifstream StringFile (FileName, std::ios::in);
    getline (StringFile,SourceString);
    StringFile.close();
}

//Choice of Reading from File or from the Console
void Exercise1_MissingAlphabet::ReadInput()
{
    std::cout << "Enter\n 1--> Read From The Console \t 2--> Read From The File" << std::endl;
    int choice;
    std::cin >> choice;
    switch(choice)
    {
        case 1: ReadingFromConsole();
                break;
        case 2: ReadingFromFile();
                break;
    }
}

//Tracks the Alphabets that are Present in the String
bool Exercise1_MissingAlphabet::LoggingEachAlpa()
{
    std::locale loc;
    int SourceStringLenght = SourceString.length();
    int CheckisallPresent = 0;
    for(int index = 0; index < SourceStringLenght; index++)
    {
        if(isalpha(SourceString[index],loc))
        {
            int i =(int) SourceString[index] - 'a';
            ReferenceArray[i] = true;
            CheckisallPresent = CheckForAllCharacters(CheckisallPresent);
            if( index > NUMBEROFALPHABETS && CheckisallPresent)
            {
                return true;
            }
        }
    }
    return false;
}

//Returns the Missing Alphabet from the String
void Exercise1_MissingAlphabet::getMissingAlpha()
{
    for(int j=0 ; j< NUMBEROFALPHABETS ; j++)
    {
        if(ReferenceArray[j] == false)
        {
            char Ma = j+'a';
            MissingAlphabet = Ma;
            return;
        }
    }
}

//Execution of the Program
void Exercise1_MissingAlphabet::Execute()
{
    ReadInput();

    getLowerCase();

    CheckForAllAlphaPresent = LoggingEachAlpa();
    if(CheckForAllAlphaPresent)
    {
        MissingAlphabet = '1';
        Output();
    }
    else
    {
        getMissingAlpha();
        Output();
    }
}

//OutPut Of the Program
void Exercise1_MissingAlphabet::Output()
{
    if(MissingAlphabet == '1')
    {
        std::cout << "All the Alphabets are present" << std::endl;
        return ;
    }
    else
    {
        std::cout << MissingAlphabet << std::endl;
    }
}
