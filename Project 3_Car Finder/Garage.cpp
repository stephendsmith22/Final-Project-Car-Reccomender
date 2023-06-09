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

void Garage::removeElements(int threshold, string sortingChoice){
	if (sortingChoice == "price") {
		int index = 0;
		vector<Cars> tempCars;
		while (garage[index].getPrice() <= threshold && index < garage.size()) {
			tempCars.push_back(garage[index]);
			index++;
		}
		garage = tempCars;
	}
	else if (sortingChoice == "mileage") {
		int index = 0;
		vector<Cars> tempCars;
		while (garage[index].getMileage() <= threshold && index < garage.size()) {
			tempCars.push_back(garage[index]);
			index++;
		}
		garage = tempCars;
	}
	else if (sortingChoice == "year") {
		int index = garage.size() - 1;
		vector<Cars> tempCars;
		while (garage[index].getYear() >= threshold && index > 0) {
			tempCars.push_back(garage[index]);
			index--;
		}
		garage = tempCars;
	}
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

			if (i < pivotIndex && j > pivotIndex) {
				swap(garage[i], garage[j]);
				i++;
				j--;
			}
		}

		return pivotIndex;
	}
	else if (sortingChoice == "mileage") {
		int pivot = garage[start].getMileage();

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (garage[i].getMileage() <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(garage[pivotIndex], garage[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (garage[i].getMileage() <= pivot)
				i++;

			while (garage[j].getMileage() > pivot)
				j--;

			if (i < pivotIndex && j > pivotIndex) {
				swap(garage[i], garage[j]);
				i++;
				j--;
			}
		}

		return pivotIndex;
	}
	else if (sortingChoice == "year") {
		int pivot = garage[start].getYear();

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (garage[i].getYear() <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(garage[pivotIndex], garage[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (garage[i].getYear() <= pivot)
				i++;

			while (garage[j].getYear() > pivot)
				j--;

			if (i < pivotIndex && j > pivotIndex) {
				swap(garage[i], garage[j]);
				i++;
				j--;
			}
		}

		return pivotIndex;
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

void Garage::merge(vector<Cars>& arr, int left, int mid, int right, string sortingChoice) {

	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<Cars> L;
	L.reserve(n1);

	vector<Cars> R;
	R.reserve(n2);

	for (int i = 0; i < n1; i++)
		L.push_back(garage.at(left + i));

	for (int j = 0; j < n2; j++)
		R.push_back(garage.at(mid + 1 + j));

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (sortingChoice == "price") {
			if (L[i].getPrice() <= R[j].getPrice()) {
				garage[k] = L[i];
				i++;
			}
			else {
				garage[k] = R[j];
				j++;
			}
		}
		else if (sortingChoice == "mileage") {
			if (L[i].getMileage() <= R[j].getMileage()) {
				garage[k] = L[i];
				i++;
			}
			else {
				garage[k] = R[j];
				j++;
			}
		}
		else if (sortingChoice == "year") {
			if (L[i].getYear() <= R[j].getYear()) {
				garage[k] = L[i];
				i++;
			}
			else {
				garage[k] = R[j];
				j++;
			}
		}
		k++;
	}

	while (i < n1) {
		garage[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		garage[k] = R[j];
		j++;
		k++;
	}

}


void Garage::mergeSort(vector<Cars>& arr, int left, int right, string sortingChoice) {

	if (left < right) {

		//m is the point where the array is divided into two subarrays
		int mid = left + (right - left) / 2;
		mergeSort(garage, left, mid, sortingChoice);
		mergeSort(garage, mid + 1, right, sortingChoice);

		//Merge the sorted subarrays
		merge(garage, left, mid, right, sortingChoice);
	}
}