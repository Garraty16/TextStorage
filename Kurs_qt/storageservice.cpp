#include <storageservice.h>
#include <QString>
#include <stdio.h>
#include <QFile>
#include <QDir>
#include <QTextStream>

StorageService::StorageService(char* dirTexts)
{
    m_dirTexts = dirTexts;
}

// Выполняет команду com в командной строке
// и возвращает результат выполнения
char* StorageService::doCommand(char* com)
{
    QString msg = QString("");
    FILE *inpFile;
    char buff[512];
    if (!(inpFile = popen(com, "r"))){
        msg = QString("Error");
    } else {
        while(fgets(buff, sizeof(buff), inpFile) != NULL) {
            msg = QString("%1 ").arg(buff);
        }

    }
    pclose(inpFile);
}

// Считывает все содержимое из файла filename и возвращает его
QString StorageService::getTextFromFile(char* filename)
{
    QString outp = "";
    std::ifstream file(QString("%1/%2/%3")
                       .arg(m_dirTexts, filename, filename)
                       .toStdString().c_str());
        std::string str;
        while (std::getline(file, str))
        {
            outp += QString::fromStdString(str) + QString("\n");
        }
    return outp;
}

// Получить список существующих текстовых файлов
QString* StorageService::getFilesList()
{
    QString* list = new QString[255];
    int iCur = 0;
    char* PATH = m_dirTexts;
        DIR *dir = opendir(PATH);
        struct dirent *entry = readdir(dir);
        while (entry != NULL)
        {
            if (entry->d_type == DT_DIR){
                list[iCur] = QString("%1").arg(entry->d_name);
                if (list[iCur] != "."
                        && list[iCur] != "..")
                iCur++;
            }
            entry = readdir(dir);
        }
        closedir(dir);

        return list;
}

// Создать папку для нового текстового файла
// и сам файл внутри нее
int StorageService::createTextFile(char* filename)
{
    QString dirname = QString("%1/%2")
            .arg(m_dirTexts, filename);

    // папка уже существует
    if (QDir(dirname).exists()) {
       return -1;
    } else {
        QDir().mkdir(dirname);
    }
    return 0;
}

// Сохранить изменения в существующий текстовый файл
int StorageService::saveTextFile(char* filename, QString content)
{
    QFile file(QString("%1/%2/%3")
               .arg(m_dirTexts, filename, filename));
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << content << endl;
    }
    file.close();
    return 0;
}

// Удалить папку и файл
int StorageService::deleteTextFile(QString filename)
{
    QString dirname = QString("%1/%2")
            .arg(m_dirTexts, filename);
    // папка существует
    if (QDir(dirname).exists()) {
        QDir(dirname).removeRecursively();
    } else {
        return -1;
    }
    return 0;
}
