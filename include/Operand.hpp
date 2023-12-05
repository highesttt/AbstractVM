/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Operand
*/

#pragma once

#include "IOperand.hpp"

namespace AbstractVM {

template <typename T>
class Operand : public IOperand {
    public:
        Operand(const std::string &value);
        ~Operand() = default;

        std::string toString() const override;
        eOperandType getType() const override;
        IOperand *clone() const override;

        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;

    protected:
    private:
        T value;
};

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;

}