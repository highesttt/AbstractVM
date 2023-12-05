/*
** EPITECH PROJECT, 2023
** Arcade-C++ [WSL: Manjaro]
** File description:
** ColoredMessages
*/

#include <iostream>

std::string message(std::string &str) {
    std::string::size_type pos = 0;
    while ((pos = str.find("&a", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[1;32m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&b", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[1;36m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&c", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[1;31m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&d", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[1;35m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&e", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[1;33m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&f", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[1;37m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&1", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[0;34m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&2", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[0;32m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&3", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[0;36m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&4", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[0;31m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&5", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[0;35m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&6", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[0;33m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&7", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[0;37m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&8", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[1;30m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&9", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[1;34m");
        pos += 2;
    }
    pos = 0;
    while ((pos = str.find("&0", pos)) != std::string::npos) {
        str.replace(pos, 2, "\033[0;30m");
        pos += 2;
    }
    return str;
}
