#include "Garage.h"
#include "Cars.h"
#include <fstream>
#include <iostream>
#include <string>
#include <map>

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
			garage[id] = tempCar;
		}

	}

}

int Garage::partition(map<int, Cars> map_garage, int start, int end, string sortingChoice){
	if (sortingChoice == "price") {
		int pivot = garage[start].getPrice();

		int count = 0;
		auto iter
		for (auto i = start + 1; i <= end; i++) {
			if (garage[i].getPrice() <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(garage[pivotIndex].getPrice(), garage[start].getPrice());

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (garage[i].getPrice() <= pivot) {
				i++;
			}

			while (garage[j].getPrice() > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(garage[i++].getPrice(), garage[j--].getPrice());
			}
		}

		return pivotIndex;
	}
	else if (sortingChoice == "mileage") {

	}
	else if (sortingChoice == "year") {

	}
}

void Garage::quickSort(map<int, Cars> map_garage, int start, int end, string sortingChoice){
	if (sortingChoice == "price") {
		// base case
		if (start >= end)
			return;

		// partitioning the array
		int p = partition(garage, start, end, "price");

		// Sorting the left part
		quickSort(garage, start, p - 1, "price");

		// Sorting the right part
		quickSort(garage, p + 1, end, "price");
	}
	else if (sortingChoice == "mileage") {

	}
	else if (sortingChoice == "year") {

	}
	else
		cout << "Invalid sorting choice, cannot perform sort.\n";
}
