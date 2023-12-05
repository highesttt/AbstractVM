/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "Parser.hpp"

void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(basic_5, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/basic_5.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("5\n");
}

Test(basic_AT_Test, default, .init=redirect_all_std) {
    std::ifstream file("./doc/example.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("42\n42.42\n3341.25\n");
}

Test(basic_stdin_1, default, .init=redirect_all_std) {
    std::istringstream file("push int32(5)\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(std::cin);
    cr_assert_stdout_eq_str("5\n");
}

Test(all_types_and_all_functions, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/all_types_and_all_functions.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("-3.055414\n3\n2\n1\n1\n2\n1\n1\n1\n3\n9\n3\n3\n3\n");
}

Test(all_operations_int8, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/all_operations_int8.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("1\n0\n");
}

Test(all_operations_int16, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/all_operations_int16.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("1\n0\n");
}

Test(all_operations_int32, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/all_operations_int32.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("1\n0\n");
}

Test(all_operations_float, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/all_operations_float.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("1\n0\n");
}

Test(all_operations_double, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/all_operations_double.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("1\n");
}

Test(divide_between_two_ints, default, .init=redirect_all_std) {
    std::istringstream file("push int16(5)\npush int32(2)\ndiv\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("2\n");
}

Test(modulo_between_two_ints, default, .init=redirect_all_std) {
    std::istringstream file("push int16(5)\npush int32(2)\nmod\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("1\n");
}

Test(substract_between_two_ints, default, .init=redirect_all_std) {
    std::istringstream file("push int16(5)\npush int32(2)\nsub\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("3\n");
}

Test(missing_exit, default, .init=redirect_all_std) {
    std::istringstream file("push int32(5)\ndump\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
    parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&eMissing exit instruction\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(register_tests, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/register_tests.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    AbstractVM::Parser parser;
    parser.parse(file);
    cr_assert_stdout_eq_str("1\n1\n1\n");
}