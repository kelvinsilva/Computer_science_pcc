#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rule.h"
#include "global_vars.h"

namespace Ui {
class MainWindow;
class MyPanelOpenGL;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_released();
    void on_pushButton_4_released();

public slots:
    void lcdset();
    void lcdclear();
    void change_path_box(QString);
    void delay_set(int del); //Changing a global variable

    void set_x(int x); //Changing a global variable
    void set_y(int y); //Changing a global variable
    void set_xx(int x1); //Changing a global variable
    void set_yy(int y1); //Changing a global variable



protected:


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
