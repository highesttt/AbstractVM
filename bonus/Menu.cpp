/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Menu
*/

#include "Menu.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define DUMP "\n\033[1;36m━━━━━━━━━━━━━━━━━━━━━━━\033[1;31mDump\033[1;36m━━━━━━━━━━━━━━━━━━━━━━━━━\n\033[0m"
#define HISTORY "\n\033[1;36m━━━━━━━━━━━━━━━━━━━━━━\033[1;31mHistory\033[1;36m━━━━━━━━━━━━━━━━━━━━━━━━\n\033[0m"

Menu::Menu() {
    sf::Event event;
    sf::Text hostText = getHostText(font);
    sf::Color color = {236, 240, 243, 255};
    std::string host = "";

    if (!font.loadFromFile("./bonus/assets/font.ttf")) {
        std::cerr << "Error: failed to load font." << std::endl;
        exit(84);
    }

    window.setFramerateLimit(60);
    window.clear(color);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            this->checkEvents(event, hostText, host);
        }

        drawHostImage();
        this->drawText(hostText, host);

        window.display();
    }
}

void Menu::checkEvents(sf::Event &event, sf::Text &hostText, std::string &host) {
    if (event.type == sf::Event::Closed)
        window.close();

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
        this->setInputText(hostText, host, true);
        if (host != "") {
            clearInput(hostText, host);
            try {
                launchParser();
            } catch (std::exception &e) {
                if (checkError(e.what(), host, hostText))
                    inputStrings.pop_front();
            }
        }
    } else if (event.type == sf::Event::TextEntered) {
        this->updateText(event.text.unicode, hostText, host);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
        std::string clipboard = sf::Clipboard::getString();
        for (auto &i : clipboard) {
            sf::Uint32 unicode = i;
            this->updateText(unicode, hostText, host);
        }
    }
}

bool Menu::checkError(const char *error, std::string &host, sf::Text &hostText) {
    sf::Color color = {236, 240, 243, 255};

    if (inputStrings.front().compare("restart\n") == 0) {
        window.clear(color);
        inputStrings.clear();
        return false;
    } else if (inputStrings.front().compare("back\n") == 0) {
        if (inputStrings.size() > 0) {
            inputStrings.pop_front();
            host = inputStrings.front().substr(0, inputStrings.front().size() - 1);
            this->setInputText(hostText, host, true);
            inputStrings.pop_front();
            launchParser(false);
            return false;
        }
        return false;
    } else {
        std::cerr << "Error: " << error << "\e[0m" << std::endl;
        return true;
    }
}

void Menu::clearInput(sf::Text &hostText, std::string &host) {
    if (host != "exit" && host != ";;")
        inputStrings.push_front(host + "\n");
    host.clear();
    if (!host.empty())
        host.pop_back();
    this->setInputText(hostText, host, true);
}

void Menu::launchParser(bool print) {
    sf::Color color = {236, 240, 243, 255};
    AbstractVM::Parser parser;
    std::istringstream res;
    std::istringstream final;

    for (auto &i : inputStrings)
        res.str(i + res.str());
    final.str(res.str() + "exit");
    if (print)
        std::cout << DUMP << std::endl;
    parser.parse(final);
    if (print)
        std::cout << DUMP << std::endl;
    if (print)
        std::cout << HISTORY << std::endl;
    std::cout << final.str() << std::endl;
    if (print)
        std::cout << HISTORY << std::endl;
    this->stack = parser.factory.stack.stack;
    this->registers = parser.factory.stack.registers;
    window.clear(color);
    drawStack();
}

void Menu::drawText(sf::Text &hostText, std::string &selectedString) {
    if (cursorClock.getElapsedTime() >= cursorBlinkTime) {
        showCursor = !showCursor;
        this->setInputText(hostText, selectedString);
        cursorClock.restart();
    }

    window.draw(hostText);
}

void Menu::updateText(sf::Uint32 &unicode, sf::Text &text, std::string &inputString) {
    if (unicode < 128 && unicode != 13) {
        if (unicode == '\b' && !inputString.empty()) {
            inputString.pop_back();
        }
        else if (unicode != '\b' && text.getLocalBounds().width < MAX_TEXT_LENGTH && unicode != '\t') {
            inputString += static_cast<char>(unicode);
        }
        this->setInputText(text, inputString);
        this->updateCursor();
    }
}

void Menu::updateText(sf::Text &text, std::string &inputString) {
    this->setInputText(text, inputString);
}

void Menu::updateCursor() {
    cursorClock.restart();
    showCursor = true;
}

void Menu::drawHostImage() {
    sf::Image image;
    if (!image.loadFromFile("./bonus/assets/textbox.png")) {
        std::cerr << "Error: failed to load image." << std::endl;
        exit(84);
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(1.2, 1.2);
    window.draw(sprite);
}

sf::Text Menu::getHostText(sf::Font &fontArg) {
    sf::Text hostText;
    hostText.setFont(fontArg);
    hostText.setCharacterSize(30);
    hostText.setFillColor(sf::Color::Black);
    hostText.setString("_");
    hostText.setPosition(20, 20);
    return hostText;
}

void Menu::setInputText(sf::Text &text, std::string &inputString, bool forceHide) {
    if (showCursor && !forceHide) {
        text.setString(inputString + "_");
    } else {
        text.setString(inputString);
    }
}

void Menu::drawStack() {

    sf::Text stackText;
    stackText.setFont(font);
    stackText.setCharacterSize(30);
    stackText.setFillColor(sf::Color::Black);
    stackText.setString("Stack:");
    stackText.setPosition(680, 100);

    sf::Text registersText;
    registersText.setFont(font);
    registersText.setCharacterSize(30);
    registersText.setFillColor(sf::Color::Black);
    registersText.setString("Registers:");
    registersText.setPosition(50, 100);


    int i = 0;
    for (auto &it : stack) {
        sf::Text stackText;
        stackText.setFont(font);
        stackText.setCharacterSize(30);
        stackText.setFillColor(sf::Color::Black);
        if (i == 15) {
            stackText.setString("...");
            stackText.setPosition(730, 130 + (i * 30));
            window.draw(stackText);
            break;
        } else {
            stackText.setString(getTextType(it->getType()) + "(" + it->toString() + ")");
        }
        stackText.setPosition(730, 130 + (i * 30));
        window.draw(stackText);
        i++;
    }

    i = 0;
    for (auto &it : registers) {
        sf::Text registersText;
        registersText.setFont(font);
        registersText.setCharacterSize(30);
        registersText.setFillColor(sf::Color::Black);
        if (it != nullptr)
            registersText.setString(getTextType(it->getType()) + "(" + it->toString() + ")");
        else
            registersText.setString("none");
        registersText.setPosition(100, 130 + (i * 30));
        window.draw(registersText);
        i++;
    }

    window.draw(stackText);
    window.draw(registersText);
}