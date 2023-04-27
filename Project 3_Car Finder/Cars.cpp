#include <iostream>
#include "Cars.h"

Cars& Cars::operator=(const Cars& c) {
	make = c.make;
	model = c.model;
	price = c.price;
	mileage = c.mileage;
	year = c.year;
	return *this;
}
