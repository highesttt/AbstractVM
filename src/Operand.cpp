/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Operand
*/

#include "Operand.hpp"
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include "utils.h"
#include "Factory.hpp"
#include "Exception.hpp"
#include <iostream>

namespace AbstractVM {

template <typename T>
Operand<T>::Operand(const std::string &value) {
    if (typeid(T) == typeid(int8_t))
        this->value = static_cast<T>(std::stoi(value));
    else if (typeid(T) == typeid(int16_t))
        this->value = static_cast<T>(std::stoi(value));
    else if (typeid(T) == typeid(int32_t))
        this->value = static_cast<T>(std::stoi(value));
    else if (typeid(T) == typeid(float))
        this->value = static_cast<T>(std::stof(value));
    else
        this->value = static_cast<T>(std::stod(value));
}

template <typename T>
eOperandType Operand<T>::getType() const {
    if (typeid(T) == typeid(int8_t))
        return INT8;
    else if (typeid(T) == typeid(int16_t))
        return INT16;
    else if (typeid(T) == typeid(int32_t))
        return INT32;
    else if (typeid(T) == typeid(float))
        return FLOAT;
    else
        return DOUBLE;
}

template <typename T>
IOperand *Operand<T>::clone() const {
    return new Operand<T>(this->toString());
}

template <typename T>
std::string Operand<T>::toString() const {
    std::string str = std::to_string(this->value);

    if (!(typeid(T) != typeid(float) && typeid(T) != typeid(double))) {
        size_t precision = 0;
        if (this->getType() == FLOAT)
            precision = 7;
        else
            precision = 15;

        std::stringstream ss;
        ss.unsetf(std::ios::floatfield);
        ss.precision(precision);
        ss << this->value;
        str = ss.str();

    }
    return str;
}

template <typename T>
IOperand *Operand<T>::operator+(const IOperand &rhs) const {
    if (this->getType() > rhs.getType()) {
        if (typeid(T) != typeid(float) && typeid(T) != typeid(double) && typeid(rhs) != typeid(float) && typeid(rhs) != typeid(double)) {
            return Factory().createOperand(this->getType(), std::to_string(std::stoi(rhs.toString()) + this->value));
        } else if (typeid(T) == typeid(float)) {
            return Factory().createOperand(FLOAT, std::to_string(std::stof(rhs.toString()) + this->value));
        } else {
            return Factory().createOperand(DOUBLE, std::to_string(std::stod(rhs.toString()) + this->value));
        }
    } else {
        return Factory().createOperand(rhs.getType(), getStringWithPrecision(std::stod(rhs.toString()) + this->value, 16));
    }
}

template <typename T>
IOperand *Operand<T>::operator-(const IOperand &rhs) const {
    if (this->getType() > rhs.getType()) {
        if (typeid(T) != typeid(float) && typeid(T) != typeid(double) && rhs.getType() != FLOAT && rhs.getType() != DOUBLE) {
            return Factory().createOperand(this->getType(), std::to_string(std::stoi(rhs.toString()) - this->value));
        } else if (typeid(T) == typeid(float)) {
            return Factory().createOperand(FLOAT, std::to_string(std::stof(rhs.toString()) - this->value));
        } else {
            return Factory().createOperand(DOUBLE, std::to_string(std::stod(rhs.toString()) - this->value));
        }
    } else {
        return Factory().createOperand(rhs.getType(), getStringWithPrecision(std::stod(rhs.toString()) - this->value, 16));
    }
}

template <typename T>
IOperand *Operand<T>::operator*(const IOperand &rhs) const {
    if (this->getType() > rhs.getType()) {
        if (typeid(T) != typeid(float) && typeid(T) != typeid(double) && rhs.getType() != FLOAT && rhs.getType() != DOUBLE) {
            return Factory().createOperand(this->getType(), std::to_string(std::stoi(rhs.toString()) * this->value));
        } else if (typeid(T) == typeid(float)) {
            return Factory().createOperand(FLOAT, std::to_string(std::stof(rhs.toString()) * this->value));
        } else {
            return Factory().createOperand(DOUBLE, std::to_string(std::stod(rhs.toString()) * this->value));
        }
    } else {
        return Factory().createOperand(rhs.getType(), getStringWithPrecision(std::stod(rhs.toString()) * this->value, 16));
    }
}

template <typename T>
IOperand *Operand<T>::operator/(const IOperand &rhs) const {
    if (this->value == 0)
        throw Exception("Division by zero");

    if (this->getType() > rhs.getType()) {
        if (typeid(T) != typeid(float) && typeid(T) != typeid(double) && rhs.getType() != FLOAT && rhs.getType() != DOUBLE) {
            return Factory().createOperand(this->getType(), std::to_string(std::stoi(rhs.toString()) / this->value));
        } else if (typeid(T) == typeid(float)) {
            return Factory().createOperand(FLOAT, std::to_string(std::stof(rhs.toString()) / this->value));
        } else {
            return Factory().createOperand(DOUBLE, std::to_string(std::stod(rhs.toString()) / this->value));
        }
    } else {
        return Factory().createOperand(rhs.getType(), getStringWithPrecision(std::stod(rhs.toString()) / this->value, 16));
    }
}

template <typename T>
IOperand *Operand<T>::operator%(const IOperand &rhs) const {
    if (this->value == 0)
        throw Exception("Modulo by zero");

    if (this->getType() > rhs.getType()) {
        if (typeid(T) != typeid(float) && typeid(T) != typeid(double) && rhs.getType() != FLOAT && rhs.getType() != DOUBLE) {
            return Factory().createOperand(this->getType(), std::to_string(std::stoi(rhs.toString()) % std::stoi(this->toString())));
        } else if (typeid(T) == typeid(float)) {
            return Factory().createOperand(FLOAT, std::to_string(std::fmod(std::stof(rhs.toString()), this->value)));
        } else {
            return Factory().createOperand(DOUBLE, std::to_string(std::fmod(std::stod(rhs.toString()), this->value)));
        }
    } else {
        return Factory().createOperand(rhs.getType(), getStringWithPrecision(std::fmod(std::stod(rhs.toString()), this->value), 16));
    }
}

}