/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Menu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <deque>
#include <iostream>
#include "Parser.hpp"

#define MAX_TEXT_LENGTH 1225

class Menu {
    public:
        Menu();
        void drawText(sf::Text &hostText, std::string &selectedString);
        void updateCursor();
        void updateText(sf::Uint32 &unicode, sf::Text &text, std::string &inputString);
        void updateText(sf::Text &text, std::string &inputString);
        sf::Text getHostText(sf::Font &fontArg);
        void setInputText(sf::Text &text, std::string &inputString, bool forceHideCursor = false);
        void drawHostImage();
        void drawStack();
        void launchParser(bool print = true);
        void checkEvents(sf::Event &event, sf::Text &hostText, std::string &host);
        bool checkError(const char *error, std::string &host, sf::Text &hostText);
        void clearInput(sf::Text &hostText, std::string &host);
    private:
        sf::Font font;
        sf::Clock cursorClock;
        bool showCursor{true};
        std::string hostString;
        const sf::Time cursorBlinkTime{sf::seconds(0.5f)};

        std::deque<std::string> inputStrings;

        std::deque<AbstractVM::IOperand *> stack;
        std::deque<AbstractVM::IOperand *> registers;

        sf::RenderWindow window{sf::VideoMode(1280, 720), "abstractVM - Window"};
};
