/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** test_overflows
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "Parser.hpp"
#include "Factory.hpp"
void redirect_all_std(void);

Test(overflow, default, .init=redirect_all_std) {
    std::ifstream file("./tests/AbstractTests/overflow_int8.avm");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    try {
        AbstractVM::Parser parser;
        parser.parse(file);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(overflows_cin, default, .init=redirect_all_std) {
    std::istringstream file("push int16(32768)\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(overflows_cin2, default, .init=redirect_all_std) {
    std::istringstream file2("push int32(2147483648)\ndump\nexit\n;;");
    std::cin.rdbuf(file2.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(overflows_cin3, default, .init=redirect_all_std) {
    std::istringstream file3("push float(390000000000000000000000000000000000000)\ndump\nexit\n;;");
    std::cin.rdbuf(file3.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(overflows_cin4, default, .init=redirect_all_std) {
    std::istringstream file4("push double(180000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)\ndump\nexit\n;;");
    std::cin.rdbuf(file4.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(overflow_in_factory_int32, default, .init=redirect_all_std) {
    try {
        AbstractVM::Factory factory;
        factory.createOperand(AbstractVM::eOperandType::INT32, "2147483648");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        cr_assert_stderr_eq_str("Overflow or underflow on a value\n");
    }
}

Test(overflow_in_factory_float, default, .init=redirect_all_std) {
    try {
        AbstractVM::Factory factory;
        factory.createOperand(AbstractVM::eOperandType::FLOAT, "390000000000000000000000000000000000000");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        cr_assert_stderr_eq_str("Overflow or underflow on a value\n");
    }
}

Test(overflow_in_factory_double, default, .init=redirect_all_std) {
    try {
        AbstractVM::Factory factory;
        factory.createOperand(AbstractVM::eOperandType::DOUBLE, "180000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        cr_assert_stderr_eq_str("Overflow or underflow on a value\n");
    }
}

Test(overflow_by_adding, default, .init=redirect_all_std) {
    std::istringstream file("push int8(127)\npush int8(1)\nadd\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(underflow_by_adding, default, .init=redirect_all_std) {
    std::istringstream file("push int8(-128)\npush int8(-123)\nadd\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(overflow_by_subtracting, default, .init=redirect_all_std) {
    std::istringstream file("push int8(-128)\npush int8(1)\nsub\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(underflow_by_subtracting, default, .init=redirect_all_std) {
    std::istringstream file("push int8(127)\npush int8(-128)\nsub\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(overflow_by_multiplying, default, .init=redirect_all_std) {
    std::istringstream file("push int8(127)\npush int8(2)\nmul\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(underflow_by_multiplying, default, .init=redirect_all_std) {
    std::istringstream file("push int8(-128)\npush int8(2)\nmul\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(overflow_by_dividing, default, .init=redirect_all_std) {
    std::istringstream file("push float(240282346638528859811704183484516925440)\npush float(0.5)\ndiv\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(underflow_by_dividing, default, .init=redirect_all_std) {
    std::istringstream file("push float(-240282346638528859811704183484516925440)\npush float(0.5)\ndiv\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Overflow or underflow on a value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}
