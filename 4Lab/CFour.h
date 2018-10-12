#ifndef CFOUR_H
#define CFOUR_H
#include "CThree.h"

class CFour:public CThree
{
    public:
        CFour();
        CFour(std::string s, COne& obj,int length,int id);
        CFour(const CFour & other);
        void Set_id(int id);
        int Get_id();
        virtual void print();
        virtual ~CFour();

    protected:

    private:
        int id_;
};

#endif // CFOUR_H
