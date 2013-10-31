#include "dialogsimilarity.h"
#include "ui_dialogsimilarity.h"

dialogSImilarity::dialogSImilarity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogSImilarity)
{
    ui->setupUi(this);
    linesOfA = 0;
    linesOfB = 0;
    similarLines = 0;
    similarity = 0;
}

dialogSImilarity::~dialogSImilarity()
{
    delete ui;
}

void dialogSImilarity::on_buttonOK_clicked()
{
    this->close();
}

void dialogSImilarity::setLabelValues(int la, int lb, int sl)
{
    char temp[32];
    linesOfA = la;
    linesOfB = lb;
    similarLines = sl;
    similarity  = (double)similarLines/(double)(linesOfA+linesOfB-similarLines);
    sprintf(temp, "%f",similarity);

    ui->myLabelLA->setText(QString::number(linesOfA));
    ui->myLabelLB->setText(QString::number(linesOfB));
    ui->myLabelSL->setText(QString::number(similarLines));
    ui->myLabelSM->setText(QString::fromStdString(temp));
}
