#include "Garage.h"
#include "Cars.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Garage::Garage(ifstream& file, string makeInput, string modelInput, int maxPrice, int maxMileage, int yearInput) {
	//get rid of the first line because it's just the column titles
	getline(file, tempString);
	int test = 0;
	while (garage.size() < 122142) {
		
		int count = 0;
		//read in id
		getline(file, tempString, ',');
		id = stoi(tempString);
		//price
		getline(file, tempString, ',');
		price = stoi(tempString);
		if (price < maxPrice) {
			count++;
		}
		//scrap year and zipcode
		getline(file, tempString, ',');
		getline(file, tempString, ',');

		//read in mileage
		getline(file, tempString, ',');
		mileage = stoi(tempString);
		if (mileage < maxMileage) {
			count++;
		}
		
		//read in make
		getline(file, make, ',');
		if (make == makeInput) {
			count++;
		}
		
		//read in model
		getline(file, model, ',');
		if (model == modelInput) {
			count++;
		}
		//read in year
		getline(file, tempString, ',');
		year = stoi(tempString);
		if (year >= yearInput) {
			count++;
		}
		
		//scrap the rest
		getline(file, tempString);

		if (count == 5) {
			Cars tempCar(id, make, model, price, mileage, year);
			garage.push_back(tempCar);
		}

		cout << ", Size of garage: " << garage.size() << endl;
		cout << "Test= " << test << endl;
		test++;
		
	}
}