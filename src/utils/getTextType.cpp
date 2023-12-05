/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** getTextType
*/

#include "utils.h"

std::string getTextType(AbstractVM::eOperandType const &type) {
    switch (type) {
        case AbstractVM::eOperandType::INT8:
            return "int8";
        case AbstractVM::eOperandType::INT16:
            return "int16";
        case AbstractVM::eOperandType::INT32:
            return "int32";
        case AbstractVM::eOperandType::FLOAT:
            return "float";
        case AbstractVM::eOperandType::DOUBLE:
            return "double";
        default:
            return "unknown";
    }
}