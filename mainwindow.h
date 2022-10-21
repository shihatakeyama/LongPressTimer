// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// mainwindow.h
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_1_pressed();
    void onpushButton_1_longpressed();
    void on_pushButton_2_pressed();
    void onpushButton_2_longpressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
