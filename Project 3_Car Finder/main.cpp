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


    sf::RenderWindow window(sf::VideoMode(1000, 500), "Car determiner 3,000");
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
            /*g.mergeSort(g.garage, 0, g.garage.size() - 1, "price");
            //remove all elements that are not under the inputted price
            g.removeElements(userInput.maxPrice, "price");
            g.mergeSort(g.garage, 0, g.garage.size() - 1, "mileage");
            g.removeElements(userInput.mileage, "mileage");
            g.mergeSort(g.garage, 0, g.garage.size() - 1, "year");
            g.removeElements(userInput.year, "year");*/

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
                g.garage.erase(g.garage.begin() + 10, g.garage.end());

            window.clear(sf::Color::White);

            //==========Top Ten cars==========
            sf::RectangleShape topTenCarsRectangle(sf::Vector2f(200, 50));
            topTenCarsRectangle.setFillColor(sf::Color::White);
            //text for top 10 cars
            sf::Text topTenCarsText("Top 5 Overall Cars", font, 36);
            topTenCarsText.setFillColor(sf::Color::Blue);
            //Draw Top 10 cars output
            topTenCarsRectangle.setPosition(250, 20);
            topTenCarsText.setPosition(topTenCarsRectangle.getPosition().x + 10, topTenCarsRectangle.getPosition().y + 10);
            window.draw(topTenCarsRectangle);
            window.draw(topTenCarsText);


            //==========Print car 1==========
            sf::RectangleShape car1(sf::Vector2f(200, 50));
            car1.setFillColor(sf::Color::White);
            //text for car1
            string car1String = "Make: " + g.garage[0].getMake() + ", Model: " + g.garage[0].getModel() + ", Price: " + to_string(g.garage[0].getPrice()) + ", Mileage: " + to_string(g.garage[0].getMileage()) + ", Year: " + to_string(g.garage[0].getYear());
            sf::Text car1Text("#1: " + car1String, font, 24);
            car1Text.setFillColor(sf::Color::Black);
            //Draw car1 output
            car1.setPosition(30, 70);
            car1Text.setPosition(car1.getPosition().x + 10, car1.getPosition().y + 10);
            window.draw(car1);
            window.draw(car1Text);

            //==========Print car 2==========
            sf::RectangleShape car2(sf::Vector2f(200, 50));
            car2.setFillColor(sf::Color::White);
            //text for car2
            string car2String = "Make: " + g.garage[1].getMake() + ", Model: " + g.garage[1].getModel() + ", Price: " + to_string(g.garage[1].getPrice()) + ", Mileage: " + to_string(g.garage[1].getMileage()) + ", Year: " + to_string(g.garage[1].getYear());
            sf::Text car2Text("#2: " + car2String, font, 24);
            car2Text.setFillColor(sf::Color::Black);
            //Draw car2 output
            car2.setPosition(30, 120);
            car2Text.setPosition(car2.getPosition().x + 10, car2.getPosition().y + 10);
            window.draw(car2);
            window.draw(car2Text);

            //==========Print car 3==========
            sf::RectangleShape car3(sf::Vector2f(200, 50));
            car3.setFillColor(sf::Color::White);
            //text for car3
            string car3String = "Make: " + g.garage[2].getMake() + ", Model: " + g.garage[2].getModel() + ", Price: " + to_string(g.garage[2].getPrice()) + ", Mileage: " + to_string(g.garage[2].getMileage()) + ", Year: " + to_string(g.garage[2].getYear());
            sf::Text car3Text("#3: " + car3String, font, 24);
            car3Text.setFillColor(sf::Color::Black);
            //Draw car3 output
            car3.setPosition(30, 170);
            car3Text.setPosition(car3.getPosition().x + 10, car3.getPosition().y + 10);
            window.draw(car3);
            window.draw(car3Text);

            //==========Print car 4==========
            sf::RectangleShape car4(sf::Vector2f(200, 50));
            car4.setFillColor(sf::Color::White);
            //text for car4
            string car4String = "Make: " + g.garage[3].getMake() + ", Model: " + g.garage[3].getModel() + ", Price: " + to_string(g.garage[3].getPrice()) + ", Mileage: " + to_string(g.garage[3].getMileage()) + ", Year: " + to_string(g.garage[3].getYear());
            sf::Text car4Text("#4: " + car4String, font, 24);
            car4Text.setFillColor(sf::Color::Black);
            //Draw car4 output
            car4.setPosition(30, 220);
            car4Text.setPosition(car4.getPosition().x + 10, car4.getPosition().y + 10);
            window.draw(car4);
            window.draw(car4Text);

            //==========Print car 5==========
            sf::RectangleShape car5(sf::Vector2f(200, 50));
            car5.setFillColor(sf::Color::White);
            //text for car5
            string car5String = "Make: " + g.garage[4].getMake() + ", Model: " + g.garage[4].getModel() + ", Price: " + to_string(g.garage[4].getPrice()) + ", Mileage: " + to_string(g.garage[4].getMileage()) + ", Year: " + to_string(g.garage[4].getYear());
            sf::Text car5Text("#5: " + car5String, font, 24);
            car5Text.setFillColor(sf::Color::Black);
            //Draw car5 output
            car5.setPosition(30, 270);
            car5Text.setPosition(car5.getPosition().x + 10, car5.getPosition().y + 10);
            window.draw(car5);
            window.draw(car5Text);

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