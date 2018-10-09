#include <iostream>
#include "String.h"
#include <stdio.h>
using namespace std;

int main()
{
    //---------Constructors
    String str1;
    cout << "Length of str1: " << str1.Length() << endl;
    cout << "str1: ";
    str1.print();
    cout << endl << "---------------" << endl;
    //---------
    String str2("Example of code");
    cout << "Length of str2: " << str2.Length() << endl;
    cout << "str2: ";
    str2.print();
    cout << endl << "---------------" << endl;
    //---------
    String str3(str2);
    cout << "Length of str3: " << str3.Length() << endl;
    cout << "str3: ";
    str3.print();
    cout << endl << "---------------" << endl;
    //---------

    //---------Find
    char sym;
    int start_pos;
    cout << "Enter a char for Find method: ";
    cin >> sym;
    cout << "Enter an index for Find method: ";
    cin >> start_pos;
    cout << "Method Find finds " << sym << " in index: " << str3.Find(sym,start_pos);
    cout << endl << "---------------" << endl;
    //---------

    //---------FindLast
    char sym1;
    cout << "Enter a char for Findlast method: ";
    cin >> sym1;
    cout << "Method FindLast finds last emergence " << sym1 << " in index: " << str3.FindLast(sym1);
    cout << endl << "---------------" << endl;
    //---------

    //---------Substr
    int index_sub;
    int count_sub;
    cout << "Enter an index, where we will start use Substr method: ";
    cin >> index_sub;
    cout << "Enter length of substring: ";
    cin >> count_sub;
    String sub_str=str3.Substr(index_sub,count_sub);
    cout << "Substring by Substr method: ";
    sub_str.print();
    cout << endl << "---------------" << endl;
    //---------

    //---------Remove
    int index_remove;
    int count_remove;
    cout << "Enter an index for Remove method: ";
    cin >> index_remove;
    cout << "Enter length of remove string: ";
    cin >> count_remove;
    str3.Remove(index_remove,count_remove);
    cout << "Result of Remove method: ";
    str3.print();
    cout << endl << "---------------" << endl;
    //---------

    //---------Insert
    int index_insert;
    cout << "Enter an index, before what we will use Insert method: ";
    cin >> index_insert;
    str3.Insert("33333",index_insert);
    cout << "Result of Insert method: ";
    str3.print();
    cout << endl << "---------------" << endl;
    //---------

    str1.~String();
    str2.~String();
    str3.~String();
    return 0;
}
