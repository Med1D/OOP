#include "String.h"

String::String()
{
    str_length=0;
}

String::String(char *str)
{
    while(*str != '\0')
    {
        str_length++;
        str++;
    }
}


String::~String()
{
    //dtor
}

int String::Length()
{
    return str_length;
}

//COPY

int String::Find(char ch, int start)
{
    int result=-1;
    while(*this!='/0')
    {
        if(*(this)==ch) {result=*(p_arr+start);break;}
        this++;
    }
    return result;
}
