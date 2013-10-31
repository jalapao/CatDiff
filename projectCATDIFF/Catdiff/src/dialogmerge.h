#ifndef DIALOGMERGE_H
#define DIALOGMERGE_H

#include <QDialog>
#include <vector>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "filters.h"

namespace Ui {
class DialogMerge;
}

class DialogMerge : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogMerge(QWidget *parent = 0);
    bool showText(std::vector<QString> textContent);

    ~DialogMerge();
    
private slots:
    bool on_buttonSave_clicked();

    void on_buttonClose_clicked();

private:
    Ui::DialogMerge *ui;
    std::vector<QString> mergedContent;
    QStandardItemModel* mergedModel = new QStandardItemModel;
    int setLineSize(int length, int maxSize);
};

#endif // DIALOGMERGE_H
