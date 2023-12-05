/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** test_floats
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include "Parser.hpp"
#include "utils.h"
void redirect_all_std(void);

// Test Floats
Test(float_with_infinite_precision, default, .init=redirect_all_std) {
    std::istringstream file("push float(2)\npush float(3)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("0.6666667\n");
}
Test(float_with_99999999, default, .init=redirect_all_std) {
    std::istringstream file("push float(99999999)\npush float(100000000)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("1\n");
}

Test(float_multiplication, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush float(3)\nmul\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("6.3\n");
}

Test(float_addition, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush float(3)\nadd\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("5.1\n");
}

Test(float_substraction, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush float(3)\nsub\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("-0.9\n");
}

Test(float_division, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush float(3)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("0.7\n");
}

Test(float_modulo, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush float(3)\nmod\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("2.1\n");
}

Test(float_modulo_with_int8, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush int8(3)\nmod\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("2.1\n");
}

Test(float_modulo_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush double(3)\nmod\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("2.1\n");
}

Test(float_division_with_int8, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush int8(3)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("0.7\n");
}

Test(float_division_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush double(3)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("0.7\n");
}

Test(float_addition_with_int8, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush int8(3)\nadd\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("5.1\n");
}

Test(float_addition_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush double(3)\nadd\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("5.1\n");
}

Test(float_substraction_with_int8, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush int8(3)\nsub\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("-0.9\n");
}

Test(float_substraction_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush double(3)\nsub\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("-0.9\n");
}

Test(float_multiplication_with_int8, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush int8(3)\nmul\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("6.3\n");
}

Test(float_multiplication_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push float(2.1)\npush double(3)\nmul\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("6.3\n");
}

// Test int8

Test(int8_division, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush int8(3)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("0\n");
}

Test(int8_modulo, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush int8(3)\nmod\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("2\n");
}

Test(int8_division_with_int16, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush int8(3)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("0\n");
}

Test(int8_modulo_with_int16, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush int8(3)\nmod\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("2\n");
}

Test(int8_division_with_float, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush float(3)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("0.666667\n");
}

Test(int8_modulo_with_float, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush float(3)\nmod\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("2\n");
}

Test(int8_division_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush double(3)\ndiv\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("0.666667\n");
}

Test(int8_modulo_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush double(3)\nmod\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("2\n");
}

Test(int8_addition_with_int16, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush int8(3)\nadd\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("5\n");
}

Test(int8_addition_with_float, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush float(3)\nadd\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("5\n");
}

Test(int8_addition_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush double(3)\nadd\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("5\n");
}

Test(int8_substraction_with_int16, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush int8(3)\nsub\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("-1\n");
}

Test(int8_substraction_with_float, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush float(3)\nsub\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("-1\n");
}

Test(int8_substraction_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush double(3)\nsub\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("-1\n");
}

Test(int8_multiplication_with_int16, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush int8(3)\nmul\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("6\n");
}

Test(int8_multiplication_with_float, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush float(3)\nmul\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("6\n");
}

Test(int8_multiplication_with_double, default, .init=redirect_all_std) {
    std::istringstream file("push int8(2)\npush double(3)\nmul\ndump\nexit\n");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("6\n");
}