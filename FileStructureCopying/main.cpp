#include "CopyFileStructure.h"
#include <iostream>
#include <thread>
#define MAX_NUMBER_OF_THREADS 10

using namespace std;

void GettingStarted(string SourceFile , string DestinationFile , string FileToStoreDetails)
{
    CopyFileStructure *Obj = new CopyFileStructure(SourceFile, DestinationFile ,FileToStoreDetails);
}

int main()
{
    std::vector<std::thread> threads;
    int ThreadCheck;
    for(int i = 0 ; i<MAX_NUMBER_OF_THREADS ; i++)
    {
        cout << "Enter the Source file" << endl;
        string SourceFile;
        cin >> SourceFile;

        cout << "Enter the Destination Path" << endl;
        string DestinationFile;
        cin >> DestinationFile;

        cout << "Enter the File To Which File Details are To be Written" << endl;
        string FileToStoreDetails;
        cin >> FileToStoreDetails;

        cout << "Thread Created ---------- Thread Number :" << i <<endl;
        threads.push_back(std::thread(GettingStarted, SourceFile , DestinationFile , FileToStoreDetails));
        threads[i].detach();

    }
    return 0;
}
