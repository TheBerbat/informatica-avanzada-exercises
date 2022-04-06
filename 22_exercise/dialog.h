#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    uint8_t getValue();
    void setValue(uint8_t);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
