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
    while (str_adr[i]!=str_adr[-1])
    {
        if (str_adr[i]==ch) {return i;}
        i--;
    }
    return -1;
}

String String::Substr(int index,int count)//со
{
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
