#include <iostream>
#include <fstream>
#pragma once

using namespace std;

class Cars {
    string make, model;
    int price, mileage, year;
public:
    Cars(string make, string model, int price, int mileage, int year)
        : make(make), model(model), year(year), price(price), mileage(mileage) {}
    int getPrice() { return price; }
    int getMileage() { return mileage; }
    int getYear() { return year; }
};