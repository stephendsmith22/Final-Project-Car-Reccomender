#include <iostream>
#include "Cars.h"
#include <vector> 
#include <fstream>

using namespace std;

class Garage {
	string make, model, tempString;
	int id, price, mileage, year;
	void swap(Cars& a, Cars& b);
public:
    vector<Cars> garage;
	Garage(ifstream& file, string make, string model);
	void removeElements(int threshold, string sortingChoice);
	void mergeSort(vector<Cars>& arr, int left, int right, string sortingChoice);
	void merge(vector<Cars>& arr, int left, int mid, int right, string sortingChoice);
    int partition(vector<Cars> map_garage, int start, int end, string sortingChoice);
    void quickSort(vector<Cars> map_garage, int start, int end, string sortingChoice);
};

