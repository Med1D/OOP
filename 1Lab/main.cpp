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


    String *stroka=new String(p_arr);//����������� ��� ������� ������(� �����������)
    dlina = stroka->Length();//���������� ���������� ����� ������
    printf("����� ������: %d", dlina);//����� ����� ������
    cout << endl << "-----------------------"<< endl;


    //---------------COPY FUNCTION

    //---------------FIND FUNCTION
    char sym;
    int start_pos=0;
    cout << "������� ������: ";
    cin >> sym;
    cout << "������� � ������ ������� ������: ";
    cin >> start_pos;
    while(start_pos>=stroka->Length() || start_pos<0)//���������� isdigit()
    {
        cout << "������� ������ ���������: ";
        cin >> start_pos;
    }
    int index_find = stroka->Find(sym,start_pos);
    printf("����� Find ����� %c � �������: %d", sym,index_find);
    //---------------






    delete stroka;
    delete [] p_arr;
    return 0;
}
