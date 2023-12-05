/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** main
*/

#include "Parser.hpp"
#include "Factory.hpp"
#include "Menu.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    if (!(ac == 1 || ac == 2)) {
        std::cerr << "Usage: ./abstractVM [file]" << std::endl;
        return 84;
    }

    if (ac == 2) {
        std::ifstream file;

        file.open(av[1]);
        if (!file.is_open()) {
            std::cerr << "Error: could not open file" << std::endl;
            return 84;
        }
        try {
            AbstractVM::Parser parser;
            parser.parse(file);
            file.close();
            return 0;
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 84;
        }
    }
    Menu menu;
}
