#include "dialoghelp.h"
#include "ui_dialoghelp.h"

dialoghelp::dialoghelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialoghelp)
{
    ui->setupUi(this);
    QMovie *movie=new QMovie("/home/gongye/Desktop/1.gif");
    ui->label->setMovie(movie);
    movie->start();
}

dialoghelp::~dialoghelp()
{
    delete ui;
}

void dialoghelp::on_pushButton1_clicked()
{
    QMovie *movie=new QMovie("/home/gongye/Desktop/1.gif");
    ui->label->setMovie(movie);
    movie->start();
}

void dialoghelp::on_pushButton2_clicked()
{
    QMovie *movie=new QMovie("/home/gongye/Desktop/2.gif");
    ui->label->setMovie(movie);
    movie->start();
}


