#ifndef APARTMENT_H
#define APARTMENT_H
#include <string>

class Apartment
{
    public:
        Apartment();
        Apartment(int n,float area,float cost,std::string address);
        Apartment(const Apartment& other);
        virtual ~Apartment();

        void SetNumberOfRooms(int n);
        int GetNumberOfRooms();
        void SetArea(float area);
        float GetArea();
        void SetCost(float cost);
        float GetCost();
        void SetAddress(std::string address);
        std::string GetAddress();
        void print();

    protected:

    private:
        int n;
        float area;
        float cost;
        std::string address;
};

#endif // APARTMENT_H
