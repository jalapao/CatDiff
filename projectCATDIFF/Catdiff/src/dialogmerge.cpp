#include "dialogmerge.h"
#include "ui_dialogmerge.h"

DialogMerge::DialogMerge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMerge)
{
    ui->setupUi(this);
    mergedModel->setColumnCount(1);
    ui->tableViewMerge->setModel(mergedModel);
    int properWidth = ui->tableViewMerge->width();
    ui->tableViewMerge->setColumnWidth(0,properWidth);
}

DialogMerge::~DialogMerge()
{
    delete ui;
}

bool DialogMerge::showText(std::vector<QString> textContent)
{
    QStandardItem* item;
    QString thisLine;
    int maxLineSize = 0;

    mergedContent = textContent;
    std::vector<QString>::iterator itTextContent;
    for(itTextContent = textContent.begin();itTextContent!= textContent.end(); itTextContent++)
    {
        thisLine = *itTextContent;
        item = new QStandardItem(thisLine);
        mergedModel->appendRow(item);
        maxLineSize = setLineSize(thisLine.length(),maxLineSize);
    }
    return true;
}

int DialogMerge::setLineSize(int length, int maxSize)
{
    if(length>maxSize)
    {
        maxSize = length;
    }
    ui->tableViewMerge->setColumnWidth(0,12*maxSize);
    return maxSize;
}

bool DialogMerge::on_buttonSave_clicked()
{

    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    //fileDialog->setFilter(myFilters);
    fileDialog->setOption(QFileDialog::ShowDirsOnly);
    fileDialog->setWindowTitle(tr("Save at..."));
    //fileDialog->setDirectory(".");
    //fileDialog->setFilter(tr("Image Files(*.jpg *.png)"));
    if(fileDialog->exec() == QDialog::Accepted)
    {
        QString path = fileDialog->selectedFiles()[0]+fileDialog->filter();

        //QMessageBox::information(NULL, tr("Path"), path);
        QFile fileToSave(path);
        if(!fileToSave.open(QIODevice::WriteOnly | QIODevice::Text| QIODevice::Append))
        {
            QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);
            return false;
        }
        std::vector<QString>::iterator itTextContent;
        QTextStream out(&fileToSave);
        //QTextStream out(&file);
        for(itTextContent = mergedContent.begin();itTextContent!= mergedContent.end(); itTextContent++)
        {
            out<<(*itTextContent)<<"\n";
            out.flush();
        }
        fileToSave.close();
    }
    else
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any folders."));
        return false;
    }
    return true;
}

void DialogMerge::on_buttonClose_clicked()
{
    this->close();
}
