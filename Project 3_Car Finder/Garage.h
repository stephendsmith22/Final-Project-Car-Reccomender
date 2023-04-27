#include <iostream>
#include "Cars.h"
#include <vector> 
#include <fstream>

using namespace std;

class Garage {
	string make, tempString;
	int id, price, mileage, year;
	vector<Cars> garage;
public:
	Garage(ifstream file);
	void mergeSort();
	void merge();
};