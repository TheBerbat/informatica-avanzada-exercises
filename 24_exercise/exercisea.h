#ifndef EXERCISEA_H
#define EXERCISEA_H

#include <QDialog>

namespace Ui {
class ExerciseA;
}

class ExerciseA : public QDialog
{
    Q_OBJECT

public:
    explicit ExerciseA(QWidget *parent = nullptr);
    ~ExerciseA();

    void setResponse(double res);

private slots:
    void print();

private:
    Ui::ExerciseA *ui;
};

#endif // EXERCISEA_H
