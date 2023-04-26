#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#pragma "once"

using namespace std;

sf::RectangleShape textBox() {

    // Set up the rectangle
    sf::RectangleShape rectangle(sf::Vector2f(200, 50));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);

    return rectangle;
}

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 500), "Car determiner 3,000");
    //window.setFramerateLimit(60);

    //Font
    sf::Font font;
    font.loadFromFile("arial.ttf");

    //==========Set Up text box, text, and inputs for car make==========
    sf::RectangleShape carMakeRectangle = textBox();
    std::string carMakeInput;

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
    std::string carModelInput;

    //Hold text for car model
    sf::Text carModelText;
    carModelText.setFont(font);
    carModelText.setCharacterSize(24);
    carModelText.setFillColor(sf::Color::Black);
    carModelText.setString("");

    //Car model Heading
    sf::Text carModelHeading("Car Model", font, 36);
    carModelHeading.setFillColor(sf::Color::Blue);


    //==========Set up text, box, text, and inputs for min price==========
    sf::RectangleShape minPriceRectangle = textBox();
    int minPriceInput;

    //Hold text for min price
    sf::Text minPriceText;
    minPriceText.setFont(font);
    minPriceText.setCharacterSize(24);
    minPriceText.setFillColor(sf::Color::Black);
    minPriceText.setString("");

    //Min price Heading
    sf::Text minPriceHeading("Min Price", font, 36);
    minPriceHeading.setFillColor(sf::Color::Blue);


    //==========Set up text, box, text, and inputs for max price==========
    sf::RectangleShape maxPriceRectangle = textBox();
    int maxPriceInput;

    //Hold text for max price
    sf::Text maxPriceText;
    maxPriceText.setFont(font);
    maxPriceText.setCharacterSize(24);
    maxPriceText.setFillColor(sf::Color::Black);
    maxPriceText.setString("");

    //Max price Heading
    sf::Text maxPriceHeading("Max Price", font, 36);
    maxPriceHeading.setFillColor(sf::Color::Blue);


    //==========Set up text, box, text, and inputs for year==========
    sf::RectangleShape yearRectangle = textBox();
    int yearInput;

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
    bool isMinPriceActive = false;
    bool isMaxPriceActive = false;
    bool isYearActive = false;
    bool isSearchActive = false;
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
                    carMakeInput = carMakeText.getString();
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = carMakeText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        carMakeText.setString(str);
                        carMakeInput = carMakeText.getString();
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
                    carModelInput = carModelText.getString();
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = carModelText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        carModelText.setString(str);
                        carModelInput = carModelText.getString();
                    }
                }
            }
            // Check if the user clicked outside of the car model text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !carModelRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isCarModelActive = false;
            }


            //==========Min Price==========
            //User clicked in the min price text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && minPriceRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isMinPriceActive = true;
            }
            //User is typing in the min price text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isMinPriceActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for min price

                    minPriceText.setString(minPriceText.getString() + static_cast<char>(event.text.unicode));

                    //Convert string to int
                    std::stringstream ss(minPriceText.getString());
                    ss >> minPriceInput;
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = minPriceText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        minPriceText.setString(str);

                        //Convert string to int
                        std::stringstream ss(minPriceText.getString());
                        ss >> minPriceInput;
                    }
                }
            }
            // Check if the user clicked outside of the min price text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !minPriceRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isMinPriceActive = false;
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
                    ss >> maxPriceInput;

                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = maxPriceText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        maxPriceText.setString(str);

                        //Convert string to int
                        std::stringstream ss(maxPriceText.getString());
                        ss >> maxPriceInput; //successful Conversion

                    }
                }
            }
            // Check if the user clicked outside of the max price text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !maxPriceRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isMaxPriceActive = false;
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
                    ss >> yearInput;
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = yearText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        yearText.setString(str);

                        //Convert string to int
                        std::stringstream ss(yearText.getString());
                        ss >> yearInput; //successful Conversion
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

            window.clear(sf::Color::White);

            //==========Print car make==========
            sf::RectangleShape printCarMakeRectangle(sf::Vector2f(200, 50));
            printCarMakeRectangle.setFillColor(sf::Color::White);

            //text for car make
            sf::Text printCarMakeText("Car Make: " + carMakeInput, font, 24);
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
            sf::Text printCarModelText("Car Model: " + carModelInput, font, 24);
            printCarModelText.setFillColor(sf::Color::Black);

            //Draw car model output
            printCarModelRectangle.setPosition(50, 80);
            printCarModelText.setPosition(printCarModelRectangle.getPosition().x + 10, printCarModelRectangle.getPosition().y + 10);
            window.draw(printCarModelRectangle);
            window.draw(printCarModelText);


            //==========Print min price==========
            sf::RectangleShape printMinPriceRectangle(sf::Vector2f(200, 50));
            printMinPriceRectangle.setFillColor(sf::Color::White);

            //text for Minimum price
            sf::Text printMinPriceText("Minimum Price: " + to_string(minPriceInput), font, 24); //Doesn't print out ints correctly
            printMinPriceText.setFillColor(sf::Color::Black);

            //Draw min price output
            printMinPriceRectangle.setPosition(50, 130);
            printMinPriceText.setPosition(printMinPriceRectangle.getPosition().x + 10, printMinPriceRectangle.getPosition().y + 10);
            window.draw(printMinPriceRectangle);
            window.draw(printMinPriceText);


            //==========Print max price==========
            sf::RectangleShape printMaxPriceRectangle(sf::Vector2f(200, 50));
            printMaxPriceRectangle.setFillColor(sf::Color::White);

            //text for max price
            sf::Text printMaxPriceText("Maximum Price: " + to_string(maxPriceInput), font, 24); //Doesn't print out ints correctly
            printMaxPriceText.setFillColor(sf::Color::Black);

            //Draw max price output
            printMaxPriceRectangle.setPosition(50, 180);
            printMaxPriceText.setPosition(printMaxPriceRectangle.getPosition().x + 10, printMaxPriceRectangle.getPosition().y + 10);
            window.draw(printMaxPriceRectangle);
            window.draw(printMaxPriceText);


            //==========Print year==========
            sf::RectangleShape printYearRectangle(sf::Vector2f(200, 50));
            printYearRectangle.setFillColor(sf::Color::White);

            //text for year
            sf::Text printYearText("Car Year: " + to_string(yearInput), font, 24); //Doesn't print out ints correctly
            printYearText.setFillColor(sf::Color::Black);

            //Draw year output
            printYearRectangle.setPosition(50, 230);
            printYearText.setPosition(printYearRectangle.getPosition().x + 10, printYearRectangle.getPosition().y + 10);
            window.draw(printYearRectangle);
            window.draw(printYearText);

        } else { //Search is not clicked, keep getting inputs

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

            //Draw inputs input for min price
            minPriceRectangle.setPosition(50, 200);
            minPriceHeading.setPosition(minPriceRectangle.getPosition().x, minPriceRectangle.getPosition().y - 50);
            minPriceText.setPosition(minPriceRectangle.getPosition().x + 10, minPriceRectangle.getPosition().y + 10);
            window.draw(minPriceRectangle);
            window.draw(minPriceHeading);
            window.draw(minPriceText);

            //Draw input for max price
            maxPriceRectangle.setPosition(400, 200);
            maxPriceHeading.setPosition(maxPriceRectangle.getPosition().x, maxPriceRectangle.getPosition().y - 50);
            maxPriceText.setPosition(maxPriceRectangle.getPosition().x + 10, maxPriceRectangle.getPosition().y + 10);
            window.draw(maxPriceRectangle);
            window.draw(maxPriceHeading);
            window.draw(maxPriceText);

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


    std::cout << "Car Make = " << carMakeInput << std::endl;

    std::cout << "Car model = " << carModelInput << std::endl;

    std::cout << "Min Price = " << minPriceInput << std::endl;

    if (maxPriceInput == 0) { //No Input given
        maxPriceInput = INT_MAX;
    }
    std::cout << "Max Price = " << maxPriceInput << std::endl;

    std::cout << "Car year = " << yearInput << std::endl;


    return 0;
}
