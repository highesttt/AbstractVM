/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** isValidInstruction
*/

#include "utils.h"
#include <regex>

bool isValidInstruction(const std::string &line) {
    std::regex regex("push|pop|dump|assert|add|sub|mul|div|mod|print|exit|;;");

    return std::regex_match(line, regex);
}

bool isValidType(const std::string &line) {
    std::regex regex("int8|int16|int32|float|double");

    return std::regex_match(line, regex);
}
