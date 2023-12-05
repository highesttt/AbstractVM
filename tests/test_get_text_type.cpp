/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** test_get_text_type
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include "utils.h"
void redirect_all_std(void);

Test(text_type_int8, default, .init=redirect_all_std) {
    AbstractVM::eOperandType input = AbstractVM::eOperandType::INT8;
    std::string expected = "int8";

    cr_assert_eq(getTextType(input), expected);
}

Test(text_type_int16, default, .init=redirect_all_std) {
    AbstractVM::eOperandType input = AbstractVM::eOperandType::INT16;
    std::string expected = "int16";

    cr_assert_eq(getTextType(input), expected);
}

Test(text_type_int32, default, .init=redirect_all_std) {
    AbstractVM::eOperandType input = AbstractVM::eOperandType::INT32;
    std::string expected = "int32";

    cr_assert_eq(getTextType(input), expected);
}

Test(text_type_float, default, .init=redirect_all_std) {
    AbstractVM::eOperandType input = AbstractVM::eOperandType::FLOAT;
    std::string expected = "float";

    cr_assert_eq(getTextType(input), expected);
}

Test(text_type_double, default, .init=redirect_all_std) {
    AbstractVM::eOperandType input = AbstractVM::eOperandType::DOUBLE;
    std::string expected = "double";

    cr_assert_eq(getTextType(input), expected);
}

Test(text_type_unknown, default, .init=redirect_all_std) {
    std::string expected = "unknown";
    AbstractVM::eOperandType input = static_cast<AbstractVM::eOperandType>(-1);

    cr_assert_eq(getTextType(input), expected);
}