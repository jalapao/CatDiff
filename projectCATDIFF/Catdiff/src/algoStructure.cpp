#include "algoStructure.h"

AlgoStructure::AlgoStructure()
{
}

AlgoStructure::AlgoStructure(int ls, int x, int y, int mx, int my)
{
    longestSequence = ls;
    fatherX = x;
    fatherY = y;
    myX = mx;
    myY = my;
}

void AlgoStructure::set(int ls, int fx, int fy, int mx, int my)
{
    longestSequence = ls;
    fatherX = fx;
    fatherY = fy;
    myX = mx;
    myY = my;
}

 AlgoStructure &AlgoStructure::operator= (const AlgoStructure &foo)
 {
     this->setFatherX(foo.getFatherX());
     this->setFatherY(foo.getFatherY());
     this->setLongestSequence(foo.getLongestSequence());
     this->setMyX(foo.getMyX());
     this->setMyY(foo.getMyY());
     return *this;
 }
