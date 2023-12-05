/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Factory
*/

#pragma once

#include "IOperand.hpp"
#include "Stack.hpp"

namespace AbstractVM {

class Factory {
    public:
        Factory() : stack(Stack()) {};
        ~Factory() = default;

        static IOperand *createOperand(eOperandType type, const std::string &value);

        Stack stack;
    protected:
    private:
        static IOperand *createInt8(const std::string &value);
        static IOperand *createInt16(const std::string &value);
        static IOperand *createInt32(const std::string &value);
        static IOperand *createFloat(const std::string &value);
        static IOperand *createDouble(const std::string &value);

        static constexpr IOperand *(*createType[5])(const std::string &value) = {
            &Factory::createInt8,
            &Factory::createInt16,
            &Factory::createInt32,
            &Factory::createFloat,
            &Factory::createDouble
        };
};

}