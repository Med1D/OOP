#include "COne.h"
#include <iostream>
COne::COne()
{
    l=0;
    s="";
}

COne::COne(const COne &other)
{
    this->l=other.l;
    this->s=other.s;
}
COne::COne(long l, std::string s)
{
    this->l=l;
    this->s=s;
}

COne &COne::operator=(const COne &other)
{
    this->l=other.l;
    this->s=other.s;
    return *this;
}

long COne::Get_l()
{
    return this->l;
}

void COne::Set_l(long l)
{
    this->l=l;
}

std::string COne::Get_s()
{
    return this->s;
}

void COne::Set_s(std::string s)
{
    this->s=s;
}

void COne::print()
{
    std::cout << "#1 L: " << l << std::endl;
    std::cout << "#1 S: " << s << std::endl;
}
COne::~COne()
{
    //dtor
}
