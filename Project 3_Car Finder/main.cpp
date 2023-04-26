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

    sf::RenderWindow window(sf::VideoMode(800, 500), "SFML window");
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


    //==========Set up text, box, text, and inputs for zip code==========
    sf::RectangleShape zipCodeRectangle = textBox();
    int zipCodeInput;

    //Hold text for zip code
    sf::Text zipCodeText;
    zipCodeText.setFont(font);
    zipCodeText.setCharacterSize(24);
    zipCodeText.setFillColor(sf::Color::Black);
    zipCodeText.setString("");

    //Zip code Heading
    sf::Text zipCodeHeading("Zip Code*", font, 36);
    zipCodeHeading.setFillColor(sf::Color::Blue);


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


    //==========Set up text, box, text, and inputs for body type==========
    sf::RectangleShape bodyTypeRectangle = textBox();
    std::string bodyTypeInput;

    //Hold text for body type
    sf::Text bodyTypeText;
    bodyTypeText.setFont(font);
    bodyTypeText.setCharacterSize(24);
    bodyTypeText.setFillColor(sf::Color::Black);
    bodyTypeText.setString("");

    //Body type Heading
    sf::Text bodyTypeHeading("Body Type", font, 36);
    bodyTypeHeading.setFillColor(sf::Color::Blue);


    //==========Required Text==========
    sf::Text requiredHeader("* = required field", font, 12);
    requiredHeader.setFillColor(sf::Color::Red);


    //==========Set up text, box, text, and inputs for distance away==========
    sf::RectangleShape distanceRectangle = textBox();
    int distanceInput;

    //Hold text for distance
    sf::Text distanceText;
    distanceText.setFont(font);
    distanceText.setCharacterSize(24);
    distanceText.setFillColor(sf::Color::Black);
    distanceText.setString("");

    //Distance Heading
    sf::Text distanceHeading("Distance Away (Miles)", font, 36);
    distanceHeading.setFillColor(sf::Color::Blue);


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
    bool isZipCodeActive = false;
    bool isMinPriceActive = false;
    bool isMaxPriceActive = false;
    bool isBodyTypeActive = false;
    bool isDistanceActive = false;
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


            //==========Zip code==========
            //User clicked in the zip code text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && zipCodeRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isZipCodeActive = true;
            }
            //User is typing in the zip code text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isZipCodeActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for zip code

                    zipCodeText.setString(zipCodeText.getString() + static_cast<char>(event.text.unicode));

                    //Convert string to int
                    std::stringstream ss(zipCodeText.getString());
                    ss >> zipCodeInput;
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = zipCodeText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        zipCodeText.setString(str);

                        //Convert string to int
                        std::stringstream ss(zipCodeText.getString());
                        ss >> zipCodeInput;
                    }
                }
            }
            // Check if the user clicked outside of the zip code text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !zipCodeRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isZipCodeActive = false;
            }


            //==========Min Price==========
            //User clicked in the min price text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && minPriceRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isMinPriceActive = true;
            }
            //User is typing in the min price text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isMinPriceActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for zip code

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

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for zip code

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


            //==========Body Type==========
            //User clicked in the body type text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && bodyTypeRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isBodyTypeActive = true;
            }
            //User is typing in the body type text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isBodyTypeActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for zip code

                    bodyTypeText.setString(bodyTypeText.getString() + static_cast<char>(event.text.unicode));

                    bodyTypeInput = bodyTypeText.getString();
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = bodyTypeText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        bodyTypeText.setString(str);
                        bodyTypeInput = bodyTypeText.getString();
                    }
                }
            }
            // Check if the user clicked outside of the body type text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !bodyTypeRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isBodyTypeActive = false;
            }


            //==========Distance away==========
            //User clicked in the distance text box
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && distanceRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isDistanceActive = true;
            }
            //User is typing in the min price text box
            if (!isSearchActive && event.type == sf::Event::TextEntered && isDistanceActive) {

                if (event.text.unicode < 128 && event.text.unicode != '\b') { //Get input for zip code

                    distanceText.setString(distanceText.getString() + static_cast<char>(event.text.unicode));

                    //Convert string to int
                    std::stringstream ss(distanceText.getString());
                    ss >> distanceInput;
                }
                else if (event.text.unicode == '\b') { // Handle backspace

                    std::string str = distanceText.getString();
                    if (str.size() > 0) {
                        str.pop_back();
                        distanceText.setString(str);

                        //Convert string to int
                        std::stringstream ss(distanceText.getString());
                        ss >> distanceInput;
                    }
                }
            }
            // Check if the user clicked outside of the body type text box to deactivate it
            if (!isSearchActive && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !distanceRectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                isDistanceActive = false;
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


            //==========Print zip code==========
            sf::RectangleShape printZipCodeRectangle(sf::Vector2f(200, 50));
            printZipCodeRectangle.setFillColor(sf::Color::White);

            //text for car make
            sf::Text printZipCodeText("Zip Code: " + to_string(zipCodeInput), font, 24); //Doesn't print out ints correctly
            printZipCodeText.setFillColor(sf::Color::Black);

            //Draw car make output
            printZipCodeRectangle.setPosition(50, 80);
            printZipCodeText.setPosition(printZipCodeRectangle.getPosition().x + 10, printZipCodeRectangle.getPosition().y + 10);
            window.draw(printZipCodeRectangle);
            window.draw(printZipCodeText);


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


            //==========Print body type==========
            sf::RectangleShape printBodyTypeRectangle(sf::Vector2f(200, 50));
            printBodyTypeRectangle.setFillColor(sf::Color::White);

            //text for body type
            sf::Text printBodyTypeText("Body Type: " + bodyTypeInput, font, 24); //Doesn't print out ints correctly
            printBodyTypeText.setFillColor(sf::Color::Black);

            //Draw body type output
            printBodyTypeRectangle.setPosition(50, 230);
            printBodyTypeText.setPosition(printBodyTypeRectangle.getPosition().x + 10, printBodyTypeRectangle.getPosition().y + 10);
            window.draw(printBodyTypeRectangle);
            window.draw(printBodyTypeText);


            //==========Print distance==========
            sf::RectangleShape printDistanceRectangle(sf::Vector2f(200, 50));
            printDistanceRectangle.setFillColor(sf::Color::White);

            //text for distance
            sf::Text printDistanceText("Distance (Miles): " + to_string(distanceInput), font, 24); //Doesn't print out ints correctly
            printDistanceText.setFillColor(sf::Color::Black);

            //Draw distance output
            printDistanceRectangle.setPosition(50, 280);
            printDistanceText.setPosition(printDistanceRectangle.getPosition().x + 10, printDistanceRectangle.getPosition().y + 10);
            window.draw(printDistanceRectangle);
            window.draw(printDistanceText);


        }
        else { //Search is not clicked, keep getting inputs

            //Draw input for make of car
            carMakeRectangle.setPosition(50, 50);
            makeHeading.setPosition(carMakeRectangle.getPosition().x, carMakeRectangle.getPosition().y - 50);
            carMakeText.setPosition(carMakeRectangle.getPosition().x + 10, carMakeRectangle.getPosition().y + 10);
            window.draw(carMakeRectangle);
            window.draw(makeHeading);
            window.draw(carMakeText);

            //Draw input for zip code
            zipCodeRectangle.setPosition(400, 50);
            zipCodeHeading.setPosition(zipCodeRectangle.getPosition().x, zipCodeRectangle.getPosition().y - 50);
            zipCodeText.setPosition(zipCodeRectangle.getPosition().x + 10, zipCodeRectangle.getPosition().y + 10);
            window.draw(zipCodeRectangle);
            window.draw(zipCodeHeading);
            window.draw(zipCodeText);

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

            //Draw input for body type
            bodyTypeRectangle.setPosition(50, 350);
            bodyTypeHeading.setPosition(bodyTypeRectangle.getPosition().x, bodyTypeRectangle.getPosition().y - 50);
            bodyTypeText.setPosition(bodyTypeRectangle.getPosition().x + 10, bodyTypeRectangle.getPosition().y + 10);
            window.draw(bodyTypeRectangle);
            window.draw(bodyTypeHeading);
            window.draw(bodyTypeText);

            //Draw input for distance
            distanceRectangle.setPosition(400, 350);
            distanceHeading.setPosition(distanceRectangle.getPosition().x, distanceRectangle.getPosition().y - 50);
            distanceText.setPosition(distanceRectangle.getPosition().x + 10, distanceRectangle.getPosition().y + 10);
            window.draw(distanceRectangle);
            window.draw(distanceHeading);
            window.draw(distanceText);

            //Draw Search Button
            searchButtonRectangle.setPosition(400, 450);
            searchButtonText.setPosition(searchButtonRectangle.getPosition().x + 10, searchButtonRectangle.getPosition().y + 10);
            window.draw(searchButtonRectangle);
            window.draw(searchButtonText);

            //Draw Required header
            requiredHeader.setPosition(400, 100);
            window.draw(requiredHeader);

        }





        window.display();
    }


    std::cout << "Car Make = " << carMakeInput << std::endl;

    std::cout << "ZipCode = " << zipCodeInput << std::endl;

    std::cout << "Min Price = " << minPriceInput << std::endl;

    if (maxPriceInput == 0) { //No Input given
        maxPriceInput = INT_MAX;
    }
    std::cout << "Max Price = " << maxPriceInput << std::endl;

    std::cout << "Body Type = " << bodyTypeInput << std::endl;

    std::cout << "Distance = " << distanceInput << std::endl;


    return 0;
}
