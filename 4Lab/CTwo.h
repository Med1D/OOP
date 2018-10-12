#ifndef CTWO_H
#define CTWO_H
#include <string>
#include "COne.h"

class CTwo
{
    public:
        CTwo();
        virtual ~CTwo();
        CTwo(const CTwo &other);
        CTwo& operator=(const CTwo &other);
        CTwo(std::string s, COne &obj);
        std::string Get_s();
        void Set_s(std::string s);
        COne Get_obj();
        void Set_obj(COne &obj);
        virtual void print();

    protected:

    private:
        std::string s;
        COne obj;
};

#endif // CTWO_H
