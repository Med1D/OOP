#ifndef CONE_H
#define CONE_H
#include <string>
class COne
{
    public:
        COne();
        virtual ~COne();
        COne(const COne &other);
        COne& operator =(const COne &other);
        COne(long l,std::string s);
        long Get_l();
        void Set_l(long l);
        std::string Get_s();
        void Set_s(std::string s);
        void print();
    protected:

    private:
        long l;
        std::string s;
};

#endif // CONE_H
