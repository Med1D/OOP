#include "CTwo.h"
#include <iostream>
CTwo::CTwo()
{
    s="";
    obj.Set_l(0);
    obj.Set_s("");
}

CTwo::CTwo(const CTwo &other)
{
    this->s=other.s;
    this->obj=other.obj;
}

CTwo& CTwo::operator=(const CTwo &other)
{
    this->s=other.s;
    this->obj=other.obj;
    return *this;
}

CTwo::CTwo(std::string s, COne &obj)
{
    this->s=s;
    this->obj=obj;
}

std::string CTwo::Get_s()
{
    return this->s;
}

void CTwo::Set_s(std::string s)
{
    this->s=s;
}

COne CTwo::Get_obj()
{
    return obj;
}

void CTwo::Set_obj(COne &obj)
{
    this->obj=obj;
}

void CTwo::print()
{
    std::cout << "#2 S: " << s << std::endl;
    obj.print();
}


CTwo::~CTwo()
{
    //dtor
}
