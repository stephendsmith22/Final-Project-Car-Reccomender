#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include "Cars.h"
#include "Garage.h"

using namespace std;

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


int main() {
    userInput userInput;
    ifstream file("used_car_sales_csv.csv");


    sf::RenderWindow window(sf::VideoMode(800, 500), "Car determiner 3,000");
    //window.setFramerateLimit(60);

    //Font
    sf::Font font;
    font.loadFromFile("arial.ttf");

    //==========Set Up text box, text, and inputs for car make==========
    sf::RectangleShape carMakeRectangle = textBox();

    //Hold text for car make
    sf::Text carMakeText;
    carMakeText.setFont(font);
    carMakeText.setCharacterSize(24);
    carMakeText.setFillColor(sf::Color::Black);
    carMakeText.setString("");

    //Car make Heading
    sf::Text makeHeading("Car Make", font, 36);
    makeHeading.setFillColor(sf::Color::Blue);


    //==========Set up text, box, text, and inputs for car model==========
    sf::RectangleShape carModelRectangle = textBox();

    //Hold text for car model
    sf::Text carModelText;
    carModelText.setFont(font);
    carModelText.setCharacterSize(24);
    carModelText.setFillColor(sf::Color::Black);
    carModelText.setString("");

    //Car model Heading
    sf::Text carModelHeading("Car Model", font, 36);
    carModelHeading.setFillColor(sf::Color::Blue);


    //==========Set up text, box, text, and inputs for max price==========
    sf::RectangleShape maxPriceRectangle = textBox();

    //Hold text for max price
    sf::Text maxPriceText;
    maxPriceText.setFont(font);
    maxPriceText.setCharacterSize(24);
    maxPriceText.setFillColor(sf::Color::Black);
    maxPriceText.setString("");

    //Max price Heading
    sf::Text maxPriceHeading("Max Price", font, 36);
    maxPriceHeading.setFillColor(sf::Color::Blue);


    //==========Set up text, box, text, and inputs for max mileage==========
    sf::RectangleShape maxMileageRectangle = textBox();

    //Hold text for max mileage
    sf::Text maxMileageText;
    maxMileageText.setFont(font);
    maxMileageText.setCharacterSize(24);
    maxMileageText.setFillColor(sf::Color::Black);
    maxMileageText.setString("");

    //Max milage Heading
    sf::Text maxMileageHeading("Max Mileage", font, 36);
    maxMileageHeading.setFillColor(sf::Color::Blue);


    //==========Set up text, box, text, and inputs for year==========
    sf::RectangleShape yearRectangle = textBox();

    //Hold text for year
    sf::Text yearText;
    yearText.setFont(font);
    yearText.setCharacterSize(24);
    yearText.setFillColor(sf::Color::Black);
    yearText.setString("");

    //Year Heading
    sf::Text yearHeading("Car Year", font, 36);
    yearHeading.setFillColor(sf::Color::Blue);


    //==========Required Text==========
    sf::Text requiredHeader("* = required field", font, 12);
    requiredHeader.setFillColor(sf::Color::Red);


    //==========Search Button==========
    // Set up the rectangle
    sf::RectangleShape searchButtonRectangle(sf::Vector2f(100, 50));
    searchButtonRectangle.setFillColor(sf::Color::Black);
    searchButtonRectangle.setOutlineThickness(2);
    searchButtonRectangle.setOutlineColor(sf::Color::Black);

    //text for search button
    sf::Text searchButtonText("Search", font, 24);
    searchButtonText.setFillColor(sf::Color::White);


    bool isCarMakeActive = false;
    bool isCarModelActive = false;
    bool isMaxPriceActive = false;
    bool isMaxMileageActive = false;
    bool isYearActive = false;
    bool isSearchActive = false;
    bool isImportanceActive = false;
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) { //Exit program
                window.close();
            }


            //==========Car Make==========
            //User clicked in the car make text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && carMakeRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isCarMakeActive = true;
            }
            //User is typing in the car make text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isCarMakeActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for car make

                    carMakeText.setString(carMakeText.getString() + static_cast<char>(event.text.unicode));
                    userInput.make = carMakeText.getString();
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = carMakeText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        carMakeText.setString(str);
                        userInput.make = carMakeText.getString();
                    }
                }
            }
            // Check if the user clicked outside of the car make text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !carMakeRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isCarMakeActive = false;
            }


            //==========Car Model==========
            //User clicked in the car model text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && carModelRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isCarModelActive = true;
            }
            //User is typing in the car model text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isCarModelActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for car model

                    carModelText.setString(carModelText.getString() + static_cast<char>(event.text.unicode));
                    userInput.model = carModelText.getString();
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = carModelText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        carModelText.setString(str);
                        userInput.model = carModelText.getString();
                    }
                }
            }
            // Check if the user clicked outside of the car model text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !carModelRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isCarModelActive = false;
            }


            //==========Max Price==========
            //User clicked in the max price text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && maxPriceRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isMaxPriceActive = true;
            }
            //User is typing in the max price text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isMaxPriceActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for max price

                    maxPriceText.setString(maxPriceText.getString() + static_cast<char>(event.text.unicode));

                    //Convert string to int
                    std::stringstream ss(maxPriceText.getString());
                    ss >> userInput.maxPrice;

                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = maxPriceText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        maxPriceText.setString(str);

                        //Convert string to int
                        std::stringstream ss(maxPriceText.getString());
                        ss >> userInput.maxPrice; //successful Conversion

                    }
                }
            }
            // Check if the user clicked outside of the max price text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !maxPriceRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isMaxPriceActive = false;
            }


            //==========Max Mileage==========
            //User clicked in the max mileage text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && maxMileageRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isMaxMileageActive = true;
            }
            //User is typing in the max mileage text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isMaxMileageActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for max milage

                    maxMileageText.setString(maxMileageText.getString() + static_cast<char>(event.text.unicode));

                    //Convert string to int
                    std::stringstream ss(maxMileageText.getString());
                    ss >> userInput.mileage;

                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = maxMileageText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        maxMileageText.setString(str);

                        //Convert string to int
                        std::stringstream ss(maxMileageText.getString());
                        ss >> userInput.mileage; //successful Conversion

                    }
                }
            }
            // Check if the user clicked outside of the max milage text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !maxMileageRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isMaxMileageActive = false;
            }


            //==========Year==========
            //User clicked in the year text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && yearRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isYearActive = true;
            }
            //User is typing in the year text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isYearActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for year

                    yearText.setString(yearText.getString() + static_cast<char>(event.text.unicode));

                    //Convert string to int
                    std::stringstream ss(yearText.getString());
                    ss >> userInput.year;
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = yearText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        yearText.setString(str);

                        //Convert string to int
                        std::stringstream ss(yearText.getString());
                        ss >> userInput.year; //successful Conversion
                    }
                }
            }
            // Check if the user clicked outside of the year text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !yearRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isYearActive = false;
            }

            //==========Search Button==========
            //User clicked in the body type text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && searchButtonRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isSearchActive = true;
            }

        }


        window.clear(sf::Color::White);

        //Show results if button is clicked
        if (isSearchActive) {

            ifstream file("used_car_sales_csv.csv");
            //create our garage object which will create a vector of cars which will be sorted
            Garage g(file, userInput.make, userInput.model);
            vector<Cars> storeGarage = g.garage;

            //=============Merge Sort==============
            g.mergeSort(g.garage, 0, g.garage.size() - 1, "price");
            //remove all elements that are not under the inputted price
            g.removeElements(userInput.maxPrice, "price");
            g.mergeSort(g.garage, 0, g.garage.size() - 1, "mileage");
            g.removeElements(userInput.mileage, "mileage");
            g.mergeSort(g.garage, 0, g.garage.size() - 1, "year");
            g.removeElements(userInput.year, "year");

            g.garage = storeGarage;
            //=============Quick Sort===============
            g.quickSort(g.garage, 0, g.garage.size() - 1, "price");
            //remove all elements that are not under the inputted price
            g.removeElements(userInput.maxPrice, "price");
            g.quickSort(g.garage, 0, g.garage.size() - 1, "mileage");
            g.removeElements(userInput.mileage, "mileage");
            g.quickSort(g.garage, 0, g.garage.size() - 1, "year");
            g.removeElements(userInput.year, "year");
            //if the number of cars left is greater than 10, just output the first 10
            //if it is 0, tell user we could not find any cars that matched their search
            if (g.garage.size() > 10)
                g.garage.erase(g.garage.begin() + 11, g.garage.end());

            window.clear(sf::Color::White);

            //Search through dataset for cars with correct input
            //fstream file("used_car_sales_csv.csv");
            //Garage g(file, make, model);

            //==========Print car make==========
            sf::RectangleShape printCarMakeRectangle(sf::Vector2f(200, 50));
            printCarMakeRectangle.setFillColor(sf::Color::White);

            //text for car make
            sf::Text printCarMakeText("Car Make: " + userInput.make, font, 24);
            printCarMakeText.setFillColor(sf::Color::Black);

            //Draw car make output
            printCarMakeRectangle.setPosition(50, 30);
            printCarMakeText.setPosition(printCarMakeRectangle.getPosition().x + 10, printCarMakeRectangle.getPosition().y + 10);
            window.draw(printCarMakeRectangle);
            window.draw(printCarMakeText);


            //==========Print car model==========
            sf::RectangleShape printCarModelRectangle(sf::Vector2f(200, 50));
            printCarModelRectangle.setFillColor(sf::Color::White);

            //text for car model
            sf::Text printCarModelText("Car Model: " + userInput.model, font, 24);
            printCarModelText.setFillColor(sf::Color::Black);

            //Draw car model output
            printCarModelRectangle.setPosition(50, 80);
            printCarModelText.setPosition(printCarModelRectangle.getPosition().x + 10, printCarModelRectangle.getPosition().y + 10);
            window.draw(printCarModelRectangle);
            window.draw(printCarModelText);

            //==========Print max price==========
            sf::RectangleShape printMaxPriceRectangle(sf::Vector2f(200, 50));
            printMaxPriceRectangle.setFillColor(sf::Color::White);

            //text for max price
            sf::Text printMaxPriceText("Maximum Price: " + to_string(userInput.maxPrice), font, 24); //Doesn't print out ints correctly
            printMaxPriceText.setFillColor(sf::Color::Black);

            //Draw max price output
            printMaxPriceRectangle.setPosition(50, 130);
            printMaxPriceText.setPosition(printMaxPriceRectangle.getPosition().x + 10, printMaxPriceRectangle.getPosition().y + 10);
            window.draw(printMaxPriceRectangle);
            window.draw(printMaxPriceText);

            //==========Print max mileage==========
            sf::RectangleShape printMaxMileageRectangle(sf::Vector2f(200, 50));
            printMaxMileageRectangle.setFillColor(sf::Color::White);

            //text for max mileage
            sf::Text printMaxMileageText("Maximum Mileage: " + to_string(userInput.mileage), font, 24); //Doesn't print out ints correctly
            printMaxMileageText.setFillColor(sf::Color::Black);

            //Draw max mileage output
            printMaxMileageRectangle.setPosition(50, 180);
            printMaxMileageText.setPosition(printMaxMileageRectangle.getPosition().x + 10, printMaxMileageRectangle.getPosition().y + 10);
            window.draw(printMaxMileageRectangle);
            window.draw(printMaxMileageText);


            //==========Print year==========
            sf::RectangleShape printYearRectangle(sf::Vector2f(200, 50));
            printYearRectangle.setFillColor(sf::Color::White);

            //text for year
            sf::Text printYearText("Car Year: " + to_string(userInput.year), font, 24); //Doesn't print out ints correctly
            printYearText.setFillColor(sf::Color::Black);

            //Draw year output
            printYearRectangle.setPosition(50, 230);
            printYearText.setPosition(printYearRectangle.getPosition().x + 10, printYearRectangle.getPosition().y + 10);
            window.draw(printYearRectangle);
            window.draw(printYearText);
            

            //Display all cars that would satisfy the requirements given by the user

            /*sf::Text printYearText("Car Year: " + to_string(userInput.year), font, 24); //Doesn't print out ints correctly
            printYearText.setFillColor(sf::Color::Black);
            printYearRectangle.setPosition(100, 230);
            printYearText.setPosition(printYearRectangle.getPosition().x + 10, printYearRectangle.getPosition().y + 10);
            window.draw(printYearRectangle);
            window.draw(printYearText);*/


        }
        else { //Search is not clicked, keep getting inputs

            //Draw input for make of car
            carMakeRectangle.setPosition(50, 50);
            makeHeading.setPosition(carMakeRectangle.getPosition().x, carMakeRectangle.getPosition().y - 50);
            carMakeText.setPosition(carMakeRectangle.getPosition().x + 10, carMakeRectangle.getPosition().y + 10);
            window.draw(carMakeRectangle);
            window.draw(makeHeading);
            window.draw(carMakeText);

            //Draw input for car model
            carModelRectangle.setPosition(400, 50);
            carModelHeading.setPosition(carModelRectangle.getPosition().x, carModelRectangle.getPosition().y - 50);
            carModelText.setPosition(carModelRectangle.getPosition().x + 10, carModelRectangle.getPosition().y + 10);
            window.draw(carModelRectangle);
            window.draw(carModelHeading);
            window.draw(carModelText);

            //Draw input for max price
            maxPriceRectangle.setPosition(50, 200);
            maxPriceHeading.setPosition(maxPriceRectangle.getPosition().x, maxPriceRectangle.getPosition().y - 50);
            maxPriceText.setPosition(maxPriceRectangle.getPosition().x + 10, maxPriceRectangle.getPosition().y + 10);
            window.draw(maxPriceRectangle);
            window.draw(maxPriceHeading);
            window.draw(maxPriceText);

            //Draw input for max milage
            maxMileageRectangle.setPosition(400, 200);
            maxMileageHeading.setPosition(maxMileageRectangle.getPosition().x, maxMileageRectangle.getPosition().y - 50);
            maxMileageText.setPosition(maxMileageRectangle.getPosition().x + 10, maxMileageRectangle.getPosition().y + 10);
            window.draw(maxMileageRectangle);
            window.draw(maxMileageHeading);
            window.draw(maxMileageText);

            //Draw input for year
            yearRectangle.setPosition(50, 350);
            yearHeading.setPosition(yearRectangle.getPosition().x, yearRectangle.getPosition().y - 50);
            yearText.setPosition(yearRectangle.getPosition().x + 10, yearRectangle.getPosition().y + 10);
            window.draw(yearRectangle);
            window.draw(yearHeading);
            window.draw(yearText);

            //Draw Search Button
            searchButtonRectangle.setPosition(400, 450);
            searchButtonText.setPosition(searchButtonRectangle.getPosition().x + 10, searchButtonRectangle.getPosition().y + 10);
            window.draw(searchButtonRectangle);
            window.draw(searchButtonText);


        }





        window.display();

    }





    std::cout << "Car Make = " << userInput.make << std::endl;
    std::cout << "Car model = " << userInput.model << std::endl;
    std::cout << "Max Price = " << userInput.maxPrice << std::endl;
    std::cout << "Max Mileage = " << userInput.mileage << std::endl;
    std::cout << "Car year = " << userInput.year << std::endl;


    //==========Merge Sort==========





    //==========Quick Sort==========

    return 0;
}