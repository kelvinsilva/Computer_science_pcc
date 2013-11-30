#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Hello!"));
    statusBar()->showMessage(QString("Game of Life by Kelvin Silva"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{

}

void MainWindow::on_pushButton_4_released(){

}

void MainWindow::lcdset(){

    iteration_count++;
    this->ui->lcdNumber->display(iteration_count);
}

void MainWindow::lcdclear(){
    iteration_count = 0;
    this->ui->lcdNumber->display(iteration_count);
}

void MainWindow::change_path_box(QString fnm){

    this->ui->lineEdit_5->setText(fnm);
}

void MainWindow::delay_set(int del){
    delay = del;
}

void MainWindow::set_x(int xx){ //Changing a global variable
    x_ =  xx;
}
void MainWindow::set_y(int yy){ //Changing a global variable
    y_ = yy;
}
void MainWindow::set_xx(int xxx){ //Changing a global variable
    x_x = xxx;
}
void MainWindow::set_yy(int yyy){ //Changing a global variable
    y_y = yyy;
}
