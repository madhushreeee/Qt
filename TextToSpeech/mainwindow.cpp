#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTextToSpeech>
#include <QVoice>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QStringList engines = QTextToSpeech::availableEngines();
    qDebug() <<  QTextToSpeech::availableEngines();//<< "Available engines:" << engines;
    for (auto engine : engines) {
        qDebug() << "  " << engine;
    }

speech = new QTextToSpeech;


    qDebug() << "Available locales:";
    for (auto locale : speech->availableLocales()) {
        qDebug() << "  " << locale;
    }


    speech->setLocale(QLocale(QLocale::English));


    qDebug() << "Available voices:";
    for (auto voice : speech->availableVoices()) {
        qDebug() << "  " << voice.name();
    }


    qDebug() << "Locale:" << speech->locale();
    qDebug() << "Pitch:" << speech->pitch();
    qDebug() << "Rate:" << speech->rate();
    qDebug() << "Voice:" << speech->voice().name();
    qDebug() << "Volume:" << speech->volume();
    qDebug() << "State:" << speech->state();



    speech->say(ui->textEdit->toPlainText());



}

void MainWindow::on_pause_clicked()
{
    speech->pause();
}

void MainWindow::on_resume_clicked()
{
    speech->resume();
}

void MainWindow::on_stop_clicked()
{
    speech->stop();
}
