#include <iostream>
#include <stdio.h>
#include "String.h"
using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    char *p_arr=new char[50];
    char *p_arr2=new char[50];
    char *p_arr3 = new char[50];
    cout << "Пожалуйста, введите первую строку: ";
    gets(p_arr);
    cout << "Пожалуйста, введите copy-строку: ";
    gets(p_arr2);
    cout << "Пожалуйста, введите insert-строку: ";
    gets(p_arr3);
    int dlina=0;
    cout << "-----------------------"<< endl;


    String *stroka=new String(p_arr);//Конструктор для объекта строка(с параметрами)
    dlina = stroka->Length();//Присвоение переменной длины строки
    printf("Длина строки: %d", dlina);//Вывод длины строки
    cout << endl << "-----------------------" << endl;


    //---------------COPY FUNCTION
    String *stroka2=new String(p_arr2);
    stroka->Copy(*stroka2);
    cout << "Рузльтат метода Copy: ";
    stroka->print();
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------FIND FUNCTION
    char sym;
    int start_pos=0;
    cout << "Введите символ: ";
    cin >> sym;
    cout << "Введите с какого индекса искать: ";
    cin >> start_pos;
    while(start_pos>=stroka->Length() || start_pos<0)
    {
        cout << "Введите индекс корректно: ";
        cin >> start_pos;
    }
    int index_find = stroka->Find(sym,start_pos);
    printf("Метод Find нашёл %c в позиции: %d", sym,index_find);
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------FINDLAST FUNCTION
    char sym1;
    cout << "Введите символ: ";
    cin >> sym1;
    int index_find_last=stroka->FindLast(sym1);
    printf("Метод FindLast нашёл последнее вхождение %c в позиции: %d", sym1,index_find_last);
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------SUBSTR FUNCTION
    String *Sub_str = new String[50];
    int index_sub;
    int count_sub;
    cout << "Введите индекс, с которого будет начато выделение строки: ";
    cin >> index_sub;
     while(index_sub<0 || index_sub>=stroka->Length())
    {
        cout << "Введите индекс корректно: ";
        cin >> index_sub;
    }
    cout << "Введите длину, выделяемой подстроки: ";
    cin >> count_sub;
    while(count_sub>stroka->Length()-index_sub || count_sub<=0)
    {
        cout << "Введите длину корректно: ";
        cin >> count_sub;
    }
    *Sub_str=stroka->Substr(index_sub,count_sub);
    printf("Выделенная строка методом Substr: ");
    Sub_str->print();
    delete [] Sub_str;
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------REMOVE FUNCTION
    int index_remove,count_remove;
    cout << "Введите индекс: ";
    cin >> index_remove;
    while(index_remove<0 || index_remove>=stroka->Length())
    {
        cout << "Введите индекс корректно: ";
        cin >> index_remove;
    }
    cout << "Введите длину удаляемой строки: ";
    cin >> count_remove;
    while(count_remove<0 || count_remove>stroka->Length()-index_remove)
    {
        cout << "Введите длину удаляемой строки корректно: ";
        cin >> count_remove;
    }
    stroka->Remove(index_remove,count_remove);
    cout << "Рузльтат метода Remove: ";
    stroka->print();
    cout << endl << "-----------------------" << endl;

    //---------------INSERT FUNCTION
    int index_insert=0;
    cout << "Введите индекс, перед которым будем вставлена строка методом Insert: ";
    cin >> index_insert;
    while(index_insert<0 || index_insert>stroka->Length())
    {
        cout << "Введите индекс корректно: ";
        cin >> index_insert;
    }
    stroka->Insert(p_arr3,index_insert);
    cout << "Результат выполнения метода Insert: ";
    stroka->print();
    cout << endl << "-----------------------" << endl;
    //---------------


    delete stroka;
    delete [] p_arr;
    delete stroka2;
    delete [] p_arr2;
    delete [] p_arr3;
    return 0;
}
