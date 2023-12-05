/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** test_instructions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include "utils.h"
void redirect_all_std(void);

Test(is_valid_instruction, default, .init=redirect_all_std) {
    std::string input = "push";
    bool expected = true;

    cr_assert_eq(isValidInstruction(input), expected);
}

Test(is_valid_instruction2, default, .init=redirect_all_std) {
    std::string input = "punsh";
    bool expected = false;

    cr_assert_eq(isValidInstruction(input), expected);
}

Test(is_valid_type, default, .init=redirect_all_std) {
    std::string input = "int8";
    bool expected = true;

    cr_assert_eq(isValidType(input), expected);
}

Test(is_valid_type2, default, .init=redirect_all_std) {
    std::string input = "int4";
    bool expected = false;

    cr_assert_eq(isValidType(input), expected);
}