/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Stack
*/

#pragma once

#include "IOperand.hpp"
#include <memory>
#include <deque>

namespace AbstractVM {

class Stack {
    public:
        Stack();
        ~Stack();

        void push(IOperand *operand);
        void pop();
        void clear();
        void dup();
        void swap();
        void dump() const;
        void assert(eOperandType type, const std::string &value);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void load(size_t const &index);
        void store(size_t const &index);
        void print() const;

        std::deque<IOperand *> stack;
        std::deque<IOperand *> registers;
    protected:
    private:
};

}