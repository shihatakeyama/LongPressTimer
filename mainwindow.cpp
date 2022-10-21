// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// mainwindow.cpp
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

void ECF_startLongPressTimer(QWidget *Btn ,int32_t Milisec ,QObject *SlotObj ,const char *SlotName);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// ボタン1押された
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void MainWindow::on_pushButton_1_pressed()
{
    ECF_startLongPressTimer(ui->pushButton_1 ,2000 ,this ,SLOT(onpushButton_1_longpressed()));

    qDebug() << "MainWindow::on_pushButton_1_pressed()";
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// ボタン1長押された
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void MainWindow::onpushButton_1_longpressed()
{
    qDebug() << "MainWindow::onpushButton_1_longpressed()";
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// ボタン2押された
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void MainWindow::on_pushButton_2_pressed()
{
    ECF_startLongPressTimer(ui->pushButton_2 ,2000 ,this ,SLOT(onpushButton_2_longpressed()));

    qDebug() << "MainWindow::on_pushButton_2_pressed()";
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// ボタン2長押された
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void MainWindow::onpushButton_2_longpressed()
{
    qDebug() << "MainWindow::onpushButton_2_longpressed()";
}


