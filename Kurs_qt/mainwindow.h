#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
