#include "String.h"
#include <iostream>
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

String::String(const String &other)
{
    this->str_length = other.str_length;
    this->str_adr = new char[other.str_length+1];
    String::Copy(other.str_adr);
}

String::~String()
{
    //dtor
}

int String::Length()
{
    return str_length;
}

void String::Copy(const String& str)
{
    str_length=str.str_length;
    delete [] str_adr;
    this->str_adr = new char[str_length+1];
    for(int i=0;i<str.str_length;i++)
    {
        this->str_adr[i]=str.str_adr[i];
    }
}

int String::Find(char &ch, int start)
{
    while(start>=this->Length() || start<0)
    {
        std::cout << "Enter index correctly: ";
        std::cin >> start;
    }
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
    while (str_adr[i]!=str_adr[-1])
    {
        if (str_adr[i]==ch) {return i;}
        i--;
    }
    return -1;
}

String String::Substr(int index,int count)//со
{
     while(index<0 || index>=this->Length())
    {
        std::cout << "Enter index correctly: ";
        std::cin >> index;
    }
    std::cout << "Enter length of substring: ";
    std::cin >> count;
    while(count>this->Length()-index || count<=0)
    {
        std::cout << "Enter length correctly: ";
        std::cin >> count;
    }
    char *buf = new char[str_length];
    int j=0;
    for( int i=index;i<index+count;i++)
    {
        buf[j]=str_adr[i];
        j++;
    }
    return buf;
}

void String::Remove(int index, int count)
{
    while(index<0 || index>=this->Length())
    {
        std::cout << "Enter an index correctly: ";
        std::cin >> index;
    }
    while(count<0 || count>this->Length()-index)
    {
        std::cout << "Enter length of remove string correctly: ";
        std::cin >> count;
    }
    char *buffer = new char[str_length+1];
    int j=0;
    for(int i=0;i<this->Length();i++)
    {
        if(i<index || i>=index+count)
        {
        buffer[j]=str_adr[i];
        j++;
        }
    }
    String::Copy(buffer);
    delete [] buffer;
}

void String::Insert(char *s, int index)
{
     while(index<0 || index>this->Length())
    {
        std::cout << "Enter an index correctly: ";
        std::cin >> index;
    }
    char *buffer = new char[50];
    int j=0;

    for(int i=0;i<this->Length();i++)
    {
        if(i==index)
        {
            int counter_while=i;
            if(index==0)
            {
                while(str_adr[j] != '\0')
                {
                buffer[j]=str_adr[j];
                j++;
                }
                j=0;
                while(s[j]!='\0')
                {
                str_adr[counter_while]=s[j];
                counter_while++;
                j++;
                str_length++;
                }
                while(*buffer!='\0')
                {
                str_adr[counter_while]=*buffer;
                counter_while++;
                buffer++;
            }
            break;
            }

            else
            {
            while(s[j] != '\0')
            {
                buffer[j]=str_adr[counter_while];
                str_adr[counter_while]=s[j];
                counter_while++;
                j++;
                str_length++;
            }
            while(*buffer!='\0')
            {
                str_adr[counter_while]=*buffer;
                counter_while++;
                buffer++;
            }
            break;
            }
        }
    }
    delete [] buffer;
}



void String::print()
{
    for(int i=0;i<this->Length();i++)
    {
        printf("%c" ,this->str_adr[i]);
    }
}
