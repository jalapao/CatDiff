#include "dialogabout.h"
#include "ui_dialogabout.h"

dialogabout::dialogabout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogabout)
{
    ui->setupUi(this);
    //ui->label_2->setScaledContents(true);
    QMovie *movie=new QMovie("/home/wyr/linuxlinux/firstTry/image/about.png");
    ui->label_2->setMovie(movie);
    movie->start();
}

dialogabout::~dialogabout()
{
    delete ui;
}



void dialogabout::on_pushButton_clicked()
{
    this->close();
}
