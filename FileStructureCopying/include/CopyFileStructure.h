#ifndef COPYFILESTRUCTURE_H
#define COPYFILESTRUCTURE_H

#include <string>
#include <windows.h>
#include <dir.h>
#include <dirent.h>
#include <vector>

class CopyFileStructure
{
    public:
        CopyFileStructure();
        CopyFileStructure(std::string Source , std::string Destination , std::string FileNameTOStore);
        void ListController();
        bool CreateDir(std::string DirName);
        void ListingFilesInFile();//bool isDirectory, std::string PathToStore , std::string FileName);
        bool GoingInsideTheDirectory(char *CurrentWorkingDirectory,std::string TempDirectorHolder);
        virtual ~CopyFileStructure();

    protected:

    private:
        std::string SourceFile;//Stores the Source File Path
        std::string DestinationFile;//Stores the Destination File Path
        std::string FileToStoreDetails;//Stores Path the File to which List Of Files to be Written
        std::vector<std::string> ListOfFiles;//Contains the List of Files

        //Aides for searching the file in the a Directory
        DIR *CurrentDirectory;
        struct dirent *Dirnt;

        //Stores the Files Details
        WIN32_FIND_DATA FileDetails;
        LARGE_INTEGER FileSize;
        char PathOfTheFile[MAX_PATH];

};

#endif // COPYFILESTRUCTURE_H
