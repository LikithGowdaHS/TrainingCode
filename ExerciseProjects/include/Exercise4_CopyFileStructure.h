#ifndef EXERCISE4_COPYFILESTRUCTURE_H
#define EXERCISE4_COPYFILESTRUCTURE_H

#include <string>
#include <thread>
#include <vector>

#include <Exercise0Base.h>
#include "../../FileStructureCopying/include/CopyFileStructure.h"


class Exercise4_CopyFileStructure : public Exercise0Base
{
    public:
        Exercise4_CopyFileStructure();
        void ReadInput();
        void Execute();
        void Output();
        void GettingStarted();
        virtual ~Exercise4_CopyFileStructure();

    protected:

    private:
        std::vector<std::thread> Threads;
        std::string SourceFile;
        std::string DestinationFile;
        std::string FiletoStoreDetails;
};

#endif // EXERCISE4_COPYFILESTRUCTURE_H
