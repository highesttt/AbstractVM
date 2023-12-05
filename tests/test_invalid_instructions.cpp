/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** test_invalid_instructions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "Parser.hpp"
void redirect_all_std(void);

Test(unknown_instruction, default, .init=redirect_all_std) {
    std::istringstream file("punsh int32(5)\ndump\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Unknown instruction\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_push, default, .init=redirect_all_std) {
    std::istringstream file("push int(82)\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e invalid push instruction\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_pop, default, .init=redirect_all_std) {
    std::istringstream file("pop\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Pop on empty stack\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_assert, default, .init=redirect_all_std) {
    std::istringstream file("assert int8(0)\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Assert on empty stack\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_assert2, default, .init=redirect_all_std) {
    std::istringstream file("push int8(1)\nassert int8(0)\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 2:&e Assert failed\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_assert3, default, .init=redirect_all_std) {
    std::istringstream file("push int8(1)\nassert int4(18)\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 2:&e invalid assert instruction\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_add, default, .init=redirect_all_std) {
    std::istringstream file("add\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Add on stack with less than 2 elements\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_sub, default, .init=redirect_all_std) {
    std::istringstream file("sub\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Sub on stack with less than 2 elements\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_mul, default, .init=redirect_all_std) {
    std::istringstream file("mul\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Mul on stack with less than 2 elements\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_div, default, .init=redirect_all_std) {
    std::istringstream file("div\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Div on stack with less than 2 elements\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_mod, default, .init=redirect_all_std) {
    std::istringstream file("mod\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Mod on stack with less than 2 elements\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_print, default, .init=redirect_all_std) {
    std::istringstream file("print\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Print on empty stack\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_print2, default, .init=redirect_all_std) {
    std::istringstream file("push int16(1)\nprint\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 2:&e Print on non INT8 value\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_dup, default, .init=redirect_all_std) {
    std::istringstream file("dup\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Dup on empty stack\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_swap, default, .init=redirect_all_std) {
    std::istringstream file("swap\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Swap on stack with less than 2 elements\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_load, default, .init=redirect_all_std) {
    std::istringstream file("load int8(16)\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Invalid index\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_load2, default, .init=redirect_all_std) {
    std::istringstream file("load int8(0)\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Register is empty\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_store, default, .init=redirect_all_std) {
    std::istringstream file("store int8(16)\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Invalid index\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_store2, default, .init=redirect_all_std) {
    std::istringstream file("store int8(0)\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e Store on empty stack\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(invalid_store3, default, .init=redirect_all_std) {
    std::istringstream file("store 3\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 1:&e invalid store instruction\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(division_by_zero_int8, default, .init=redirect_all_std) {
    std::istringstream file("push int8(1)\npush int8(0)\ndiv\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Division by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(division_by_zero_int16, default, .init=redirect_all_std) {
    std::istringstream file("push int16(1)\npush int16(0)\ndiv\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Division by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(division_by_zero_int32, default, .init=redirect_all_std) {
    std::istringstream file("push int32(1)\npush int32(0)\ndiv\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Division by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(division_by_zero_float, default, .init=redirect_all_std) {
    std::istringstream file("push float(1.0)\npush float(0.0)\ndiv\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Division by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(division_by_zero_double, default, .init=redirect_all_std) {
    std::istringstream file("push double(1.0)\npush double(0.0)\ndiv\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Division by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(modulo_by_zero_int8, default, .init=redirect_all_std) {
    std::istringstream file("push int8(1)\npush int8(0)\nmod\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Modulo by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(modulo_by_zero_int16, default, .init=redirect_all_std) {
    std::istringstream file("push int16(1)\npush int16(0)\nmod\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Modulo by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(modulo_by_zero_int32, default, .init=redirect_all_std) {
    std::istringstream file("push int32(1)\npush int32(0)\nmod\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Modulo by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(modulo_by_zero_float, default, .init=redirect_all_std) {
    std::istringstream file("push float(1.0)\npush float(0.0)\nmod\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Modulo by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}

Test(modulo_by_zero_double, default, .init=redirect_all_std) {
    std::istringstream file("push double(1.0)\npush double(0.0)\nmod\nexit\n;;");
    std::cin.rdbuf(file.rdbuf());
    try {
        AbstractVM::Parser parser;
        parser.parse(std::cin);
    } catch (std::exception &e) {

        std::cerr << e.what() << std::endl;
        std::string error = "&cline 3:&e Modulo by zero\n";
        cr_assert_stderr_eq_str(message(error).c_str());
    }
}