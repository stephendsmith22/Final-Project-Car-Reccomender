#include "Garage.h"
#include "Cars.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Garage::Garage(ifstream& file, string make, string model) {
	//get rid of the first line because it's just the column titles
	getline(file, tempString);
	while (file.is_open()) {
		//read in id, if our tempString is blank, then we have reached the end of the file
		getline(file, tempString, ',');
		if (tempString.size() == 0)
			break;
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
		getline(file, this->make, ',');
		//read in model
		getline(file, this->model, ',');
		//read in year
		getline(file, tempString, ',');
		year = stoi(tempString);
		//scrap the rest
		getline(file, tempString);
		if (this->make == make && this->model == model) {
			Cars tempCar(this->make, this->model, price, mileage, year);
			garage.push_back(tempCar);
		}

	}

}

void Garage::swap(Cars& a, Cars& b){
	Cars tempCar = a;
	a = b;
	b = tempCar;
}

int Garage::partition(vector<Cars> map_garage, int start, int end, string sortingChoice){
	if (sortingChoice == "price") {

		int pivot = garage[start].getPrice();

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (garage[i].getPrice() <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(garage[pivotIndex], garage[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (garage[i].getPrice() <= pivot)
				i++;

			while (garage[j].getPrice() > pivot)
				j--;

			if (i < pivotIndex && j > pivotIndex)
				swap(garage[i++], garage[j--]);
		}

		return pivotIndex;
	}
	else if (sortingChoice == "mileage") {

	}
	else if (sortingChoice == "year") {

	}
}

void Garage::quickSort(vector<Cars> map_garage, int start, int end, string sortingChoice){
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(garage, start, end, sortingChoice);

	// Sorting the left part
	quickSort(garage, start, p - 1, sortingChoice);

	// Sorting the right part
	quickSort(garage, p + 1, end, sortingChoice);
}
