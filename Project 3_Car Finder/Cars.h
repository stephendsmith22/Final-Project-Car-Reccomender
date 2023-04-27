#include <iostream>
#pragma once

Class Cars{

};
sf::RectangleShape textBox() {

    // Set up the rectangle
    sf::RectangleShape rectangle(sf::Vector2f(200, 50));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);

    return rectangle;
}

struct userInput {

    int maxPrice;
    int mileage;
    int year;
    std::string make;
    std::string model;

};

struct fileStruct {

    int id;
    int price;
    int mileage;
    int year;
    std::string make;
    std::string model;
};

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void readFile() {

    std::ifstream fin("C:/Users/elilo/source/repos/Final-Project-Car-Reccomender/Project 3_Car Finder/SimpleCars_csv.csv");
    std::string line;
    if (fin.is_open()) {

        while (getline(fin, line, ',')) {
            /*
            std::istringstream iss(line);
            std::vector<std::string> fields;
            std::string field;

            // Split the line into fields using comma as a delimiter
            while (getline(iss, field, ',')) {
                fields.push_back(field);
            }

            // Extract the desired columns (in this case, the first and third columns)
            std::string col1 = fields[0];
            std::string col3 = fields[2];

            // Print the extracted columns
            std::cout << "Column 1: " << col1 << std::endl;
            std::cout << "Column 3: " << col3 << std::endl;
            */

            std::cout << line << std::endl;
        }
    }

    fin.close();
}