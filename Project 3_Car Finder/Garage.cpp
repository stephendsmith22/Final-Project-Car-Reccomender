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
		//scrap year and zipcode
		getline(file, tempString, ',');
		getline(file, tempString, ',');
		//read in mileage
		getline(file, tempString, ',');
		mileage = stoi(tempString);
		//read in make
		getline(file, make, ',');	
		//read in model
		getline(file, model, ',');
		//read in year
		getline(file, tempString, ',');
		year = stoi(tempString);
		//scrap the rest
		getline(file, tempString);
		cout << ", Size of garage: " << garage.size() << endl;
		
	}
}