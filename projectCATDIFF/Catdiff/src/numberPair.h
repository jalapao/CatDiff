#ifndef NUMBERPAIR_H
#define NUMBERPAIR_H

class numberPair
{
private:
    int x;
    int y;
public:
    numberPair(int a,int b)
    {
      x = a;
      y = b;
    }

    numberPair()
    {}

    void setNumberPair(int a, int b)
    {
        x=a;
        y=b;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

};
#endif // NUMBERPAIR_H
