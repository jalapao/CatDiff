#ifndef ALGOSTRUCTURE_H
#define ALGOSTRUCTURE_H



class AlgoStructure{

 public:
    AlgoStructure();
    AlgoStructure(int longestSequence, int fatherX, int fatherY, int mx, int my);
    void set(int ls,int fx, int fy, int mx, int my);


    AlgoStructure &operator= (const AlgoStructure &);

 private:
    int longestSequence;
    int fatherX;
    int fatherY;
    int myX;
    int myY;
    //int whoseAddition;

 public:
    int getFatherX()const
    {
        return fatherX;
    }
    int getFatherY()const
    {
        return fatherY;
    }
    int getLongestSequence()const
    {
        return longestSequence;
    }

    int getMyX() const
    {
        return myX;
    }
    int getMyY() const
    {
        return myY;
    }

    void setFatherX(int x)
    {
        fatherX = x;
    }

    void setFatherY(int y)
    {
        fatherY = y;
    }

    void setLongestSequence(int ls)
    {
        longestSequence = ls;
    }

    void setMyX(int mx)
    {
        myX = mx;
    }
    void setMyY(int my)
    {
        myY = my;
    }
};

#endif // ALGOSTRUCTURE_H
