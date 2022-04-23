#ifndef EXERCISEB_H
#define EXERCISEB_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class ExerciseB;
}

class ExerciseB : public QDialog
{
    Q_OBJECT

public:
    explicit ExerciseB(QWidget *parent = nullptr);
    ~ExerciseB();

    void insertData(QString data);

private slots:
    void print();

private:
    Ui::ExerciseB *ui;

    QStringList stringList;
};

#endif // EXERCISEB_H
