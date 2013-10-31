#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QDialog>
#include <QMovie>
namespace Ui {
    class dialogabout;
}

class dialogabout : public QDialog
{
    Q_OBJECT

public:
    explicit dialogabout(QWidget *parent = 0);
    ~dialogabout();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogabout *ui;
};

#endif // DIALOGABOUT_H
