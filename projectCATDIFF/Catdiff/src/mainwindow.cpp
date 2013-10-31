#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoStructure.h"
#include "dialogmerge.h"
#include "FolderDiff.h"
#include "dialogabout.h"
#include "dialoghelp.h"
#include "dialogsimilarity.h"
#define column_width 50

bool folderMode = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    modelA->setColumnCount(2);
    modelB->setColumnCount(2);
    modelC->setColumnCount(3);
    modelD->setColumnCount(3);
    setHeaders();
    ui->setupUi(this);

    ui->tableViewA->setModel(modelA);
    ui->tableViewA->setColumnWidth(0,column_width);
    ui->tableViewB->setModel(modelB);
    ui->tableViewB->setColumnWidth(0,column_width);
    ui->tableViewC->setModel(modelC);
    ui->tableViewD->setModel(modelD);
    ui->tableViewC->setColumnWidth(0,150);
    ui->tableViewC->setColumnWidth(1,100);
    ui->tableViewC->setColumnWidth(2,281);
    ui->tableViewD->setColumnWidth(0,150);
    ui->tableViewD->setColumnWidth(1,100);
    ui->tableViewD->setColumnWidth(2,281);

    ui->tableViewC->hide();
    ui->tableViewD->hide();

    //ui->tableViewA->verticalScrollbarValueChanged();

//    ui->buttonDiffer->setFlat(true);
//    ui->buttonMerge->setFlat(true);
//    ui->openButtonA->setFlat(true);
//    ui->openButtonB->setFlat(true);
//    ui->buttonMode->setFlat(true);
//    ui->frame->setStyleSheet("QFrame#myframe{border-image:url(image/2_1.png)}");
//    ui->frame->show();

//    QPixmap pixmap("image/2_1.png");
//    QPalette myPalette;
//    myPalette.setBrush(ui->frame->backgroundRole(),QBrush(pixmap));
//    ui->frame->setPalette(myPalette);
//    ui->frame->setMask(pixmap.mask()); //可以将图片中透明部分显示为透明的
//    ui->frame->setAutoFillBackground(true);
//    ui->frame->show();
}

void MainWindow::connetScrollBars()
{
    QObject::connect((QObject*)ui->tableViewA->verticalScrollBar(),SIGNAL(valueChanged(int)),(QObject*)ui->tableViewB->verticalScrollBar(),SLOT(setValue(int)));
    QObject::connect((QObject*)ui->tableViewB->verticalScrollBar(),SIGNAL(valueChanged(int)),(QObject*)ui->tableViewA->verticalScrollBar(),SLOT(setValue(int)));
}

