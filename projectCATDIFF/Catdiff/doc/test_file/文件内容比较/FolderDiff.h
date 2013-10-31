#ifndef FOLDERDIFF_H
#define FOLDERDIFF_H

#include<QFileInfo>
#include<vector>

class FolderDiff
{
public:
    FolderDiff();
    void listToVector(QFileInfoList infoList, int tableViewID);
    ~FolderDiff();

private:
    std::vector<QFileInfo> vInfoC;
    std::vector<QFileInfo> vInfoD;

};


#endif // FOLDERDIFF_H
