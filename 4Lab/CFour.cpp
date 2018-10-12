#include "CFour.h"
#include <stdio.h>
CFour::CFour():CThree(),id_(0)
{
    //ctor
}

CFour::CFour(std::string s, COne& obj,int length,int id):CThree(s,obj,length),id_(id)
{

}

CFour::CFour(const CFour & other):CThree(other)
{
this->id_=other.id_;
}

void CFour::Set_id(int id)
{
    this->id_=id;
}

int CFour::Get_id()
{
    return this->id_;
}

void CFour::print()
{
    printf("#4 ID IS: %d\n", this->id_);
    CThree::print();
}

CFour::~CFour()
{
    //dtor
}
