/*
** EPITECH PROJECT, 2023
** abstractVM [WSL: Manjaro]
** File description:
** test_colored_messages
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include "utils.h"
void redirect_all_std(void);

Test(colored_messages, test_colored_messages, .init=redirect_all_std) {
    std::string input = "&aa&bb&cc&dd&ee&ff&00&11&22&33&44&55&66&77&88&99";
    std::string expected = "\033[1;32ma\033[1;36mb\033[1;31mc\033[1;35md\033[1;33me\033[1;37mf\033[0;30m0\033[0;34m1\033[0;32m2\033[0;36m3\033[0;31m4\033[0;35m5\033[0;33m6\033[0;37m7\033[1;30m8\033[1;34m9";

    cr_assert_eq(message(input), expected);
}