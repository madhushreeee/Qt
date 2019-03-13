#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtTextToSpeech>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pause_clicked();

    void on_resume_clicked();

    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    QTextToSpeech *speech;

};

#endif // MAINWINDOW_H