void MainWindow::disconnetScrollBars()
{
    QObject::disconnect((QObject*)ui->tableViewA->verticalScrollBar(),SIGNAL(valueChanged(int)),(QObject*)ui->tableViewB->verticalScrollBar(),SLOT(setValue(int)));
    QObject::disconnect((QObject*)ui->tableViewB->verticalScrollBar(),SIGNAL(valueChanged(int)),(QObject*)ui->tableViewA->verticalScrollBar(),SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked(int ButtonID)
{
    if(folderMode)
    {
        folderModeOpen(ButtonID);
        return;
    }
    QFileDialog* fd = new QFileDialog( this );
    fd->setFilter(myFilters);
    fd->show();
    if(fd->exec()==QFileDialog::Accepted) // ok
    {
        QStringList fileList= fd->selectedFiles();
        QString fileSelected = fileList.front();

        if(ButtonID == 1)
        {
            ui->tableViewA->clearSpans();
            bufferTextVectorA.clear();
            modelA->clear();
            ui->filePathA->setText(fileSelected);
            showTextInBrowser(fileSelected,1);
        }
        if(ButtonID == 2)
        {
            ui->tableViewB->clearSpans();
            bufferTextVectorB.clear();
            modelB->clear();
            ui->filePathB->setText(fileSelected);
            showTextInBrowser(fileSelected,2);
        }
        //qWarning(s);
    }
}

void MainWindow::showTextInBrowser(QString fileSelected,int ButtonID)
{
    QFile fileToShow(fileSelected);
    if(!fileToShow.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);

    }
    //int fileSize = fileToShow.size();
    int countOfLines = 0;

    disconnetScrollBars();

    QTextStream in(&fileToShow);
    int maxLineSize = 0;
    QString textLine;
    while(!in.atEnd())//读取一行
    {
        textLine = in.readLine();
        maxLineSize = max_line_size(maxLineSize,textLine);
        //std::string bufferLine = textLine.toStdString();
        if(ButtonID==1)
        {
            bufferTextVectorA.push_back(textLine);
        }
        if(ButtonID==2)
        {
            bufferTextVectorB.push_back(textLine);
        }

        countOfLines++;
        char buffer[16];
        sprintf(buffer,"%d",countOfLines);
        QString countOfLinesString = QString::fromStdString(buffer);
        add_item_to_tableview(countOfLinesString,textLine,ButtonID);
    }

    if(ButtonID==1)
    {
        set_columns_width(maxLineSize,1);
        countOfLinesA = countOfLines;
    }
    if(ButtonID==2)
    {
        set_columns_width(maxLineSize,2);
        countOfLinesB = countOfLines;
    }
    fileToShow.close();
}

void MainWindow::add_item_to_tableview(QString countOfLinesString, QString textLine,int ButtonID)
{
    //QStandardItem* item1 = new QStandardItem(countOfLinesString);
    QStandardItem* item1 = new QStandardItem(" ");
    QStandardItem* item2 = new QStandardItem(textLine);
    QList<QStandardItem*> item;
    item << item1 << item2;

    if(ButtonID == 1)
    {
        modelA->appendRow(item);
    }
    if(ButtonID == 2)
    {
        modelB->appendRow(item);
    }
}

void MainWindow::on_openButtonA_clicked()
{
     on_openButton_clicked(1);
}

void MainWindow::on_openButtonB_clicked()
{
     on_openButton_clicked(2);
}

int MainWindow::max_line_size(int maxLineSize, QString textLine)
{
    int lineSize = 0;
    lineSize = textLine.size();
    if(lineSize>maxLineSize)
    {return lineSize;}
    else
    {return maxLineSize;}
}

void MainWindow::drawGreenTextOnLeftAndBlankOnRight(QString content, int lineNumber)
{
    drawSomething("+", QColor(181,212,255,150), 1, content, lineNumber);
}

void MainWindow::drawRedTextOnRightAndBlankOnLeft(QString content, int lineNumber)
{
    drawSomething("-", QColor(254,192,223,150), 2, content, lineNumber);
}

void MainWindow::drawWhiteTextOnBothSides(QString content, int lineNumberA, int lineNumberB)
{
    QStandardItem* itemDot1;
    QStandardItem* itemDot2;
    QStandardItem* itemContent1;
    QStandardItem* itemContent2;
    QList<QStandardItem*> item1;
    QList<QStandardItem*> item2;
    int maxLineSize = 0;            //it is used for setting width of the tableView

    char tempChar[16];
    sprintf(tempChar, "%d",lineNumberA);
    QString lineNumberStringA = QString::fromStdString(tempChar);
    sprintf(tempChar, "%d", lineNumberB);
    QString lineNumberStringB = QString::fromStdString(tempChar);

    itemDot1 = new QStandardItem(lineNumberStringA);
    itemDot2 = new QStandardItem(lineNumberStringB);
    itemContent1 = new QStandardItem(content);
    itemContent2 = new QStandardItem(content);
    item1.clear();
    item2.clear();

    itemDot1->setBackground(QBrush(QColor(255,255,255,255)));
    itemDot2->setBackground(QBrush(QColor(255,255,255,255)));
    itemContent1->setBackground(QBrush(QColor(255,255,255,255)));
    itemContent2->setBackground(QBrush(QColor(255,255,255,255)));

    item1 << itemDot1 << itemContent1;
    item2<< itemDot2<< itemContent2;

    modelA->appendRow(item1);
    modelB->appendRow(item2);

    maxLineSize = max_line_size(maxLineSize,content);
    set_columns_width(maxLineSize,1);
    set_columns_width(maxLineSize,2);
}

void MainWindow::drawSomething(QString plusOrMinus, QColor greenOrRed, int AorB, QString content, int lineNumber)
{
    QStandardItem* itemDot1;
    QStandardItem* itemDot2;
    QStandardItem* itemContent;
    QStandardItem* itemBlank;
    QList<QStandardItem*> item;
    QList<QStandardItem*> itemBlankRow;
    int maxLineSize = 0;            //it is used for setting width of the tableView

    char tempChar[16];
    sprintf(tempChar, "%d",lineNumber);
    QString lineNumberString = QString::fromStdString(tempChar);

    itemDot1 = new QStandardItem(lineNumberString);
    itemDot2 = new QStandardItem(plusOrMinus);
    itemContent = new QStandardItem(content);
    itemBlank = new QStandardItem(" ");
    item.clear();
    itemBlankRow.clear();

    itemDot1->setBackground(QBrush(greenOrRed));
    itemDot2->setBackground(QBrush(greenOrRed));
    itemContent->setBackground(QBrush(greenOrRed));
    itemBlank->setBackground(QBrush(greenOrRed));

    item << itemDot1 << itemContent;
    itemBlankRow << itemDot2 << itemBlank;

    //if write something in A, it's 1.
    //if write something in B, it's 2.
    if(AorB == 1)
    {
        modelA->appendRow(item);
        modelB->appendRow(itemBlankRow);
    }
    else if(AorB == 2)
    {
        modelB->appendRow(item);
        modelA->appendRow(itemBlankRow);
    }

    maxLineSize = max_line_size(maxLineSize,content);
    set_columns_width(maxLineSize,1);
    set_columns_width(maxLineSize,2);

}

bool MainWindow::on_buttonDiffer_clicked()
{
    if(folderMode)
    {
        if(folderModeDiffer())
        {return true;}
        else
        {return false;}
    }
    clearThingsOfFileMode();

    bufferTextVectorMerge.clear();

    std::vector<QString>::iterator itBufferTextVectorA;
    std::vector<QString>::iterator itBufferTextVectorB;

    QString filePathAString = ui->filePathA->toPlainText();
    QString filePathBString = ui->filePathB->toPlainText();

    if((filePathAString.length() == 0)||(filePathBString.length() == 0))
    {
        QMessageBox::warning(this,"Error","You need to choose two files!",QMessageBox::Yes);
        ui->filePathA->clear();
        ui->filePathB->clear();
        return false;
    }

    AlgoStructure algoTable[countOfLinesA+1][countOfLinesB+1];
    for(int i= 0;i<=countOfLinesA;i++)
    {
        for(int j=0;j<=countOfLinesB;j++)
        {
            algoTable[i][j] = AlgoStructure(0,0,0,i,j);
        }
    }

    AlgoStructure algoStructureTemp;
    int countTempA = 0;
    int countTempB = 0;

    for(itBufferTextVectorA = bufferTextVectorA.begin();itBufferTextVectorA!=bufferTextVectorA.end();itBufferTextVectorA++)
    {
        countTempA++;
        countTempB = 0;
        for(itBufferTextVectorB= bufferTextVectorB.begin();itBufferTextVectorB!=bufferTextVectorB.end();itBufferTextVectorB++)
        {
            countTempB++;
            if(!QString::compare(*itBufferTextVectorA,*itBufferTextVectorB))
            {
                algoStructureTemp.set(algoTable[countTempA-1][countTempB-1].getLongestSequence()+1, countTempA-1, countTempB-1,countTempA,countTempB);
                algoTable[countTempA][countTempB] = algoStructureTemp;
            }
            else
            {
                if(algoTable[countTempA][countTempB-1].getLongestSequence()>algoTable[countTempA-1][countTempB].getLongestSequence())
                {
                    algoStructureTemp.set(algoTable[countTempA][countTempB-1].getLongestSequence(),
                                          algoTable[countTempA][countTempB-1].getFatherX(),algoTable[countTempA][countTempB-1].getFatherY(),
                                          countTempA,countTempB);
                }
                else
                {
                    algoStructureTemp.set(algoTable[countTempA-1][countTempB].getLongestSequence(),
                                          algoTable[countTempA-1][countTempB].getFatherX(),algoTable[countTempA-1][countTempB].getFatherY(),
                                          countTempA,countTempB);
                }
                algoTable[countTempA][countTempB] = algoStructureTemp;
            }
        }
    }//fill in the whole table to find LCS.

    longestCommonSubsequence.clear();
    longestCommonSubsequence.push_back(algoTable[countOfLinesA][countOfLinesB]);
    int indexX = countOfLinesA;
    int indexY = countOfLinesB;
    int newIndexX;
    int newIndexY;
    while(indexX>0 && indexY>0)
    {
        newIndexX = algoTable[indexX][indexY].getFatherX();
        newIndexY = algoTable[indexX][indexY].getFatherY();
        indexX = newIndexX;
        indexY = newIndexY;
        longestCommonSubsequence.push_back(algoTable[indexX][indexY]);
    }
    longestCommonSubsequence.pop_back();
    reshowTextInTableView();
    showSimilarity();
    return true;
}

void MainWindow::showSimilarity()
{
    dialogSImilarity *dSimilarity = new dialogSImilarity;
    dSimilarity->setLabelValues(bufferTextVectorA.size(),bufferTextVectorB.size(),longestCommonSubsequence.size());
    dSimilarity->show();
}

void MainWindow::reshowTextInTableView()
{
    clearThingsOfFileMode();

    connetScrollBars();

    std::vector<bool> luckyFlagA;
    std::vector<bool> luckyFlagB;
    int countA = 0;
    int countB = 0;


    luckyFlagA.resize(bufferTextVectorA.size(),false);
    luckyFlagB.resize(bufferTextVectorB.size(),false);

    for(int i = 0; i < longestCommonSubsequence.size();i++)
    {
        luckyFlagA[longestCommonSubsequence[i].getMyX() - 1] = true;
        luckyFlagB[longestCommonSubsequence[i].getMyY() - 1] = true;
    }

    while(!((countA >= bufferTextVectorA.size()) && (countB >= bufferTextVectorB.size())))
    {
        for(;countA<bufferTextVectorA.size();countA++)
        {
            if(!luckyFlagA[countA])
            {
                bufferTextVectorMerge.push_back(bufferTextVectorA[countA]);
                drawGreenTextOnLeftAndBlankOnRight(bufferTextVectorA[countA], countA+1);
            }
            else
            {
                break;
            }
        }
        for(;countB<bufferTextVectorB.size();countB++)
        {
            if(!luckyFlagB[countB])
            {
                bufferTextVectorMerge.push_back(bufferTextVectorB[countB]);
                drawRedTextOnRightAndBlankOnLeft(bufferTextVectorB[countB], countB+1);
            }
            else
            {
                break;
            }
        }
        for(;countA<bufferTextVectorA.size() || countB<bufferTextVectorB.size();countA++,countB++)
        {
            if(countA<bufferTextVectorA.size())
            {
                if(luckyFlagA[countA])
                {
                    bufferTextVectorMerge.push_back(bufferTextVectorA[countA]);
                    drawWhiteTextOnBothSides(bufferTextVectorA[countA], countA+1, countB+1);
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(luckyFlagB[countB])
                {
                    bufferTextVectorMerge.push_back(bufferTextVectorB[countB]);
                    drawWhiteTextOnBothSides(bufferTextVectorB[countB], countA+1, countB+1);
                }
                else
                {
                    break;
                }
            }
        }
    }
}


void MainWindow::set_columns_width(int maxLineSize, int who)
{
    int originalSize;
    switch(who)
    {
        case 1:
        {
            originalSize = ui->tableViewA->columnWidth(1);//geometry().width();
            ui->tableViewA->setColumnWidth(0,column_width);
            if(originalSize<12*maxLineSize)
            {
                ui->tableViewA->setColumnWidth(1,12*maxLineSize);
            }
        }
        case 2:
        {
            originalSize = ui->tableViewB->columnWidth(1);
            ui->tableViewB->setColumnWidth(0,column_width);
            if(originalSize<12*maxLineSize)
            {
                ui->tableViewB->setColumnWidth(1,12*maxLineSize);
            }
        }
    }
}

bool MainWindow::on_buttonMerge_clicked()
{
    if(folderMode)
    {
        if(folderModeMerge())
        {return true;}
        else
        {return false;}
    }

    bool checkAndDiffer =  on_buttonDiffer_clicked();
    if(!checkAndDiffer)
    {return false;}

    DialogMerge *dialogMerge = new DialogMerge();
    dialogMerge->show();
    dialogMerge->showText(bufferTextVectorMerge);
    return true;
}

void MainWindow::on_buttonMode_clicked()
{
    folderMode = !folderMode;
    if(folderMode)
    {
        ui->buttonMode->setText("Compare Files");
        ui->tableViewA->hide();
        ui->tableViewB->hide();
        ui->filePathA->clear();
        ui->filePathB->clear();
        clearThingsOfFileMode();
        ui->tableViewC->show();
        ui->tableViewD->show();
        ui->buttonMerge->setEnabled(false);
        //ui->buttonMode->hide();
        folderDiff = new FolderDiff;

    }
    else
    {
        delete folderDiff;
        ui->buttonMode->setText("Compare Folders");
        ui->tableViewC->hide();
        ui->tableViewD->hide();
        ui->filePathA->clear();
        ui->filePathB->clear();
        clearThingsOfFolderMode();
        ui->buttonMerge->setEnabled(true);
        ui->tableViewA->show();
        ui->tableViewB->show();

    }
}

void MainWindow::clearThingsOfFileMode()
{
    modelA->clear();
    modelB->clear();
    ui->tableViewA->clearSpans();
    ui->tableViewB->clearSpans();
}

void MainWindow::clearThingsOfFolderMode()
{
    modelC->clear();
    modelD->clear();
    ui->tableViewC->clearSpans();
    ui->tableViewD->clearSpans();
}

void MainWindow::folderModeOpen(int buttonID)
{
    QFileDialog* fd = new QFileDialog( this );
    fd->setOption(QFileDialog::ShowDirsOnly);
    fd->setFileMode(QFileDialog::Directory);
    fd->show();
    if(fd->exec()==QFileDialog::Accepted) // ok
    {
        QStringList fileList= fd->selectedFiles();
        QString fileSelected = fileList.front();
        QDir chosenDir(fileSelected);
        QFileInfoList listOfFiles = chosenDir.entryInfoList();

        if(buttonID == 1)
        {
            ui->tableViewC->clearSpans();
            modelC->clear();
            ui->filePathA->setText(fileSelected);
            showDirFilesInTableView(listOfFiles,1);
        }
        if(buttonID == 2)
        {
            ui->tableViewD->clearSpans();
            modelD->clear();
            ui->filePathB->setText(fileSelected);
            showDirFilesInTableView(listOfFiles,2);
        }
    }


}

void MainWindow::showDirFilesInTableView(QFileInfoList listOfFiles, int tableViewID)
{
    qint64 fileSize;
    char tempSize[16];
    QString fileSizeString;
    QString name;
    QString modifyTimeString;
    QStandardItem* item1;
    QStandardItem* item2;
    QStandardItem* item3;

    int maxLineSize1 = 0;
    int maxLineSize2 = 0;
    int maxLineSize3 = 0;

    if(tableViewID == 1)
    {
        folderDiff->listToVector(listOfFiles,1);
        for(int i=0;i<listOfFiles.length();i++)
        {
            name = listOfFiles[i].fileName();
            if(name=="."||name=="..")
            {continue;}
            fileSize = listOfFiles[i].size();
            sprintf(tempSize, "%ld", fileSize);
            fileSizeString = QString::number(fileSize);

            modifyTimeString = listOfFiles[i].lastModified().toString("yyyy/MM/dd hh:mm:ss");

            item1 = new QStandardItem(name);
            item2 = new QStandardItem(tempSize);
            item3 = new QStandardItem(modifyTimeString);
            QList<QStandardItem*> item;
            item<<item1<<item2<<item3;
            modelC->appendRow(item);

            maxLineSize1 = max_line_size(maxLineSize1,name);
            maxLineSize2 = max_line_size(maxLineSize2,tempSize);
            maxLineSize3 = max_line_size(maxLineSize3,modifyTimeString);

        }
        ui->tableViewC->setColumnWidth(0,12*maxLineSize1);
        ui->tableViewC->setColumnWidth(1,12*maxLineSize2);
        if(12*(maxLineSize1+maxLineSize2+maxLineSize3)<531)
        {
            ui->tableViewC->setColumnWidth(2,531-12*(maxLineSize1+maxLineSize2));
        }
        else
        {
            ui->tableViewC->setColumnWidth(2,12*maxLineSize3);
        }
            setHeaders();
    }
    if(tableViewID == 2)
    {
        folderDiff->listToVector(listOfFiles,2);
        for(int i=0;i<listOfFiles.length();i++)
        {
           name = listOfFiles[i].fileName();
           if(name=="."||name=="..")
           {continue;}
           fileSize = listOfFiles[i].size();
           QString fileSizeString;
           sprintf(tempSize, "%ld", fileSize);
           fileSizeString = QString::number(fileSize);

           modifyTimeString = listOfFiles[i].lastModified().toString("yyyy/MM/dd hh:mm:ss");

            item1 = new QStandardItem(name);
            item2 = new QStandardItem(tempSize);
            item3 = new QStandardItem(modifyTimeString);
            QList<QStandardItem*> item;
            item<<item1<<item2<<item3;
            modelD->appendRow(item);
            maxLineSize1 = max_line_size(maxLineSize1,name);
            maxLineSize2 = max_line_size(maxLineSize2,tempSize);
            maxLineSize3 = max_line_size(maxLineSize3,modifyTimeString);
        }
        ui->tableViewD->setColumnWidth(0,12*maxLineSize1);
        ui->tableViewD->setColumnWidth(1,12*maxLineSize2);
        if(12*(maxLineSize1+maxLineSize2+maxLineSize3)<531)
        {
            ui->tableViewD->setColumnWidth(2,531-12*(maxLineSize1+maxLineSize2));
        }
        else
        {
            ui->tableViewD->setColumnWidth(2,12*maxLineSize3);
        }
            setHeaders();

    }
}

bool MainWindow::folderModeDiffer()
{
    std::vector<QFileInfo> *vInfoSame =  new std::vector<QFileInfo>;
    std::vector<QFileInfo> *vInfoHalfSame =  new std::vector<QFileInfo>;
    std::vector<QFileInfo> *vInfoNotSameC =  new std::vector<QFileInfo>;
    std::vector<QFileInfo> *vInfoNotSameD =  new std::vector<QFileInfo>;
    if((folderDiff->differVectors(vInfoSame,vInfoHalfSame,vInfoNotSameC,vInfoNotSameD))==false)
    {
        clearThingsOfFolderMode();
        QMessageBox::warning(this,"Error","You must choose two files!",QMessageBox::Yes);
        ui->filePathA->clear();
        ui->filePathB->clear();
        setHeaders();
        return false;
    }

    clearThingsOfFolderMode();

    qint64 fileSize;
    char tempSize[16];
    QString fileSizeString;
    QString name;
    QString modifyTimeString;
    QStandardItem* itemC1;
    QStandardItem* itemC2;
    QStandardItem* itemC3;
    QStandardItem* itemD1;
    QStandardItem* itemD2;
    QStandardItem* itemD3;
    QBrush halfSameColor = QBrush(QColor(255,251,195,100));
    QBrush sameColor = QBrush(QColor(255,255,255,255));
    QBrush notSameCColor = QBrush(QColor(181,212,255,150));
    QBrush notSameDColor = QBrush(QColor(254,192,223,150));

    int maxLineSize1 = 0;
    int maxLineSize2 = 0;
    int maxLineSize3 = 0;

    for(int countSame =0; countSame<vInfoSame->size();countSame++)
    {
        name = (*vInfoSame)[countSame].fileName();
        if(name=="."||name=="..")
        {continue;}
        fileSize =(*vInfoSame)[countSame].size();
        sprintf(tempSize,"%ld",fileSize);
        //fileSizeString = QString::number(fileSize);

        modifyTimeString = (*vInfoSame)[countSame].lastModified().toString("yyyy/MM/dd hh:mm:ss");

        itemC1 = new QStandardItem(name);
        itemC2 = new QStandardItem(tempSize);
        itemC3 = new QStandardItem(modifyTimeString);
        itemD1 = new QStandardItem(name);
        itemD2 = new QStandardItem(tempSize);
        itemD3 = new QStandardItem(modifyTimeString);
        itemC1->setBackground(sameColor);
        itemC2->setBackground(sameColor);
        itemC3->setBackground(sameColor);
        itemD1->setBackground(sameColor);
        itemD2->setBackground(sameColor);
        itemD3->setBackground(sameColor);
        QList<QStandardItem*> item;
        QList<QStandardItem*> item2;
        item<<itemC1<<itemC2<<itemC3;
        item2<<itemD1<<itemD2<<itemD3;
        modelC->appendRow(item);
        modelD->appendRow(item2);

        maxLineSize1 = max_line_size(maxLineSize1,name);
        maxLineSize2 = max_line_size(maxLineSize2,tempSize);
        maxLineSize3 = max_line_size(maxLineSize3,modifyTimeString);
    }

    for(int countSame =0; countSame<vInfoHalfSame->size();countSame++)
    {
        name = (*vInfoHalfSame)[countSame].fileName();
        if(name=="."||name=="..")
        {continue;}
        fileSize = (*vInfoHalfSame)[countSame].size();
        sprintf(tempSize, "%ld", fileSize);


        modifyTimeString = (*vInfoHalfSame)[countSame].lastModified().toString("yyyy/MM/dd hh:mm:ss");

        itemC1 = new QStandardItem(name);
        itemC2 = new QStandardItem(tempSize);
        itemC3 = new QStandardItem(modifyTimeString);
        itemD1 = new QStandardItem(name);
        itemD2 = new QStandardItem(tempSize);
        itemD3 = new QStandardItem(modifyTimeString);
        itemC1->setBackground(halfSameColor);
        itemC2->setBackground(halfSameColor);
        itemC3->setBackground(halfSameColor);
        itemD1->setBackground(halfSameColor);
        itemD2->setBackground(halfSameColor);
        itemD3->setBackground(halfSameColor);
        QList<QStandardItem*> item;
        QList<QStandardItem*> item2;
        item<<itemC1<<itemC2<<itemC3;
        item2<<itemD1<<itemD2<<itemD3;
        modelC->appendRow(item);
        modelD->appendRow(item2);

        maxLineSize1 = max_line_size(maxLineSize1,name);
        maxLineSize2 = max_line_size(maxLineSize2,fileSizeString);
        maxLineSize3 = max_line_size(maxLineSize3,modifyTimeString);
    }

    for(int count =0; count<vInfoNotSameC->size();count++)
    {
        name = (*vInfoNotSameC)[count].fileName();
        if(name=="."||name=="..")
        {continue;}
        fileSize = (*vInfoNotSameC)[count].size();
        sprintf(tempSize, "%ld", fileSize);

        modifyTimeString = (*vInfoNotSameC)[count].lastModified().toString("yyyy/MM/dd hh:mm:ss");

        itemC1 = new QStandardItem(name);
        itemC2 = new QStandardItem(tempSize);
        itemC3 = new QStandardItem(modifyTimeString);

        itemC1->setBackground(notSameCColor);
        itemC2->setBackground(notSameCColor);
        itemC3->setBackground(notSameCColor);

        QList<QStandardItem*> item;

        item<<itemC1<<itemC2<<itemC3;

        modelC->appendRow(item);

        maxLineSize1 = max_line_size(maxLineSize1,name);
        maxLineSize2 = max_line_size(maxLineSize2,tempSize);
        maxLineSize3 = max_line_size(maxLineSize3,modifyTimeString);
    }

    for(int count =0; count<vInfoNotSameD->size();count++)
    {
        name = (*vInfoNotSameD)[count].fileName();
        if(name=="."||name=="..")
        {continue;}
        fileSize = (*vInfoNotSameD)[count].size();
        sprintf(tempSize, "%ld", fileSize);

        modifyTimeString = (*vInfoNotSameD)[count].lastModified().toString("yyyy/MM/dd hh:mm:ss");

        itemD1 = new QStandardItem(name);
        itemD2 = new QStandardItem(tempSize);
        itemD3 = new QStandardItem(modifyTimeString);

        itemD1->setBackground(notSameDColor);
        itemD2->setBackground(notSameDColor);
        itemD3->setBackground(notSameDColor);

        QList<QStandardItem*> item;

        item<<itemD1<<itemD2<<itemD3;

        modelD->appendRow(item);

        maxLineSize1 = max_line_size(maxLineSize1,name);
        maxLineSize2 = max_line_size(maxLineSize2,tempSize);
        maxLineSize3 = max_line_size(maxLineSize3,modifyTimeString);
    }



    ui->tableViewC->setColumnWidth(0,12*maxLineSize1);
    ui->tableViewC->setColumnWidth(1,12*maxLineSize2);
    if(12*(maxLineSize1+maxLineSize2+maxLineSize3)<531)
    {
        ui->tableViewC->setColumnWidth(2,531-12*(maxLineSize1+maxLineSize2));
    }
    else
    {
        ui->tableViewC->setColumnWidth(2,12*maxLineSize3);
    }
    ui->tableViewD->setColumnWidth(0,12*maxLineSize1);
    ui->tableViewD->setColumnWidth(1,12*maxLineSize2);
    if(12*(maxLineSize1+maxLineSize2+maxLineSize3)<531)
    {
        ui->tableViewD->setColumnWidth(2,531-12*(maxLineSize1+maxLineSize2));
    }
    else
    {
        ui->tableViewD->setColumnWidth(2,12*maxLineSize3);
    }
    setHeaders();
}
bool MainWindow::folderModeMerge()
{}

void MainWindow::setHeaders()
{
    modelC->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    modelC->setHeaderData(1, Qt::Horizontal, QObject::tr("Size"));
    modelC->setHeaderData(2, Qt::Horizontal, QObject::tr("Last Modified Time"));
    modelD->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    modelD->setHeaderData(1, Qt::Horizontal, QObject::tr("Size"));
    modelD->setHeaderData(2, Qt::Horizontal, QObject::tr("Last Modified Time"));
}

void MainWindow::on_buttonHelp_clicked()
{
    dialoghelp *dialogHelp = new dialoghelp();
    dialogHelp->show();

}

void MainWindow::on_buttonAbout_clicked()
{
    dialogabout *dialogAbout = new dialogabout();
    dialogAbout->show();
}
