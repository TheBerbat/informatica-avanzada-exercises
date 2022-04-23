#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>

#include "exercisea.h"
#include "exerciseb.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QEventLoop>

#include <QtGui>
#include <QPrinter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QPrintPreviewDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushExecA, &QPushButton::clicked,
                     this, &MainWindow::execExerciseA);

    QObject::connect(ui->pushExecB, &QPushButton::clicked,
                     this, &MainWindow::execExerciseB);

    QObject::connect(ui->pushConnect, &QPushButton::clicked,
                     this, &MainWindow::connectDB);

    QObject::connect(ui->lineFilenameDB, &QLineEdit::textChanged,
                     this, &MainWindow::filenameUpdated);

    QObject::connect(ui->push_selectDDBB, &QPushButton::clicked,
                     this, &MainWindow::selectDBWindow);

    filenameUpdated({});
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::get_actual_filenameDB() const
{
    return ui->lineFilenameDB->text();
}

void MainWindow::set_actual_filenameDB(const QString& filenameDB)
{
    ui->lineFilenameDB->setText(filenameDB);
}

void MainWindow::selectDBWindow()
{
    QFileDialog fd(this, tr("Open XML File 1"), get_actual_filenameDB(), tr("SQlite Files (*.sqlite)"));
    fd.setFileMode(QFileDialog::ExistingFile);
    if(fd.exec())
    {
        QStringList fileNames = fd.selectedFiles();
        set_actual_filenameDB(fileNames[0]);
    }
}

bool MainWindow::isValidFileName(const QString &filename)
{
    QFileInfo file(filename);
    return file.exists() && file.completeSuffix() == "sqlite";
}

void MainWindow::filenameUpdated(const QString &new_filename)
{
    if(isValidFileName(new_filename))
    {
        ui->lineFilenameDB->setStyleSheet("border: 1px solid black");
        ui->pushConnect->setEnabled(true);
    }
    else
    {
        ui->lineFilenameDB->setStyleSheet("border: 1px solid red");
        ui->pushConnect->setEnabled(false);
    }
    ui->pushExecA->setEnabled(false);
    ui->pushExecB->setEnabled(false);
}

void MainWindow::connectDB()
{
    // Check if database file is selected correctly
    if ( !isValidFileName(get_actual_filenameDB()) ) {
        qInfo() << "Database cannot be open";
        return;
    }

    // Delete last database if was already created before
    if ( QSqlDatabase::contains("current_db") )
        QSqlDatabase::removeDatabase("current_db");

    // Create and configure connection
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE", "current_db");
    m_db.setDatabaseName(get_actual_filenameDB());

    if (!m_db.isValid())
        return;

    ui->pushConnect->setEnabled(false);
    ui->pushExecA->setEnabled(true);
    ui->pushExecB->setEnabled(true);
}


void MainWindow::execExerciseA()
{
    QSqlQuery q1("SELECT sum(OrderDetail.Quantity*OrderDetail.UnitPrice*(1-OrderDetail.Discount))as 'TotalPrice' FROM OrderDetail, Product WHERE Product.CategoryId == 1 AND OrderDetail.ProductId == Product.Id",
                 QSqlDatabase::database("current_db"));

    double total {};
    if (q1.next()) total = q1.value(0).toDouble();

    ExerciseA e(this);
    e.setResponse(total);
    e.exec();
}


void MainWindow::execExerciseB()
{
    QSqlQuery q2("SELECT 'Order'.CustomerId, Customer.CompanyName, Customer.ContactName, Customer.ContactTitle, count('Order'.Id) as cuenta FROM 'Order', Customer where Customer.Id='Order'.CustomerId group by 'Order'.CustomerId having cuenta>1 order by cuenta DESC",
                 QSqlDatabase::database("current_db"));

    ExerciseB e(this);
    e.insertData("Orders - Company Name, Contact Name (Title)");
    while(q2.next())
    {
        QString companyName = q2.value(1).toString();
        QString contactName = q2.value(2).toString();
        QString contactTitle = q2.value(3).toString();
        uint count = q2.value(4).toUInt();

        QString a("%1 - %2, %3 (%4)");
        a = a.arg(QString::number(count), companyName, contactName, contactTitle);

        e.insertData(a);
    }
    e.exec();
}


