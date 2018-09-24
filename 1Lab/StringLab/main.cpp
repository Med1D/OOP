#include <iostream>
#include <stdio.h>
#include "String.h"
using namespace std;

int main()
{
    char *p_arr=new char[50];
    char *p_arr2=new char[50];
    char *p_arr3 = new char[50];
    cout << "Please, enter first string: ";
    gets(p_arr);
    cout << "Please, enter copy-string: ";
    gets(p_arr2);
    cout << "Please, enter insert-string: ";
    gets(p_arr3);
    int dlina=0;
    cout << "-----------------------"<< endl;


    String *stroka=new String(p_arr);
    dlina = stroka->Length();
    printf("String's length: %d", dlina);
    cout << endl << "-----------------------" << endl;


    //---------------COPY FUNCTION
    String *stroka2=new String(p_arr2);
    stroka->Copy(*stroka2);
    cout << "Result of Copy method: ";
    stroka->print();
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------FIND FUNCTION
    char sym;
    int start_pos=0;
    cout << "Enter a char for Find method: ";
    cin >> sym;
    cout << "Enter an index for find method: ";
    cin >> start_pos;
    int index_find = stroka->Find(sym,start_pos);
    printf("Method Find find %c in index: %d", sym,index_find);
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------FINDLAST FUNCTION
    char sym1;
    cout << "Enter a char for Findlast method: ";
    cin >> sym1;
    int index_find_last=stroka->FindLast(sym1);
    printf("Method FindLast find last emergence %c in index: %d", sym1,index_find_last);
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------SUBSTR FUNCTION
    String *Sub_str = new String[50];
    int index_sub;
    int count_sub;
    cout << "Enter an index, where we will start use Substr method: ";
    cin >> index_sub;
    *Sub_str=stroka->Substr(index_sub,count_sub);
    printf("Substring by Substr method: ");
    Sub_str->print();
    delete [] Sub_str;
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------REMOVE FUNCTION
    int index_remove,count_remove;
    cout << "Enter an index for Remove method: ";
    cin >> index_remove;
    cout << "Enter length of remove string: ";
    cin >> count_remove;
    stroka->Remove(index_remove,count_remove);
    cout << "Result of Remove method: ";
    stroka->print();
    cout << endl << "-----------------------" << endl;

    //---------------INSERT FUNCTION
    int index_insert=0;
    cout << "Enter an index, before what we will use Insert method: ";
    cin >> index_insert;
    stroka->Insert(p_arr3,index_insert);
    cout << "Result of Insert method: ";
    stroka->print();
    cout << endl << "-----------------------" << endl;
    //---------------

    stroka->~String();
    stroka2->~String();
    delete [] p_arr;
    delete [] p_arr2;
    delete [] p_arr3;
    return 0;
}
