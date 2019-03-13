#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QStringList>
#include <QDebug>
#include <QDirIterator>
#include <QGraphicsOpacityEffect>
#include <QMessageBox>



int imgno = 0;
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("IMAGE DIFFERENCE");
    this->showMaximized();
    ui->ilabel1->setMinimumSize(1,1);
    ui->ilabel2->setMinimumSize(1,1);



        ui->ilabel1->setScaledContents(true);
        ui->ilabel2->setScaledContents(true);




    if(imgno==0)
    {
        ui->prev->setVisible(false);
    }
    else
    {
        ui->prev->setVisible(true);
    }
    if(imgno==images.size())
    {
        ui->next->setVisible(false);
    }
    else
    {
        ui->next->setVisible(true);
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_goldensample_button_clicked()
{
    directory = QFileDialog::getExistingDirectory(this,tr("Choose Existing Directory",
                       "/home/",QFileDialog::DontResolveSymlinks|QFileDialog::ReadOnly));
    images = directory.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
   /* foreach (filename,images){
    QString f = directory.filePath(filename);
    qDebug() << f;
    }*/
}

void MainWindow::on_compareimages_button_clicked()
{
    directory1 = QFileDialog::getExistingDirectory(this,tr("Choose Existing Directory",
                       "/home/",QFileDialog::DontResolveSymlinks|QFileDialog::ReadOnly));
    images1 = directory1.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
    /*foreach (filename1,images1){
    QString f = directory1.filePath(filename1);
    qDebug() << f;
    }*/
}


void MainWindow::on_iterate_button_clicked()
{
    ui->next->setVisible(true);
    //static int i=0;

    ui->label1->setText(images[0]);
    //qDebug() << directory.absoluteFilePath(images[i]);
    img.load(directory.absoluteFilePath(images[0]));
    img = img.scaledToWidth(ui->ilabel1->width(),Qt::SmoothTransformation);
    //img = img.scaledToHeight(ui->ilabel1->height(),Qt::SmoothTransformation);
    ui->ilabel1->setPixmap(QPixmap::fromImage(img));



    ui->label2->setText(images1[0]);
    // qDebug()<< "new" << directory1.absoluteFilePath(images1[i]);
    img1.load(directory1.absoluteFilePath(images1[0]));
    img1 = img1.scaledToWidth(ui->ilabel2->width(),Qt::SmoothTransformation);
    //img1 = img1.scaledToHeight(ui->ilabel2->height(),Qt::SmoothTransformation);
    ui->ilabel2->setPixmap(QPixmap::fromImage(img1));


    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
    effect->setOpacity(1);
    ui->ilabel2->setGraphicsEffect(effect);


   // i++;
}

void MainWindow::on_fade_button_clicked()
{

    if((ui->ilabel1->pixmap() != 0) && (ui->ilabel2->pixmap() !=0))
    {
         QRect h = ui->ilabel1->geometry();

         ui->ilabel2->setGeometry(h);
    }

}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    if(ui->ilabel2->geometry() == ui->ilabel1->geometry())
    {
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
        effect->setOpacity(position*0.01);
        ui->ilabel2->setGraphicsEffect(effect);
    }
}

void MainWindow::on_prev_clicked()
{
    if(imgno > 0)
    {
        imgno--;
        ui->label1->setText(images[imgno]);
        img.load(directory.absoluteFilePath(images[imgno]));
        img = img.scaledToWidth(ui->ilabel1->width(),Qt::SmoothTransformation);
        //img = img.scaledToHeight(ui->ilabel1->height(),Qt::SmoothTransformation);
        ui->ilabel1->setPixmap(QPixmap::fromImage(img));

        ui->label2->setText(images1[imgno]);
        img1.load(directory1.absoluteFilePath(images1[imgno]));
        img1 = img1.scaledToWidth(ui->ilabel2->width(),Qt::SmoothTransformation);
        //img1 = img1.scaledToHeight(ui->ilabel2->height(),Qt::SmoothTransformation);
        ui->ilabel2->setPixmap(QPixmap::fromImage(img1));
    }
    else if(imgno==0)
    {
        ui->prev->setDisabled(true);
    }
}

void MainWindow::on_next_clicked()
{
    ui->iterate_button->setDisabled(true);
    ui->prev->setVisible(true);
    ui->prev->setEnabled(true);

    if(imgno <= images.size())
    {
        imgno++;

        ui->label1->setText(images[imgno]);
        img.load(directory.absoluteFilePath(images[imgno]));
        img = img.scaledToWidth(ui->ilabel1->width(),Qt::SmoothTransformation);
       // img = img.scaledToHeight(ui->ilabel1->height(),Qt::SmoothTransformation);
        ui->ilabel1->setPixmap(QPixmap::fromImage(img));

        ui->label2->setText(images1[imgno]);
        img1.load(directory1.absoluteFilePath(images1[imgno]));
        img1 = img1.scaledToWidth(ui->ilabel2->width(),Qt::SmoothTransformation);
      //  img1 = img1.scaledToHeight(ui->ilabel2->height(),Qt::SmoothTransformation);
        ui->ilabel2->setPixmap(QPixmap::fromImage(img1));

        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
        effect->setOpacity(1);
        ui->ilabel2->setGraphicsEffect(effect);
    }
    else
    {
        ui->next->setDisabled(true);
    }


}
