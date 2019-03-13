#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDir>
#include <QFileInfoList>





extern int imgno;



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
    void on_goldensample_button_clicked();

    void on_compareimages_button_clicked();

    void on_iterate_button_clicked();

    void on_fade_button_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_prev_clicked();

    void on_next_clicked();

private:
    Ui::MainWindow *ui;
    QString filename;
    QString filename1;
    QStringList images1;
    QStringList images;
    QString f;
    QImage img,img1;
    QDir directory,directory1;



};

#endif // MAINWINDOW_H
