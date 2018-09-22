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

int String::FindLast(char ch)
{
    int i=str_length-1;
    while (str_adr[i]!=str_adr[0])
    {
        if (str_adr[i]==ch) {return i;}
        i--;
    }
    return -1;
}
