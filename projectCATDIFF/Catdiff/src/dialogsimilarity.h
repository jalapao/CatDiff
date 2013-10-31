#ifndef DIALOGSIMILARITY_H
#define DIALOGSIMILARITY_H

#include <QDialog>
#include <iostream>
#include <stdio.h>

namespace Ui {
class dialogSImilarity;
}

class dialogSImilarity : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialogSImilarity(QWidget *parent = 0);
    void setLabelValues(int la, int lb, int sl);
    ~dialogSImilarity();
    
private slots:
    //void on_pushButton_clicked();

    void on_buttonOK_clicked();

private:
    Ui::dialogSImilarity *ui;
    int linesOfA;
    int linesOfB;
    int similarLines;
    double similarity;
};

#endif // DIALOGSIMILARITY_H
