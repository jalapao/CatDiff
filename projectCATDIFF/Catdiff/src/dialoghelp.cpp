#include "dialoghelp.h"
#include "ui_dialoghelp.h"

dialoghelp::dialoghelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialoghelp)
{
    ui->setupUi(this);
    //ui->label->setScaledContents(true);
    QMovie *movie=new QMovie("/home/wyr/linuxlinux/firstTry/image/help_basic_fun.png");
    ui->label->setMovie(movie);
    movie->start();
}

dialoghelp::~dialoghelp()
{
    delete ui;
}

void dialoghelp::on_pushButton1_clicked()
{
    //ui->label->setScaledContents(true);
    QMovie *movie=new QMovie("/home/wyr/linuxlinux/firstTry/image/help_basic_fun.png");
    ui->label->setMovie(movie);
    movie->start();
}

void dialoghelp::on_pushButton2_clicked()
{
    //ui->label->setScaledContents(true);
    QMovie *movie=new QMovie("/home/wyr/linuxlinux/firstTry/image/help_add_func.png");
    ui->label->setMovie(movie);
    movie->start();
}



void dialoghelp::on_pushButton_clicked()
{
    this->close();
}
