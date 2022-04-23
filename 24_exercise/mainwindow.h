#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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
    void selectDBWindow();
    void filenameUpdated(const QString &new_filename);
    void execExerciseA();
    void execExerciseB();
    void connectDB();

private:
    bool isValidFileName(const QString &filename);
    void set_actual_filenameDB(const QString& filenameDB);
    QString get_actual_filenameDB() const;

    Ui::MainWindow *ui;
    bool current_db_open{false};
};
#endif // MAINWINDOW_H
