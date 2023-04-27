#include <iostream>
#include <fstream>
#pragma once

using namespace std;

class Cars {
    string make, model;
    int id, price, mileage, year;
public:
    Cars(int id, string make, string model, int price, int mileage, int year)
        : id(id), make(make), model(model), year(year), price(price), mileage(mileage) {}
};