#ifndef STORAGESERVICE_H
#define STORAGESERVICE_H

#include <comline.h>
#include <QString>
#include <dirent.h>

namespace Ui {
    class StorageService;
}

class StorageService
{
    public:
        explicit StorageService(char* dirTexts);
        QString getTextFromFile(char* filename);
        int createTextFile(char* filename);
        int saveTextFile(char* filename, QString content);
        QString* getFilesList();
        int deleteTextFile(QString filename);

    private:
        ComLine* comLine;
        void test();
        char* doCommand(char* com);
        char* m_dirTexts; // Папка, где хранятся тексты
};

#endif // STORAGESERVICE_H
