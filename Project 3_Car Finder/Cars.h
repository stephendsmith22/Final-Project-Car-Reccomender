#include <iostream>
#include <fstream>
#pragma once

using namespace std;

class Cars {
    string make;
    int id, price, mileage, year;
public:
    Cars(int id, string make, int price, int mileage, int year)
        : id(id), make(make), year(year), price(price), mileage(mileage) {}
};