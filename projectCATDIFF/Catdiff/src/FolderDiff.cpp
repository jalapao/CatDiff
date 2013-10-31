#include "FolderDiff.h"
#include "numberPair.h"
FolderDiff::FolderDiff()
{
}

void FolderDiff::listToVector(QFileInfoList infoList, int tableViewID)
{
    if(tableViewID == 1)
    {
        vInfoC.clear();
        for(int i=0;i<infoList.length();i++)
        {
            vInfoC.push_back(infoList[i]);
        }
    }
    if(tableViewID == 2)
    {
        vInfoD.clear();
        for(int i=0;i<infoList.length();i++)
        {
            vInfoD.push_back(infoList[i]);
        }
    }
}

FolderDiff::~FolderDiff()
{}

bool FolderDiff::differVectors(std::vector<QFileInfo> *vInfoSame,std::vector<QFileInfo> *vInfoHalfSame,std::vector<QFileInfo> *vInfoNotSameC,std::vector<QFileInfo> *vInfoNotSameD)
{
    if(!checkVectors())
    {
        return false;}

    std::vector<bool> luckyFlagC;
    std::vector<bool> luckyFlagD;

    luckyFlagC.resize(vInfoC.size(),false);
    luckyFlagD.resize(vInfoD.size(),false);

    for(int i=0;i<vInfoC.size();i++)
    {
        for(int j=0;j<vInfoD.size();j++)
        {
            if(vInfoC[i].fileName() == vInfoD[j].fileName())
            {
                if(vInfoC[i].lastModified()==vInfoD[j].lastModified())
                {
                    vInfoSame->push_back(vInfoC[i]);
                }
                else
                {
                    vInfoHalfSame->push_back(vInfoC[i]);
                }
                luckyFlagC[i] = true;
                luckyFlagD[j] = true;
            }
            else
            {continue;}
        }
    }
    for(int i=0;i<luckyFlagC.size();i++)
    {
        if(!luckyFlagC[i])
        {
            vInfoNotSameC->push_back(vInfoC[i]);
        }
    }
    for(int i=0;i<luckyFlagD.size();i++)
    {
        if(!luckyFlagD[i])
        {
            vInfoNotSameD->push_back(vInfoD[i]);
        }
    }
    return true;
}

bool FolderDiff::checkVectors()
{
    if(vInfoC.empty()||vInfoD.empty())
    {return false;}
    else
    {return true;}
}
