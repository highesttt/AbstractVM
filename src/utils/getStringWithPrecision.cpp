/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** getStringWithPrecision
*/

#include <string>
#include <sstream>
#include <iomanip>


std::string getStringWithPrecision(double const &num, const int &precision) {
    std::string str;
    std::stringstream ss;

    ss.unsetf(std::ios::floatfield);
    ss.precision(precision);
    ss << num;
    str = ss.str();

    return str;
}