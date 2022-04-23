#include "exerciseb.h"
#include "ui_exerciseb.h"

#include <QPrinter>
#include <QStringListModel>
#include <QPainter>
#include <QFileDialog>

ExerciseB::ExerciseB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExerciseB)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked,
                     this, &ExerciseB::print);
}

ExerciseB::~ExerciseB()
{
    delete ui;
}

void ExerciseB::insertData(QString data)
{
    stringList.append(data);

    QStringListModel* listModel = new QStringListModel(stringList, NULL);

    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setModel(listModel);
}

void ExerciseB::print()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr(" export PDF file "), {}, "*.pdf");
    if (!fileName.isEmpty())
    {
        //  If the file suffix is empty, it is used by default .pdf
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }
        QPrinter printer;
        //  Specify the output format as pdf
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        QPainter painter;
        if (! painter.begin(&printer)) { // failed to open file
            qWarning("failed to open file, is it writable?");
        }

        painter.drawText(30, 40, "SELECT 'Order'.CustomerId, Customer.CompanyName, Customer.ContactName, Customer.ContactTitle, count('Order'.Id) as cuenta");
        painter.drawText(30, 55, "FROM 'Order', Customer");
        painter.drawText(30, 70, "WHERE Customer.Id='Order'.CustomerId");
        painter.drawText(30, 85, "GROUP BY 'Order'.CustomerId HAVING cuenta>1 ORDER BY cuenta DESC");

        uint32_t line {120};
        for(QString e : stringList)
        {
            painter.drawText(10, line, e);
            line += 16;
            if (line>=1050)
                printer.newPage();
            line %= 1050;
        }

        painter.end();
    }
}
