/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** IOperand
*/

#pragma once

#include <string>

namespace AbstractVM {

enum eOperandType {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
};

class IOperand {
    public:
        IOperand() = default;

        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual IOperand *clone() const = 0;

        virtual IOperand *operator+(const IOperand &rhs) const = 0;
        virtual IOperand *operator-(const IOperand &rhs) const = 0;
        virtual IOperand *operator*(const IOperand &rhs) const = 0;
        virtual IOperand *operator/(const IOperand &rhs) const = 0;
        virtual IOperand *operator%(const IOperand &rhs) const = 0;

        virtual ~IOperand() = default;
    protected:
    private:
};

}