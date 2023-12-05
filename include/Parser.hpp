/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Parser
*/

#pragma once

#include <vector>
#include <string>
#include "Factory.hpp"

namespace AbstractVM {

class Parser {
    public:
        Parser() = default;
        ~Parser() = default;

        void parse(std::istream &stream);
        void parseTokens();
        void tokenize(std::string &line);

        void assertOperand(std::string const &type, std::string const &value);
        void pushOperand(std::string const &type, std::string const &value);

        AbstractVM::Factory factory;
    protected:
    private:
        std::vector<std::string> tokens;
};

}