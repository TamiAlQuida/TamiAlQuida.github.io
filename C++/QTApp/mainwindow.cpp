#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "classes.h"
#include "get_value.h"
#include "bolan.h"

using namespace std;

QString textvalue;
string convertedString;
int strToInt;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_helloMF_clicked() // mainwindow.h from class MainWindow, from private slot on_helloMf...
{
    addingToAList(); // from classes.h that I created
}


void MainWindow::on_pushButton_clicked() // mainwindow.h from class MainWindow, from private slot on_push...
{
    system("python3 /home/tomcarl/QT_app/QTApp/QTApp/bolan.py");
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    // textvalue2 = ui->lineEdit->displayText();
    //data1 = textvalue.toStdString();
}


void MainWindow::on_pushButton_5_clicked()
{
    cout << "button clicked" << "\n";
    textvalue = ui->lineEdit->displayText();
    convertedString = textvalue.toStdString();
    strToInt = stoi(convertedString);
    cout << strToInt << "\n";
    bolan(strToInt);
}



