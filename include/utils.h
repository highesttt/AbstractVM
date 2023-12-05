/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** abstractVM
*/

#pragma once

#include <string>
#include "IOperand.hpp"

// utils
std::string message(std::string &str);
bool isValidInstruction(const std::string &line);
bool isValidType(const std::string &line);
std::string getStringWithPrecision(double const &str, const int &precision);
std::string getTextType(const AbstractVM::eOperandType &type);