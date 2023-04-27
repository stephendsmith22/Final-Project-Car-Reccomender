#include "Garage.h"
#include "Cars.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Garage::Garage(ifstream& file) {
	//get rid of the first line because it's just the column titles
	getline(file, tempString);
	while (garage.size() < 122144) {
		//read in id
		getline(file, tempString, ',');
		id = stoi(tempString);
		cout << id << " ";
		//price
		getline(file, tempString, ',');
		price = stoi(tempString);
		cout << price << " ";
		//scrap year and zipcode
		getline(file, tempString, ',');
		getline(file, tempString, ',');
		//read in mileage
		getline(file, tempString, ',');
		mileage = stoi(tempString);
		cout << mileage << " ";
		//read in make
		getline(file, make, ',');
		cout << make << " ";
		//read in model
		getline(file, model, ',');
		cout << model << " ";
		//read in year
		getline(file, tempString, ',');
		year = stoi(tempString);
		cout << year << " ";
		//scrap the rest
		getline(file, tempString);
		Cars tempCar(id, make, model, price, mileage, year);
		garage.push_back(tempCar);
		cout << ", Size of garage: " << garage.size() << endl;
	}
}