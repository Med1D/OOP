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
    cout << "����������, ������� ������ ������: ";
    gets(p_arr);
    cout << "����������, ������� copy-������: ";
    gets(p_arr2);
    cout << "����������, ������� insert-������: ";
    gets(p_arr3);
    int dlina=0;
    cout << "-----------------------"<< endl;


    String *stroka=new String(p_arr);//����������� ��� ������� ������(� �����������)
    dlina = stroka->Length();//���������� ���������� ����� ������
    printf("����� ������: %d", dlina);//����� ����� ������
    cout << endl << "-----------------------" << endl;


    //---------------COPY FUNCTION
    String *stroka2=new String(p_arr2);
    stroka->Copy(*stroka2);
    cout << "�������� ������ Copy: ";
    stroka->print();
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------FIND FUNCTION
    char sym;
    int start_pos=0;
    cout << "������� ������: ";
    cin >> sym;
    cout << "������� � ������ ������� ������: ";
    cin >> start_pos;
    while(start_pos>=stroka->Length() || start_pos<0)
    {
        cout << "������� ������ ���������: ";
        cin >> start_pos;
    }
    int index_find = stroka->Find(sym,start_pos);
    printf("����� Find ����� %c � �������: %d", sym,index_find);
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------FINDLAST FUNCTION
    char sym1;
    cout << "������� ������: ";
    cin >> sym1;
    int index_find_last=stroka->FindLast(sym1);
    printf("����� FindLast ����� ��������� ��������� %c � �������: %d", sym1,index_find_last);
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------SUBSTR FUNCTION
    String *Sub_str = new String[50];
    int index_sub;
    int count_sub;
    cout << "������� ������, � �������� ����� ������ ��������� ������: ";
    cin >> index_sub;
     while(index_sub<0 || index_sub>=stroka->Length())
    {
        cout << "������� ������ ���������: ";
        cin >> index_sub;
    }
    cout << "������� �����, ���������� ���������: ";
    cin >> count_sub;
    while(count_sub>stroka->Length()-index_sub || count_sub<=0)
    {
        cout << "������� ����� ���������: ";
        cin >> count_sub;
    }
    *Sub_str=stroka->Substr(index_sub,count_sub);
    printf("���������� ������ ������� Substr: ");
    Sub_str->print();
    delete [] Sub_str;
    cout << endl << "-----------------------" << endl;
    //---------------

    //---------------REMOVE FUNCTION
    int index_remove,count_remove;
    cout << "������� ������: ";
    cin >> index_remove;
    while(index_remove<0 || index_remove>=stroka->Length())
    {
        cout << "������� ������ ���������: ";
        cin >> index_remove;
    }
    cout << "������� ����� ��������� ������: ";
    cin >> count_remove;
    while(count_remove<0 || count_remove>stroka->Length()-index_remove)
    {
        cout << "������� ����� ��������� ������ ���������: ";
        cin >> count_remove;
    }
    stroka->Remove(index_remove,count_remove);
    cout << "�������� ������ Remove: ";
    stroka->print();
    cout << endl << "-----------------------" << endl;

    //---------------INSERT FUNCTION
    int index_insert=0;
    cout << "������� ������, ����� ������� ����� ��������� ������ ������� Insert: ";
    cin >> index_insert;
    while(index_insert<0 || index_insert>stroka->Length())
    {
        cout << "������� ������ ���������: ";
        cin >> index_insert;
    }
    stroka->Insert(p_arr3,index_insert);
    cout << "��������� ���������� ������ Insert: ";
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
