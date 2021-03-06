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
QString StorageService::doCommand(char* com)
{
    QString msg = QString("");
    FILE *inpFile;
    char buff[512];
    if (!(inpFile = popen(com, "r"))){
        msg = QString("Error");
    } else {
        while(fgets(buff, sizeof(buff), inpFile) != NULL) {
            msg = QString("%2 %1 ").arg(buff, msg);
        }
    }
    pclose(inpFile);

    return msg;
}

// Считывает все содержимое из файла filename и возвращает его
QString StorageService::getTextFromFile(char* filename)
{
    QString outp = "";
    std::ifstream file(QString("%1/%2")
                       .arg(m_dirTexts, filename)
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
//            if (entry->d_type == DT_DIR){
                list[iCur] = QString("%1").arg(entry->d_name);
                if (list[iCur] != "."
                        && list[iCur] != "..")
                iCur++;
//            }
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

char* StorageService::commit(QString commitName, QString filename, bool writeToFile, bool checkout)
{
    QString fileDir = QString("%1/%2")
            .arg(m_dirTexts, filename);
    QString commitsFN = QString("%1/%2/%3")
            .arg(m_dirTexts, filename, "commits.dat");
    QString cmd = "";
    // git init
    cmd = "cd " + fileDir + " && git init";
    doCommand((char*)cmd.toStdString().c_str());

    if (checkout){
        cmd = "cd " + fileDir + " && git reset HEAD --hard";
        doCommand((char*)cmd.toStdString().c_str());
        cmd = "cd " + fileDir + " && git clean -fd";
        cmd = "cd " + fileDir + " && git checkout master";
        doCommand((char*)cmd.toStdString().c_str());
    }

    // Коммит
    cmd = "cd " + fileDir + " && git add " + filename;
    doCommand((char*)cmd.toStdString().c_str());
    cmd = "cd " + fileDir + " && git commit -m '" + commitName + "'";
    QString result = doCommand((char*)cmd.toStdString().c_str());
    // Вырезаем hash коммита
    QString resultHash = result.mid(result.indexOf("]")-7, 7) ;

    // Записываем коммит в файл коммитов
    if (writeToFile){
        QString commitsFNShort = QString("%1/%2").arg(filename, "/commits.dat");
        QString oldCommits = getTextFromFile((char*)commitsFNShort.toStdString().c_str());
        QFile file(commitsFN);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << oldCommits  << commitName << endl << resultHash << endl;
        }
        file.close();
    }
}

int StorageService::checkout(QString commitName, QString filename)
{
    commit("-" + commitName, filename, false, true);

    QString fileDir = QString("%1/%2")
            .arg(m_dirTexts, filename);
    QString cmd = "";

    // Checkout cmd
    cmd = "cd " + fileDir + " && git checkout master";
    doCommand((char*)cmd.toStdString().c_str());
    commit("-" + commitName, filename, false, true);
    cmd = "cd " + fileDir + " && git checkout " + commitName;
    doCommand((char*)cmd.toStdString().c_str());
}

int StorageService::merge(QString commitName, QString filename)
{
    commit("-" + commitName, filename, false, true);

    QString fileDir = QString("%1/%2")
            .arg(m_dirTexts, filename);
    QString cmd = "";

    // Checkout cmd
    cmd = "cd " + fileDir + " && git checkout master";
    doCommand((char*)cmd.toStdString().c_str());
    commit("-" + commitName, filename, false, true);
    cmd = "cd " + fileDir + " && git merge " + commitName;
    doCommand((char*)cmd.toStdString().c_str());
}

QString* StorageService::getCommitsList(char* filename)
{
    QString* outp = new QString[256];
    outp[0] = QString("");
    int curLine = 0;
    std::ifstream file(QString("%1/%2/%3")
                       .arg(m_dirTexts, filename, "commits.dat")
                       .toStdString().c_str());
    std::string str;
    while (std::getline(file, str))
    {
        outp[curLine] = QString::fromStdString(str) + QString("\n");
        curLine++;
    }
    file.close();
    outp[curLine] = QString("");
    return outp;
}
