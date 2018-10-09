#include "CThree.h"
#include <stdio.h>
CThree::CThree():CTwo()
{
    length=0;
}

CThree::CThree(std::string s, COne& obj,int length): CTwo(s,obj)
{
    this->length=length;
}

CThree::CThree(const CThree & other): CTwo(other)
{
    this->length=other.length;
}

void CThree::Set_length(int length)
{
    this->length=length;
}

int CThree::Get_length()
{
    return length;
}

void CThree::print()
{
    printf("#3 LENGTH IS: %d\n", this->length);
    CTwo::print();
}



CThree::~CThree()
{
    //dtor
}
