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

    ss = new StorageService("texts");
    creatingFile = false;
    QString* list = ss->getFilesList();
    // Добавим все существующие текст. файлы в список
    for (int i = 0; i < 255; i++){
        if (list[i] == "")
            break;
        if (list[i] != "."
                && list[i] != "..")
        new QListWidgetItem(tr(list[i].toStdString().c_str()), ui->listTexts);
    }
    ui->listTexts->setCurrentRow(0);


}

// Отображает всплывающее сообщение в окошке с текстом msg
void MainWindow::alert(QString msg)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
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
    creatingFile = true;
}

// При изменении текущей строки в лист-виджете,
// выводим содержимое выделенного файла
void MainWindow::on_listTexts_currentRowChanged(int currentRow)
{
    QString fnQ = ui->listTexts->currentItem()->text();
    char* filename = (char*)fnQ.toStdString().c_str();
    QString text = ss->getTextFromFile(filename);
    ui->textEdit->setText(text);
}

void MainWindow::on_listTextFiles_currentRowChanged(int currentRow) {}

// Нажатие на Save
// если создается новый файл - создать и сохранить
// если нет - просто сохранить
void MainWindow::on_btnSave_clicked()
{
    // создать
    if (creatingFile){
        QString filename = ui->textFilename->text();
        if (filename != ""){
            int statusCreate = ss->createTextFile((char*)filename.toStdString().c_str());
            if (statusCreate == -1){
                // файл уже существует
                alert(QString("Файл с таким именем уже существует"));
                return;
            }
            on_btnCancel_clicked();
            new QListWidgetItem(tr(filename.toStdString().c_str()), ui->listTexts);
            ui->listTexts->setCurrentRow(ui->listTexts->count() - 1);
            ui->textEdit->setFocus();
        } else {
            alert(QString("Имя файла не может быть пустым"));
            return;
        }
        creatingFile = false;
    }
    // сохранить существующий
    else {
        QString fnQ = ui->listTexts->currentItem()->text();
        char* filename = (char*)fnQ.toStdString().c_str();
        QString text = ui->textEdit->toPlainText();
        ss->saveTextFile(filename, text);
    }
}

// Удалить папку с файлом
void MainWindow::on_btnDelete_clicked()
{
    QString fnQ = ui->listTexts->currentItem()->text();
    if (ss->deleteTextFile(fnQ) == 0){
        delete(ui->listTexts->currentItem());
    }
}
