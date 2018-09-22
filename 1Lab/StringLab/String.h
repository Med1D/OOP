#ifndef STRING_H
#define STRING_H


class String
{
    public:
        String();
        String(char *str);
        virtual ~String();
        int Length();
        void Copy(const String& str);
        int Find(char ch, int start);
        int FindLast(char ch);
        String Substr(int index, int count);
        void Remove(int index, int count);
        void Insert(char *s,int index);
        void print();

    private:
        int str_length=0;
        char *str_adr;
};

#endif // STRING_H
