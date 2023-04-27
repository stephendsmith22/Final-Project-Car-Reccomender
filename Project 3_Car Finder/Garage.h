#include <iostream>
#include "Cars.h"
#include <vector> 
#include <fstream>

using namespace std;

class Garage {
	string make, model, tempString;
	int id, price, mileage, year;
public:
    vector<Cars> garage;
	Garage(ifstream& file, string make, string model);
    void swap(Cars& a, Cars& b);
	void mergeSort();
	void merge();
    int partition(vector<Cars> map_garage, int start, int end, string sortingChoice);
    void quickSort(vector<Cars> map_garage, int start, int end, string sortingChoice);
};

