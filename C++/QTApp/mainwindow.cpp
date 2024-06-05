#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "classes.h"
#include "get_value.h"
#include "bolan.h"
#include "calories.h"
#include <QFile>
#include <QTextStream>

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
int huskostnad;
double ranta;
int antal_ar;
string tickers;

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
    //system("python3 /home/tomcarl/QT_app/QTApp/QTApp/bolan.py");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_5_clicked()
{
    textvalue = ui->lineEdit_16->displayText();
    convertedString = textvalue.toStdString();
    gramsOfFood = stoi(convertedString);
    //bolan(gramsOfFood);

    textvalue = ui->lineEdit_17->displayText();
    convertedString = textvalue.toStdString();
    carbsPer100g = stoi(convertedString);

    textvalue = ui->lineEdit_18->displayText();
    convertedString = textvalue.toStdString();
    proteinPer100g = stoi(convertedString);

    textvalue = ui->lineEdit_19->displayText();
    convertedString = textvalue.toStdString();
    fatPer100g = stoi(convertedString);

    inputData(gramsOfFood, carbsPer100g, proteinPer100g, fatPer100g);
    cout << gramsOfFatNeededToStayInKetosis << "\n";
    QgramsOfFatNeededToStayInKetosis = QString::number(gramsOfFatNeededToStayInKetosis);
    ui->lineEdit_12->setText(QgramsOfFatNeededToStayInKetosis);

    QcaloriesOfMeal = QString::number(caloriesOfMeal);
    ui->lineEdit_13->setText(QcaloriesOfMeal);
}


void MainWindow::on_pushButton_7_clicked()
{
    textvalue = ui->lineEdit_9->displayText();
    convertedString = textvalue.toStdString();
    huskostnad = stoi(convertedString);

    textvalue = ui->lineEdit_10->displayText();
    convertedString = textvalue.toStdString();
    ranta = stof(convertedString);

    textvalue = ui->lineEdit_11->displayText();
    convertedString = textvalue.toStdString();
    antal_ar = stoi(convertedString);
    
    bolan(huskostnad, ranta, antal_ar);

    QFile file("output.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString content = stream.readAll();
    file.close();
    ui->textEditConsole->setPlainText(content);
}

void MainWindow::on_pushButton_8_clicked()
{
    //textvalue = ui->textEditConsole_2->toPlainText();
    //convertedString = textvalue.toStdString();
    //tickers = stoi(convertedString);

    system("python3 ../stock_analysis.py");
}

