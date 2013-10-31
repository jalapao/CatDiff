#ifndef DIALOGHELP_H
#define DIALOGHELP_H

#include <QDialog>
#include <QMovie>
namespace Ui {
    class dialoghelp;
}

class dialoghelp : public QDialog
{
    Q_OBJECT

public:
    explicit dialoghelp(QWidget *parent = 0);
    ~dialoghelp();

private:
    Ui::dialoghelp *ui;

private slots:
    void on_pushButton2_clicked();
    void on_pushButton1_clicked();
    void on_pushButton_clicked();
};

#endif // DIALOGHELP_H
