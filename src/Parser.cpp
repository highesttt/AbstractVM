/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** parser
*/

#include <regex>
#include <iostream>
#include "utils.h"
#include "Exception.hpp"
#include "Parser.hpp"

namespace AbstractVM {

void Parser::parse(std::istream &stream) {
    std::string completeStream;
    std::string line;

    while (std::getline(stream, line)) {
        if (line == ";;")
            break;
        completeStream += line + "\n";
    }
    line = "";
    for (std::string::iterator it = completeStream.begin(); it != completeStream.end(); it++) {
        if (line == "exit") {
            tokens.push_back(line);
            break;
        }
        if (*it == '\n') {
            tokenize(line);
            line.clear();
        } else {
            line += *it;
        }
    }
    if (tokens.size() == 0 || tokens[tokens.size() - 1] != "exit") {
        std::string error = "&eMissing exit instruction";
        throw Exception(message(error));
    }
    parseTokens();
}

void Parser::parseTokens() {
    size_t line = 1;

    for (size_t i = 0; i < tokens.size(); i++) {
        try {
            if (tokens[i] == "push") {
                if (tokens.size() < i + 3)
                    throw Exception("invalid push instruction");
                pushOperand(tokens[i + 1], tokens[i + 2]);
                i += 2;
            } else if (tokens[i] == "pop") {
                factory.stack.pop();
            } else if (tokens[i] == "dump") {
                factory.stack.dump();
            } else if (tokens[i] == "assert") {
                if (tokens.size() < i + 3)
                    throw Exception("invalid assert instruction");
                if (isValidType(tokens[i + 1]) && std::regex_match(tokens[i + 2], std::regex("-?[[:digit:]]+\\.*[[:digit:]]*"))) {
                    assertOperand(tokens[i + 1], tokens[i + 2]);
                    i += 2;
                } else {
                    throw Exception("invalid assert instruction");
                }
            } else if (tokens[i] == "add") {
                factory.stack.add();
            } else if (tokens[i] == "sub") {
                factory.stack.sub();
            } else if (tokens[i] == "mul") {
                factory.stack.mul();
            } else if (tokens[i] == "div") {
                factory.stack.div();
            } else if (tokens[i] == "mod") {
                factory.stack.mod();
            } else if (tokens[i] == "print") {
                factory.stack.print();
            } else if (tokens[i] == "load") {
                if (tokens.size() < i + 3)
                    throw Exception("invalid load instruction");
                size_t index = std::stoi(tokens[i + 2]);
                factory.stack.load(index);
                i += 2;
            } else if (tokens[i] == "store") {
                if (tokens.size() < i + 3)
                    throw Exception("invalid store instruction");
                size_t index = std::stoi(tokens[i + 2]);
                factory.stack.store(index);
                i += 2;
            } else if (tokens[i] == "exit") {
                return;
            } else if (tokens[i] == "clear") {
                factory.stack.clear();
            } else if (tokens[i] == "dup") {
                factory.stack.dup();
            } else if (tokens[i] == "swap") {
                factory.stack.swap();
            } else if (tokens[i][0] != ';') {
                throw Exception("Unknown instruction");
            }
        line++;
        } catch (std::exception &e) {
            std::string error = "&cline " + std::to_string(line) + ":&e " + e.what();
            throw Exception(message(error));
            return;
        }
    }
}

void Parser::tokenize(std::string &line) {
    std::regex regex(
    "int8|int16|int32|float|double|"
    ";.*$|"
    "(?:[[:alpha:]]+|"
    "\\((?:-?[[:digit:]]+\\.*[[:digit:]]*\\)))"
    );
    std::smatch match;

    while (std::regex_search(line, match, regex)) {
        std::string token = match[0];

        if (token[0] == '(') {
            token.erase(0, 1);
            token.erase(token.size() - 1, 1);
        }
        if (token[0] != ';')
            tokens.push_back(token);
        line = match.suffix().str();
    }
}

void Parser::pushOperand(std::string const &type, std::string const &value) {
    if (type == "int8") {
        factory.stack.push(factory.createOperand(AbstractVM::eOperandType::INT8, value));
    } else if (type == "int16") {
        factory.stack.push(factory.createOperand(AbstractVM::eOperandType::INT16, value));
    } else if (type == "int32") {
        factory.stack.push(factory.createOperand(AbstractVM::eOperandType::INT32, value));
    } else if (type == "float") {
        factory.stack.push(factory.createOperand(AbstractVM::eOperandType::FLOAT, value));
    } else if (type == "double") {
        factory.stack.push(factory.createOperand(AbstractVM::eOperandType::DOUBLE, value));
    } else {
        throw Exception("invalid push instruction");
    }
}

void Parser::assertOperand(std::string const &type, std::string const &value) {
    if (type == "int8") {
        factory.stack.assert(AbstractVM::eOperandType::INT8, value);
    } else if (type == "int16") {
        factory.stack.assert(AbstractVM::eOperandType::INT16, value);
    } else if (type == "int32") {
        factory.stack.assert(AbstractVM::eOperandType::INT32, value);
    } else if (type == "float") {
        factory.stack.assert(AbstractVM::eOperandType::FLOAT, value);
    } else if (type == "double") {
        factory.stack.assert(AbstractVM::eOperandType::DOUBLE, value);
    } else {
        throw Exception("invalid assert instruction");
    }
}

}
