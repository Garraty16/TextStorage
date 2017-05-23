#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <storageservice.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listTextFiles_currentRowChanged(int currentRow);
    void init();
    void alert(QString msg);

    void on_btnCancel_clicked();

    void on_btnAdd_clicked();

    void on_listTexts_currentRowChanged(int currentRow);

    void on_btnSave_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
    StorageService *ss;
    bool creatingFile;
};

#endif // MAINWINDOW_H
