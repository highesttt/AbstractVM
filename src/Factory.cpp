/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Factory
*/

#include "Exception.hpp"
#include "Factory.hpp"
#include "Operand.hpp"
#include <cfloat>
#include <iostream>

namespace AbstractVM {

IOperand *Factory::createOperand(eOperandType type, const std::string &value) {
    return (createType[type])(value);
}

IOperand *Factory::createInt8(const std::string &value) {
    if (std::stoi(value) > INT8_MAX || std::stoi(value) < INT8_MIN)
        throw AbstractVM::Exception("Overflow or underflow on a value");
    return new Operand<int8_t>(value);
}

IOperand *Factory::createInt16(const std::string &value) {
    if (std::stoi(value) > INT16_MAX || std::stoi(value) < INT16_MIN)
        throw AbstractVM::Exception("Overflow or underflow on a value");
    return new Operand<int16_t>(value);
}

IOperand *Factory::createInt32(const std::string &value) {
    try {
        std::stoi(value);
    } catch (std::out_of_range &e) {
        throw AbstractVM::Exception("Overflow or underflow on a value");
    }
    return new Operand<int32_t>(value);
}

IOperand *Factory::createFloat(const std::string &value) {
    try {
        std::stof(value);
    } catch (std::out_of_range &e) {
        throw AbstractVM::Exception("Overflow or underflow on a value");
    }
    return new Operand<float>(value);
}

IOperand *Factory::createDouble(const std::string &value) {
    try {
        std::stod(value);
    } catch (std::out_of_range &e) {
        throw AbstractVM::Exception("Overflow or underflow on a value");
    }
    return new Operand<double>(value);
}

}