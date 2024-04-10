#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "classes.h"
#include "get_value.h"
#include "bolan.h"
#include "calories.h"

using namespace std;

QString textvalue;
string convertedString;
int strToInt;
int strToInt2;
int strToInt3;
int strToInt4;

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
    //bolan(strToInt);

    textvalue = ui->lineEdit_2->displayText();
    convertedString = textvalue.toStdString();
    strToInt2 = stoi(convertedString);
    cout << strToInt2 << "\n";

    textvalue = ui->lineEdit_3->displayText();
    convertedString = textvalue.toStdString();
    strToInt3 = stoi(convertedString);
    cout << strToInt3 << "\n";

    textvalue = ui->lineEdit_4->displayText();
    convertedString = textvalue.toStdString();
    strToInt4 = stoi(convertedString);
    cout << strToInt4 << "\n";

    inputData(strToInt, strToInt2, strToInt3, strToInt4);
}



