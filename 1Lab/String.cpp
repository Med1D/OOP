#include "String.h"
String::String()
{
    str_length=0;
}

String::String(char *str)
{
    str_adr=str;
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
    int i=0;
    while(str_adr[start+i]!='\0')
    {
        if(str_adr[start+i]==ch) {return start+i;}
        i++;
    }
    return -1;
}
