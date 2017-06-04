#ifndef COMLINE
#define COMLINE
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <QString>

namespace Ui {
    class ComLine;
}

class ComLine
{
    public:
        explicit ComLine(char* com);

        QString doCommand(char* com);
        int close();

    private:
        std::FILE *inpFile;
};
#endif // COMLINE

