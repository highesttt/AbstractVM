##
## EPITECH PROJECT, 2023
## abstractVM [WSL: Manjaro]
## File description:
## Makefile
##

# NAME: Name of the executable
NAME    =   abstractVM

# CC: Compiler
CC      =   g++

# SRC: Source files
SRC     =   $(wildcard src/*.cpp) \
            $(wildcard src/utils/*.cpp)
# OBJ: Object files
OBJ 	= 	$(SRC:src/%.cpp=$(BUILDDIR)/%.o)

# TESTSRC: Source files for tests
TESTSRC =   $(wildcard tests/*.cpp)
# TESTOBJ: Object files for tests
TESTOBJ =   $(TESTSRC:tests/%.cpp=$(BUILDDIR)/%.o)

# BONUS: Source files for bonus
BONUS	=	$(wildcard bonus/*.cpp)
# BONUSOBJ: Object files for bonus
BONUSOBJ =  $(BONUS:bonus/%.cpp=$(BUILDDIR)/bonus/%.o)

# BUILDDIR: Directory where object files will be stored
BUILDDIR = obj

# Create the build directory
$(BUILDDIR):
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR)/utils
	@mkdir -p $(BUILDDIR)/bonus

# TESTDIR: Directory where tests files will be stored
TESTDIR =   tests

# CFLAGS: Flags for the compiler
CFLAGS  =   -I ./include/ -I ./interfaces
CFLAGS  +=  -Wall -Wextra -Werror -std=c++20

# Build rules
$(BUILDDIR)/%.o: src/%.cpp | $(BUILDDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e "\e[01m\e[33m    Compiling...\
		\e[00m\e[39m$<\e[032m [OK]\e[00m"

# Rules for make all
all: $(NAME)

# Rules for make
$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\e[36;1m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\
	\e[0m"
	@echo -e "\e[36;1mIf you need help, use the command './$(NAME) -h'\
	\e[0m"
	@echo -e "\e[36;1m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\
	\e[0m"

# Rules for make clean, fclean, re
clean:
	@rm -rf $(BUILDDIR)
	@find . -name "*.gcda" -delete
	@find . -name "*.gcov" -delete
	@find . -name "*.gcno" -delete
	@rm -f ./unit_tests
	@echo -e "\e[31;1mAll object files have been removed.\e[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -rf html
	@echo -e "\e[38;5;210m$(NAME)\e[0m\e[38;5;196m has been removed.\e[0m"

re: fclean all
	@echo -e "\e[38;5;42m$(NAME)\e[0m\e[32;1m has been recompiled.\e[0m"

# Rules for make debug
debug: re
debug: CFLAGS += -g -fsanitize=address

# Rules for make debug_no_re
debug_no_re: CFLAGS += -g -fsanitize=address
debug_no_re: $(NAME)

# Rules for make tests_run
tests_compile: CFLAGS += -lcriterion --coverage -fprofile-abs-path
tests_compile: SRC := $(filter-out src/main.cpp, $(SRC))
tests_compile: $(TESTOBJ) $(OBJ)
	@$(CC) -o unit_tests $(TESTOBJ) $(OBJ) $(CFLAGS)

# Build rules for tests
$(BUILDDIR)/%.o: tests/%.cpp | $(BUILDDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e "\e[01m\e[33m    Compiling...\
		\e[00m\e[39m$<\e[032m [OK]\e[00m"

# Rules for make tests_display
tests_display:
	./unit_tests

# Rules for make tests_run
tests_run: tests_compile tests_display

# Rules for make cover
cover:
	@gcovr ./obj/ --exclude tests --exclude src/main.cpp --exclude include \
	--exclude interfaces
	@gcovr ./obj/ --branches --exclude tests --exclude src/main.cpp --exclude include \
	--exclude interfaces
	@rm -f unit_tests*

# Rules for make htmlcover
htmlcover:
	@mkdir -p html
	@gcovr ./obj --html-details html/$(NAME).html $(FLAGS) \
	--exclude src/main.cpp --exclude tests --exclude include \
	--exclude interfaces

# Rules for make bonus
bonus: CFLAGS += -I ./bonus/include/ -lsfml-graphics -lsfml-window -lsfml-system
bonus: SRC := $(filter-out src/main.cpp, $(SRC))
bonus: $(BONUSOBJ) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(BONUSOBJ) $(CFLAGS)
	@echo -e "\e[36;1m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\
	\e[0m"
	@echo -e "\e[36;1mTo launch the program, type \e[32;1m./$(NAME)\e[36;1m\
	\e[0m"
	@echo -e "\e[36;1m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\
	\e[0m"

# Build rules for bonus
$(BUILDDIR)/bonus/%.o: bonus/%.cpp | $(BUILDDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e "\e[01m\e[33m    Compiling...\
		\e[00m\e[39m$<\e[032m [OK]\e[00m"

# Rules for make bonus_re
bonus_re: fclean bonus

# Rules for make bonus_debug
bonus_debug: CFLAGS += -g -fsanitize=address
bonus_debug: bonus_re

# .PHONY: All rules
.PHONY: all clean fclean re debug debug_no_re tests_compile tests_display \
	tests_run cover htmlcover
