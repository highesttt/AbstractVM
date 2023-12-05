/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** Exception
*/

#pragma once

#include <exception>
#include <string>

namespace AbstractVM
{

class Exception : public std::exception {
    public:
        Exception(std::string const &message) : message(message) {};
        ~Exception() = default;

        const char *what() const noexcept {
            return message.c_str();
        }

    protected:
    private:
        std::string message;
};

}
