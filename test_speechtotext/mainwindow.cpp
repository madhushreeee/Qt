#include "mainwindow.h"
#include "ui_mainwindow.h"

//#define MODELDIR "D:/pocketsphinx/pocketsphinx/model"
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>
#include <QDebug>

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
    ps_decoder_t *ps = NULL;
    cmd_ln_t *config = NULL;
    char const *hyp;
    int32 score;
    int rv;
    int16 buf[512];
    FILE *fh;

    config = cmd_ln_init(NULL, ps_args(),TRUE,"-hmm", "D:/pocketsphinx/pocketsphinx/model/en-us/en-us","-lm","D:/pocketsphinx/pocketsphinx/model/en-us/en-us.lm.bin","-dict","D:/pocketsphinx/pocketsphinx/model/en-us/cmudict-en-us.dict",NULL);



    if(config == NULL)
    {
        qDebug() << "failed to create config object";
    }



    ps = ps_init(config);


    if(ps == NULL)
    {
        qDebug() << "failed to create recognizer";
    }

    fh = fopen("D://002.wav","rb");
    if (fh == NULL) {
        qDebug() << "unable to open input file\n";
        }

    rv = ps_start_utt(ps);


    while (!feof(fh)) {
        size_t nsamp;
        nsamp = fread(buf, 2, 512, fh);
        rv = ps_process_raw(ps, buf, nsamp,FALSE,FALSE);
      }

    rv= ps_end_utt(ps);

    hyp = ps_get_hyp(ps , &score);


    qDebug() << hyp;

    ps_free(ps);
    cmd_ln_free_r(config);

}
