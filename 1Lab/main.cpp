#include <iostream>
#include <stdio.h>
#include "String.h"
using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    cout << "Please, enter a string: ";
    char *p_arr=new char[50];
    gets(p_arr);
    int dlina=0;
    cout << "-----------------------"<< endl;


    String *stroka=new String(p_arr);//Конструктор для объекта строка(с параметрами)
    dlina = stroka->Length();//Присвоение переменной длины строки
    printf("Длина строки: %d", dlina);//Вывод длины строки
    cout << endl << "-----------------------"<< endl;


    //---------------COPY FUNCTION

    //---------------FIND FUNCTION
    char sym;
    int start_pos=0;
    cout << "Введите символ: ";
    cin >> sym;
    cout << "Введите с какого индекса искать: ";
    cin >> start_pos;
    while(start_pos>=stroka->Length() || start_pos<0)//Доработать isdigit()
    {
        cout << "Введите индекс корректно: ";
        cin >> start_pos;
    }
    int index_find = stroka->Find(sym,start_pos);
    printf("Метод Find нашёл %c в позиции: %d", sym,index_find);
    //---------------






    delete stroka;
    delete [] p_arr;
    return 0;
}
