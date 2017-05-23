#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <stdio.h>

void executeCom(char* com)
{
    QMessageBox msgBox;

    QString msg;
    FILE *inpFile;
    char buff[512];
    if (!(inpFile = popen(com, "r"))){
        msg = QString("Error");
    } else {
        while(fgets(buff, sizeof(buff), inpFile) != NULL) {
            msg = QString("%1").arg(buff);
            msgBox.setText(msg);
            msgBox.exec();
        }

    }
    pclose(inpFile);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // receive data from C
//   executeCom("git diff");

    return a.exec();
}
