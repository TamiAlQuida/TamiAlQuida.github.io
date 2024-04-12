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
int gramsOfFood;
int carbsPer100g;
int proteinPer100g;
int fatPer100g;
string dataToPrint;
QString QgramsOfFatNeededToStayInKetosis;
QString QcaloriesOfMeal;

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
    textvalue = ui->lineEdit->displayText();
    convertedString = textvalue.toStdString();
    gramsOfFood = stoi(convertedString);
    //bolan(gramsOfFood);

    textvalue = ui->lineEdit_2->displayText();
    convertedString = textvalue.toStdString();
    carbsPer100g = stoi(convertedString);

    textvalue = ui->lineEdit_3->displayText();
    convertedString = textvalue.toStdString();
    proteinPer100g = stoi(convertedString);

    textvalue = ui->lineEdit_4->displayText();
    convertedString = textvalue.toStdString();
    fatPer100g = stoi(convertedString);

    inputData(gramsOfFood, carbsPer100g, proteinPer100g, fatPer100g);
    cout << gramsOfFatNeededToStayInKetosis << "\n";
    QgramsOfFatNeededToStayInKetosis = QString::number(gramsOfFatNeededToStayInKetosis);
    ui->lineEdit_5->setText(QgramsOfFatNeededToStayInKetosis);

    QcaloriesOfMeal = QString::number(caloriesOfMeal);
    ui->lineEdit_6->setText(QcaloriesOfMeal);
}

