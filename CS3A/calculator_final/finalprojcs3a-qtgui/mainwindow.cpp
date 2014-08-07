#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"



MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Kelvin\'s Calculator"));
    statusBar()->showMessage(QString("Kelvin\'s Calculator by Kelvin Silva CS3A"));
    current_expression = "";

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    current_expression.push_back('9');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_2_clicked()
{
    current_expression.push_back('8');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_3_clicked()
{
    current_expression.push_back('7');
    ui->lineEdit->setText(current_expression.c_str());
}



void MainWindow::on_pushButton_4_clicked()
{
    current_expression.push_back('6');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_5_clicked()
{
    current_expression.push_back('5');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_6_clicked()
{
    current_expression.push_back('4');
    ui->lineEdit->setText(current_expression.c_str());
}


void MainWindow::on_pushButton_7_clicked()
{
    current_expression.push_back('3');
    ui->lineEdit->setText(current_expression.c_str());
}



void MainWindow::on_pushButton_8_clicked()
{
    current_expression.push_back('2');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_9_clicked()
{
    current_expression.push_back('1');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_17_clicked()
{
    current_expression.push_back('0');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_10_clicked()
{
    current_expression.push_back('+');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_11_clicked()
{
    current_expression.push_back('-');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_12_clicked()
{
    current_expression.push_back('*');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_13_clicked()
{
    current_expression.push_back('/');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_14_clicked()
{
    current_expression = ui->lineEdit->text().toStdString();
    current_expression = clean(current_expression);

    if ( look_for_error(current_expression) ){
        QMessageBox ms;
        ms.setText("Syntax Error. Reenter the expression");
        ms.exec();
        current_expression = "";
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        main_parser.clear_parser();
    }else{


        main_parser.set_string(current_expression);
        main_parser.parse_algebraic();

        ui->lineEdit_3->setText(main_parser.get_rpn_str().c_str());
        stringstream ss;
        mixedNumber mx;
        mx = output_queue_rpn_calculation(main_parser.get_output_queue());
        ss << mx;

            ui->lineEdit_2->setText(ss.str().c_str());
            main_parser.clear_parser();
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    current_expression.push_back(' ');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_16_clicked()
{
    current_expression = "";
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    main_parser.clear_parser();
}

void MainWindow::on_pushButton_18_clicked()
{
    current_expression.push_back('(');
    ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_19_clicked()
{
   current_expression.push_back(')');
   ui->lineEdit->setText(current_expression.c_str());
}

void MainWindow::on_pushButton_20_clicked()
{
    if (current_expression.size() > 0)
        current_expression.erase(current_expression.end()-1);

    ui->lineEdit->setText(current_expression.c_str());
}
