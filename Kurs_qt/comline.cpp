#include <QString>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <comline.h>

ComLine::ComLine(char* com)
{
    QString msg = QString("");
    char buff[512];
    if (!(inpFile = popen(com, "w"))){
//        msg = QString("Error");
    } else {

    }
}

// Выполняет команду com в командной строке
// и возвращает результат выполнения
QString ComLine::doCommand(char* com)
{
    QString msg = QString("");
    char buff[512];
    fprintf(inpFile, com);
//    while(fgets(buff, sizeof(buff), inpFile) != NULL) {
//        msg += QString("%1 ").arg(buff);
//    }

    return msg;
}

int ComLine::close()
{
    pclose(inpFile);
}
