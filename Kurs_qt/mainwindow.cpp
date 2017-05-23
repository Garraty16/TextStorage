#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QString"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Инициализация
void MainWindow::init()
{
    // Будем показывать только при нажатии на кнопку "Add"
    ui->labFilename->hide();
    ui->textFilename->hide();
    ui->btnCancel->hide();
}

// Отображает всплывающее сообщение в окошке с текстом msg
void MainWindow::alert(QString msg)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

void MainWindow::on_listTextFiles_currentRowChanged(int currentRow)
{

}

// Нажатие на Cancel
void MainWindow::on_btnCancel_clicked()
{
    ui->labFilename->hide();
    ui->textFilename->hide();
    ui->btnCancel->hide();
}

// Нажатие на Add
void MainWindow::on_btnAdd_clicked()
{
    ui->labFilename->show();
    ui->textFilename->show();
    ui->btnCancel->show();
}
