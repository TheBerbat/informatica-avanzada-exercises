#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "dictionary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushInsert_clicked();

    void on_pushDelete_clicked();

    void on_pushSearch_clicked();

    void on_lineSearchWord_editingFinished();

    void on_lineNewMeaning_returnPressed();

private:
    Ui::MainWindow *ui;

    Dictionary dict;
};
#endif // MAINWINDOW_H
