#include <iostream>
#include <string>
#include <fstream>
#include <locale>

using namespace std;

const int NUMBEROFALPHABETS=26;

//Converts the String to LowerCase
string getlowercase(string Source)
{
    locale loc;
    for(int i=0 ; i<Source.length() ; i++){
        if((Source[i] >='A') && Source[i] <='Z'){
            Source[i] = tolower(Source[i],loc);
        }
    }
    return Source;
}

//Returns the string from the Console
string ReadingFromConsole()
{
    string ReadString;

    cout << "Enter the String" << endl;

    cin.ignore();
    getline(cin,ReadString);

    return ReadString;
}


//Returns the string from the File that it reads
string ReadingFromFile()
{
    string ReadString;

    cout << "Enter the File name to read From" << endl;
    string FileName;
    //Reading the file name
    cin >> FileName;

    ifstream StringFile (FileName, ios::in);
    getline (StringFile,ReadString);
    StringFile.close();



    return ReadString;
}


//Choice of Reading from File or from the Console
string MakingTheChoice()
{
    cout << "Enter\n 1--> Read From The Console \t 2--> Read From The File" << endl;
    int choice;
    cin >> choice;
    string ReadString;
    switch(choice)
    {
        case 1: ReadString = ReadingFromConsole();
                break;
        case 2: ReadString = ReadingFromFile();
                break;
    }
    return ReadString;
}

//Tracks the Alphabets that are Present in the String
void LoggingEachAlpa(string Source, bool *ReferenceArray)
{
    locale loc;
    int SourceStringLenght = Source.length();
    for(int index = 0; index < SourceStringLenght; index++)
    {
        if(isalpha(Source[index],loc))
        {
            int i =(int) Source[index] - 'a';
            ReferenceArray[i] = true;
        }
    }
}

//Returns the Missing Alphabet from the String
char getMissingAlpha(bool *ReferenceArray)
{
    for(int j=0 ; j< NUMBEROFALPHABETS ; j++)
    {
        if(ReferenceArray[j] == false)
        {
            char MissingAlpha = j+'a';
            return MissingAlpha;
        }
    }
}

int main()
{
    //To Store the String for Processing
    string SourceString;

    SourceString = MakingTheChoice();

    //To Have the Reference of the Alphabets that are Present in the String
    bool ReferenceArray[NUMBEROFALPHABETS] = {false};

    SourceString = getlowercase(SourceString);

    LoggingEachAlpa(SourceString,ReferenceArray);

    char MissingAlpha = getMissingAlpha(ReferenceArray);

    cout << MissingAlpha;

    return 0;
}
