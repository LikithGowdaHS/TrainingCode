#include "Exercise4_CopyFileStructure.h"
#include "../../FileStructureCopying/include/CopyFileStructure.h"

#include <iostream>
#include <thread>

#define MAX_NUMBER_OF_THREADS 10

Exercise4_CopyFileStructure::Exercise4_CopyFileStructure()
{
    //ctor
}

Exercise4_CopyFileStructure::~Exercise4_CopyFileStructure()
{
    //dtor
}

//Reads the Input
void Exercise4_CopyFileStructure::ReadInput()
{
    std::cout << "Enter the Source file" << std::endl;
    std::cin >> SourceFile;//Directory to copy from

    std::cout << "Enter the Destination Path" << std::endl;
    std::cin >> DestinationFile;//Directory to copy to

    std::cout << "Enter the File To Which File Details are To be Written" << std::endl;
    std::cin >> FiletoStoreDetails;//File to store the list of files
}

//Starts the Process
void Exercise4_CopyFileStructure::Execute()
{
    for(int i = 0 ; i < MAX_NUMBER_OF_THREADS ; i++)
   {
        ReadInput();

        std::cout << "Enter n\\N to Discontinue " << std::endl;
        char ch;
        std::cin >> ch;

        //Creation of thread and starting of execution
        std::cout << "Thread Created ---------- Thread Number :" << i << std::endl;
        Threads.push_back(std::thread(Exercise4_CopyFileStructure::GettingStarted, this));
        Threads[i].detach();//Execution should not depend on the other threads

        //Ending the Process
        if((ch == 'N') || (ch == 'n'))
        {
            Output();
            return;
        }
    }

}

//Function that is pushed in to the thread
void Exercise4_CopyFileStructure:: GettingStarted()
{
    CopyFileStructure *Obj = new CopyFileStructure(this->SourceFile, this->DestinationFile ,this->FiletoStoreDetails);
}

void Exercise4_CopyFileStructure::Output()
{
    std::cout << "The Copy is Completed" << std::endl;
}
