#include "Apartment.h"
#include <stdio.h>
#include <iostream>
Apartment::Apartment():n(0),area(0),cost(0),address("")
{
    //ctor
}

Apartment::Apartment(int n,float area,float cost,std::string address): n(n), area(area), cost(cost), address(address)
{

}

Apartment::Apartment(const Apartment& other)
{
    this->n=other.n;
    this->area=other.area;
    this->cost=other.cost;
    this->address=other.address;
}
Apartment::~Apartment()
{
    //dtor
}

void Apartment::SetNumberOfRooms(int n)
{
    this->n=n;
}

int Apartment::GetNumberOfRooms()
{
    return this->n;
}

void Apartment::SetArea(float area)
{
    this->area=area;
}

float Apartment::GetArea()
{
    return area;
}

void Apartment::SetCost(float cost)
{
    this->cost=cost;
}

float Apartment::GetCost()
{
    return cost;
}

void Apartment::SetAddress(std::string address)
{
    this->address=address;
}

std::string Apartment::GetAddress()
{
    return address;
}

void Apartment::print()
{
    printf("%d - %.1f - %.2f - %s\n",n,area,cost,address.c_str());

}
