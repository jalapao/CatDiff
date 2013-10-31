#ifndef FOLDERDIFF_H
#include "dialoghelp.h"
#define FOLDERDIFF_H

#include<QFileInfo>
#include<vector>
#include"numberPair.h"
#include<QDateTime>

dialoghelp::dialoghelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialoghelp)
{
    ui->setupUi(this);
    //ui->label->setScaledContents(true);
    QMovie *movie=new QMovie("/home/gongye/Documents/6/firstTry/image/help_basic_fun.png");
    ui->label->setMovie(movie);
    movie->start();
#include<QMessageBox>


class FolderDiff
{
public:
    FolderDiff();
    void listToVector(QFileInfoList infoList, int tableViewID);
    bool differVectors(std::vector<QFileInfo> *vInfoSame,std::vector<QFileInfo> *vInfoHalfSame,std::vector<QFileInfo> *vInfoNotSameC,std::vector<QFileInfo> *vInfoNotSameD);
{
    delete ui;
    bool checkVectors();


void dialoghelp::on_pushButton1_clicked()
{
    //ui->label->setScaledContents(true);
    QMovie *movie=new QMovie("/home/gongye/Documents/6/firstTry/image/help_basic_fun.png");
    ui->label->setMovie(movie);
    movie->start();
    ~FolderDiff();

private:
    std::vector<QFileInfo> vInfoC;
    std::vector<QFileInfo> vInfoD;
    std::vector<numberPair> vNumberPairSame;

void dialoghelp::on_pushButton2_clicked()
{
    //ui->label->setScaledContents(true);
    QMovie *movie=new QMovie("/home/gongye/Documents/6/firstTry/image/help_add_func.png");
    ui->label->setMovie(movie);
    movie->start();
    std::vector<numberPair> vNumberPairHalfSame;

};



void dialoghelp::on_pushButton_clicked()
{
    this->close();
#endif // FOLDERDIFF_H
