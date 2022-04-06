#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

uint8_t Dialog::getValue()
{
   return static_cast<uint8_t>(ui->spinBox->value());
}

void Dialog::setValue(uint8_t value)
{
   ui->spinBox->setValue(value);
}
