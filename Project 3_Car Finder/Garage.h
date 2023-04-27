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
	Garage(ifstream& file);
	void mergeSort();
	void merge();
};



/*int partition(std::vector<int>& arr, int low, int high){

    //Select the pivot element
    int pivot = arr[low];
    int up = low, down = high;

    while(up < down) {

        for(int j = up; j < high; j++) {

            if(arr[up] > pivot) {
                break;
            }
            up++;
        }

        for(int j = high; j > low; j--) {

            if(arr[down] < pivot) {
                break;
            }
            down--;
        }

        if(up < down) {
            std::swap(arr[up], arr[down]);
        }

    }

    std::swap(arr[low], arr[down]);
    return down;
}

void quickSort(std::vector<int> & arr, int low, int high) {

    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot -1);
        quickSort(arr, pivot +1, high);
    }
}*/


/*
void mergeSort(std::vector<int>& arr, int left, int right) {

    if (left < right) {

        //m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        //Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {

    //Create x <= arr[left..mid] & y <- arr[mid.. right
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int X[n1], Y[n2]; //TODO::Figure this out

    for (int i = 0; i < n1; i++) {
        X[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Y[j] = arr[mid + 1 + j];
    }

    //Merge the arrays X and Y into arr
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (X[i] <= Y[j]) {
            arr[k] = X[i];
            i++;
        }
        else {
            arr[k] = Y[j];
            j++;
        }
        k++;
    }

    //When we run out of elements in either X or Y append the remaining elements
    while (i < n1) {
        arr[k] = X[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Y[j];
        j++;
        k++;
    }

}
*/