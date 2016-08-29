#include "CopyFileStructure.h"

#include <fstream>
#include <iostream>
#include <windows.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>

CopyFileStructure::CopyFileStructure()
{
    //ctor
}

//constructor which stores the necessary information
CopyFileStructure::CopyFileStructure(std::string Source, std::string Destination , std::string FileNameTOStore)
{
    SourceFile = Source;
    DestinationFile = Destination;
    FileToStoreDetails = FileNameTOStore;

    ListController();
}

// Prep for Listing all the files in a directory
void CopyFileStructure::ListController()
{
    SourceFile.copy(PathOfTheFile,MAX_PATH,0);

    int LengthOfString = SourceFile.length();

    //The Length should not more than 260
    if (LengthOfString > MAX_PATH)
    {
        std::cout << "The Length Of the Path is very long" << std::endl;
        exit(0);
    }

    //Calling  the Recursive Function for going in each directory and listing the files
    GoingInsideTheDirectory(PathOfTheFile,DestinationFile);
    ListingFilesInFile();

}

//Listing all the Files in to a file in a sorted Order using Vector
void CopyFileStructure::ListingFilesInFile()
{
    std::sort(ListOfFiles.begin(),ListOfFiles.end());
    std::ofstream DestinationPtr(FileToStoreDetails,std::ofstream::out | std::ofstream::app);
    for (std::vector<std::string>::iterator it = ListOfFiles.begin() ; it !=ListOfFiles.end() ; it++)
    {
        DestinationPtr << *it << std::endl;
    }
    DestinationPtr.flush();
    DestinationPtr.close();
}

//Recursive Function for going in each directory and listing the files
bool CopyFileStructure::GoingInsideTheDirectory(char * CurrentWorkingDirectory , std::string TempDirectorHolder)
{
    //Adding * for searching the Directory
    strncat(CurrentWorkingDirectory,"\\*",strlen(CurrentWorkingDirectory)-1);

    HANDLE FileFinder = INVALID_HANDLE_VALUE;
    std::string TempDest = TempDirectorHolder;

    FileFinder = FindFirstFile(CurrentWorkingDirectory,&FileDetails);
    FindNextFile(FileFinder, &FileDetails);
    FindNextFile(FileFinder, &FileDetails);

    do
    {
        //Checking For Directory
        if((FileDetails.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY))
        {
            char temp[260];
            strcpy(temp,CurrentWorkingDirectory);
            temp[strlen(temp)-1] = '\0';//Removing the * at the End of the string
            strncat(temp,FileDetails.cFileName,strlen(temp)-1);
            TempDest = TempDest + "\\" + FileDetails.cFileName;

            ListOfFiles.insert(ListOfFiles.end(),TempDest + "   <DIR>");

            CreateDir(TempDest);

            //Calling Recursively for Getting into the Directory
            GoingInsideTheDirectory(temp,TempDest);
        }
        //Listing the Files
        else
        {
            std::string TempSource = CurrentWorkingDirectory;
            TempSource.pop_back();//Removing the * at the End of the String

            TempSource = TempSource  +  FileDetails.cFileName;
            std::string Desti = TempDest;
            Desti = Desti + "\\" + FileDetails.cFileName;

            //Copying the File to the Destination
            CopyFile(TempSource.c_str(),Desti.c_str(),false);

            //Getting the File Details
            FileSize.LowPart = FileDetails.nFileSizeLow;
            FileSize.HighPart = FileDetails.nFileSizeHigh;


            std::stringstream s;
            s << Desti << "\t" << FileSize.QuadPart;

            //Adding the File to the Vector
            ListOfFiles.insert(ListOfFiles.end(),s.str());

        }
    }while (FindNextFile(FileFinder, &FileDetails) != 0);//Finding the Next File in the Directory
}


//Creating the Directory in the Destination
bool CopyFileStructure::CreateDir(std::string DirName)
{
    if(!(CreateDirectory(DirName.c_str(),NULL)))
    {
           return false;
    }
    return true;
}

CopyFileStructure::~CopyFileStructure()
{
    //dtor
}
