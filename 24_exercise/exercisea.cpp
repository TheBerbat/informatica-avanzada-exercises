#include "exercisea.h"
#include "ui_exercisea.h"

#include <QPrinter>
#include <QPainter>
#include <QFileDialog>

ExerciseA::ExerciseA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExerciseA)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, &QPushButton::clicked,
                     this, &ExerciseA::print);
}

ExerciseA::~ExerciseA()
{
    delete ui;
}

void ExerciseA::setResponse(double res)
{
    auto spanish_locale = QLocale("es_ES");
    auto num = spanish_locale.toString(res, 'f', 2);
    ui->lineEdit->setText(QString("%1€").arg(num));
}

void ExerciseA::print()
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

        painter.drawText(30, 40, "SELECT sum(OrderDetail.Quantity*OrderDetail.UnitPrice*(1-OrderDetail.Discount))as 'TotalPrice'");
        painter.drawText(30, 55, "FROM OrderDetail, Product ");
        painter.drawText(30, 70, "WHERE Product.CategoryId == 1 AND OrderDetail.ProductId == Product.Id");

        painter.drawText(10, 150, ui->lineEdit->text());

        painter.end();
    }
}
