/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Stack
*/

#include "Stack.hpp"
#include "Factory.hpp"
#include "Exception.hpp"

#include <iostream>

namespace AbstractVM {

Stack::Stack() {
    registers.resize(16);
    registers.assign(16, nullptr);
}

Stack::~Stack() {
    for (IOperand *operand : stack) {
        if (operand)
            delete operand;
    }
    stack.clear();
    for (IOperand *operand : registers) {
        if (operand)
            delete operand;
    }
    registers.clear();
}

void Stack::push(IOperand * operand) {
    std::deque<IOperand *>::iterator it = stack.begin();

    stack.insert(it, operand);
}

void Stack::pop() {
    std::deque<IOperand *>::iterator it = stack.begin();

    if (stack.size() > 0) {
        delete stack[0];
        stack.erase(it);
    } else {
        throw Exception("Pop on empty stack");
    }
}

void Stack::clear() {
    for (IOperand *operand : stack) {
        if (operand)
            delete operand;
    }
    stack.clear();
}

void Stack::dup() {
    std::deque<IOperand *>::iterator it = stack.begin();

    if (stack.size() > 0) {
        push((*it)->clone());
    } else {
        throw Exception("Dup on empty stack");
    }
}

void Stack::swap() {
    if (stack.size() < 2)
        throw Exception("Swap on stack with less than 2 elements");
    std::swap(stack[0], stack[1]);
}

void Stack::dump() const {
    for (IOperand *operand : stack) {
        std::cout << operand->toString() << std::endl;
    }
}

void Stack::assert(eOperandType type, const std::string &value) {
    if (stack.size() > 0) {
        if (stack[0]->getType() != type || stack[0]->toString() != value) {
            throw Exception("Assert failed");
        }
    } else {
        throw Exception("Assert on empty stack");
    }
}

void Stack::add() {
    if (stack.size() > 1) {
        IOperand *res = *stack[0] + *stack[1];

        pop();
        pop();
        push(res);
    } else {
        throw Exception("Add on stack with less than 2 elements");
    }
}


void Stack::sub() {
    if (stack.size() > 1) {
        IOperand *res = *stack[0] - *stack[1];

        pop();
        pop();
        push(res);
    } else {
        throw Exception("Sub on stack with less than 2 elements");
    }
}

void Stack::mul() {
    if (stack.size() > 1) {
        IOperand *res = *stack[0] * *stack[1];

        pop();
        pop();
        push(res);
    } else {
        throw Exception("Mul on stack with less than 2 elements");
    }
}

void Stack::div() {
    if (stack.size() > 1) {
        IOperand *res = *stack[0] / *stack[1];

        pop();
        pop();
        push(res);
    } else {
        throw Exception("Div on stack with less than 2 elements");
    }
}

void Stack::mod() {
    if (stack.size() > 1) {
        IOperand *res = *stack[0] % *stack[1];

        pop();
        pop();
        push(res);
    } else {
        throw Exception("Mod on stack with less than 2 elements");
    }
}

void Stack::load(size_t const &index) {
    if (index > 15) {
        throw Exception("Invalid index");
    }

    if (registers[index] != nullptr) {
        push(registers[index]->clone());
    } else {
        throw Exception("Register is empty");
    }
}

void Stack::store(size_t const &index) {
    if (index > 15) {
        throw Exception("Invalid index");
    }
    if (stack.size() > 0) {
        Factory Factory;
        registers[index] = stack[0]->clone();
        pop();
    } else {
        throw Exception("Store on empty stack");
    }
}

void Stack::print() const {
    if (stack.size() > 0) {
        if (stack[0]->getType() == INT8) {
            std::cout << static_cast<char>(std::stoi(stack[0]->toString())) << std::endl;
        } else {
            throw Exception("Print on non INT8 value");
        }
    } else {
        throw Exception("Print on empty stack");
    }
}

}