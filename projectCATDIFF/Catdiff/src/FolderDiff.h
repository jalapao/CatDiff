#ifndef FOLDERDIFF_H
#define FOLDERDIFF_H

#include<QFileInfo>
#include<vector>
#include"numberPair.h"
#include<QDateTime>
#include<QMessageBox>

class FolderDiff
{
public:
    FolderDiff();
    void listToVector(QFileInfoList infoList, int tableViewID);
    bool differVectors(std::vector<QFileInfo> *vInfoSame,std::vector<QFileInfo> *vInfoHalfSame,std::vector<QFileInfo> *vInfoNotSameC,std::vector<QFileInfo> *vInfoNotSameD);
    bool checkVectors();

    ~FolderDiff();

private:
    std::vector<QFileInfo> vInfoC;
    std::vector<QFileInfo> vInfoD;
    std::vector<numberPair> vNumberPairSame;
    std::vector<numberPair> vNumberPairHalfSame;

};


#endif // FOLDERDIFF_H
