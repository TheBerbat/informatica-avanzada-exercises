#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QProgressDialog>
#include <QThread>

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

void MainWindow::on_pushInsert_clicked()
{
    const std::string& search_word {ui->lineSearchWord->text().toStdString()};
    const QString& q_new_meaning {ui->lineNewMeaning->text()};
    const std::string& new_meaning {q_new_meaning.toStdString()};

    if (search_word.length()==0 || new_meaning.length()==0)
        return;

    dict.insert(search_word, new_meaning);
    ui->listMeanings->addItem(q_new_meaning);
    ui->lineNewMeaning->clear();
}


void MainWindow::on_pushDelete_clicked()
{
    const int id {ui->listMeanings->currentRow()};
    const std::string& search_word {ui->lineSearchWord->text().toStdString()};
    if (0<=id)
    {
        ui->listMeanings->takeItem(id);
        Dictionary::meanings_t& m {dict.search(search_word)};
        m.erase(m.begin()+id);
    }
}


void MainWindow::on_pushSearch_clicked()
{
    QString word { ui->lineSearchWord->text() };
    ui->listMeanings->clear();

    if (word.length()==0)
        return;

    QProgressDialog progress("Searching word...", "Cancel", 0, 100, this);
    progress.setWindowModality(Qt::WindowModal);

    for(std::size_t i{} ; i<=10 ; ++i)
    {
        QThread::sleep(1);
        progress.setValue(i*10);
        if (progress.wasCanceled())
            return;
    }


    try {
        auto a = dict.search(word.toStdString());
        for (auto& e : a)
            ui->listMeanings->addItem(e.c_str());
    }  catch (const std::out_of_range& e) {
        // Not found
    }
}


void MainWindow::on_lineSearchWord_editingFinished() { on_pushSearch_clicked(); }
void MainWindow::on_lineNewMeaning_returnPressed() { on_pushInsert_clicked(); }

