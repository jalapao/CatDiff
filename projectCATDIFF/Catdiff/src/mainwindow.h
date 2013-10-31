#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QPixmap>
#include <QPainter>
#include <QWidget>
#include <vector>
#include <QObject>
#include <QBitmap>
#include "algoStructure.h"
#include "filters.h"
#include <QFileInfoList>
#include <QDateTime>
#include "FolderDiff.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openButton_clicked(int buttonID);

    void on_openButtonA_clicked();
    void on_openButtonB_clicked();

    bool on_buttonDiffer_clicked();

    bool on_buttonMerge_clicked();

    void on_buttonMode_clicked();

    void on_buttonHelp_clicked();

    void on_buttonAbout_clicked();

private:
    void showTextInBrowser(QString fileSelected, int ButtonID);
    void add_item_to_tableview(QString countOfLinesString, QString textLine,int ButtonID);

    int  max_line_size(int maxLineSize, QString textLine);  //resize the width
    void set_columns_width(int maxLineSize, int who);

    void drawGreenTextOnLeftAndBlankOnRight(QString content, int lineNumber);
    void drawRedTextOnRightAndBlankOnLeft(QString content, int lineNumber);
    void drawWhiteTextOnBothSides(QString content, int lineNumberA, int lineNumberB);
    void drawSomething(QString plusOrMinus, QColor greenOrRed,int AorB, QString content, int lineNumber);

    void reshowTextInTableView();
    void connetScrollBars();
    void disconnetScrollBars();

    void clearThingsOfFileMode();
    void clearThingsOfFolderMode();
    void showSimilarity();

//folder mode:

    bool folderModeDiffer();
    void folderModeOpen(int buttonID);
    bool folderModeMerge();
    void showDirFilesInTableView(QFileInfoList listOfFiles, int tableViewID);
    void setHeaders();


    Ui::MainWindow *ui;
    //void paintEvent(QPaintEvent *event);

    std::vector<QString> bufferTextVectorA;
    std::vector<QString> bufferTextVectorB;
    std::vector<AlgoStructure> longestCommonSubsequence;

    int countOfLinesA;
    int countOfLinesB;
    QStandardItemModel *modelA = new QStandardItemModel;
    QStandardItemModel *modelB = new QStandardItemModel;
    QStandardItemModel *modelC = new QStandardItemModel;
    QStandardItemModel *modelD = new QStandardItemModel;

    QStandardItemModel *modelMerge = new QStandardItemModel;
    std::vector<QString> bufferTextVectorMerge;

    FolderDiff *folderDiff;
};

#endif // MAINWINDOW_H
