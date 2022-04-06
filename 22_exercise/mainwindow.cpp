#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cmath"
#include "dialog.h"

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


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText(QString::number(ui->lineEdit->text().toInt()+increment));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(QString::number(ui->lineEdit->text().toInt()-increment));
}

constexpr uint64_t factorial(int n)
{
    uint64_t fac = 1;
    for (int i {2} ; i<=n ; ++i)
        fac *= i;
    return fac;
}

void MainWindow::on_pushButton_3_clicked()
{
    int num = ui->lineEdit->text().toInt();
    if (num>=0)
        ui->lineEdit_2->setText(QString::number(factorial(num)));
    else
        ui->lineEdit_2->setText("Cannot calculate");
}


void MainWindow::on_commandLinkButton_clicked()
{
    close();
}


void MainWindow::on_pushButton_4_clicked()
{
    Dialog d;
    d.setValue(increment);
    if (d.exec())
        increment = d.getValue();
}

