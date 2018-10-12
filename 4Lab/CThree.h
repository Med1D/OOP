#ifndef CTHREE_H
#define CTHREE_H
#include <string>
#include "CTwo.h"

class CThree:public CTwo
{
    public:
        CThree();
        CThree(std::string s,COne& obj,int length);
        CThree(const CThree & other);
        void Set_length(int length);
        int Get_length();
        virtual void print();
        virtual ~CThree();

    protected:

    private:
        int length;
};

#endif // CTHREE_H
