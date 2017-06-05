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
        char* commit(QString commitName, QString filename, bool writeToFile, bool checkout);
        int checkout(QString commitName, QString filename);
        int merge(QString commitName, QString filename);
        QString* getCommitsList(char* filename);

    private:
        ComLine* comLine;
        QString doCommand(char* com);
        void test();
        char* m_dirTexts; // Папка, где хранятся тексты
};

#endif // STORAGESERVICE_H
