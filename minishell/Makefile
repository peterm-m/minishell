# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 21:06:36 by pedromar          #+#    #+#              #
#    Updated: 2024/03/18 19:24:22 by adiaz-uf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME := minishell

BINARY := minishell

PROJECT_PATH := .

OS := $(shell uname -s)

SHELL := bash

COLOR_PREFIX := e

ifeq ($(OS),Darwin)
	COLOR_PREFIX := 033
endif

BROWN    = \$(COLOR_PREFIX)[0;33m
BLUE     = \$(COLOR_PREFIX)[1;34m
RED      = \$(COLOR_PREFIX)[1;91m
END_COLOR= \$(COLOR_PREFIX)[0m

# Source code directory structure
SRCDIR := src
INCDIR := include
LIBDIR := lib
TESTDIR := .test
BINDIR := .build
LOGDIR := .log

CC := gcc



STD := -std=gnu99

STACK := -fstack-protector-all -Wstack-protector

WARNS := -Wall -Wextra

CFLAGS := -O3 $(STD) $(STACK) $(WARNS)

DEBUG := -g3 

DIR_DUP     = mkdir -p $(@D)
CLEANER     = rm -rvf

# Dependency libraries  
INCLUDE := -I$(INCDIR) -I$(LIBDIR)/dlst -I$(LIBDIR)/libft -I$(LIBDIR)/wrappers -I$(LIBDIR)/readline/8.2.7/include

# 
LIBS := -lreadline -L$(LIBDIR)/readline/8.2.7/lib \
	-ldlst     -L$(LIBDIR)/dlst     \
	-lft       -L$(LIBDIR)/libft

# Test libraries
TEST_LIBS := -L /usr/lib

# Tests binary file
TEST_BINARY := $(BINARY)_test_runner

# %.o file names
NAMES := \
	lexer/lexer.c \
	lexer/tokenize.c \
	lexer/get_tokens1.c \
	lexer/get_tokens2.c \
	lexer/tokenize_utils.c \
	lexer/lexer_utils.c \
	\
	grammar/utils.c \
	grammar/syntax.c \
	grammar/tables.c \
	grammar/rules_grammar1.c \
	grammar/rules_grammar2.c \
	grammar/rules_grammar3.c \
	grammar/rules_grammar4.c \
	grammar/rules_grammar5.c \
	grammar/rules_grammar6.c \
	\
	grammar/semantics/command.c \
	grammar/semantics/cmd_group.c \
	grammar/semantics/cmd_simple.c \
	grammar/semantics/cmd_subshell.c \
	grammar/semantics/element.c \
	grammar/semantics/word.c \
	grammar/semantics/redirections.c \
	grammar/semantics/cmd_connection.c \
	\
	expansion/expander.c \
	expansion/field_splitting.c \
	expansion/parameter_expansion.c \
	expansion/pathname.c \
	expansion/quote_removal.c \
	expansion/tilde_expansion.c \
	\
	subsystem/signals.c \
	subsystem/redirection.c \
	\
	executer/executer.c \
	executer/ft_execle.c \
	\
	builtins/cd.c \
	builtins/echo.c \
	builtins/env.c \
	builtins/exit.c \
	builtins/export.c \
	builtins/pwd.c \
	builtins/unset.c \
	\

NAMES := $(NAMES:%=$(SRCDIR)/%)

OBJECTS := $(NAMES:$(SRCDIR)/%.c=$(BINDIR)/%.o)
BINARYS := $(BINDIR)/$(BINARY)

#
# COMPILATION RULES
#

default: all

# Help message
help:
	@echo "Minishell"
	@echo
	@echo "Target rules:"
	@echo "    all      - Compiles and generates binary file            "
	@echo "    re       - Fclean, Compiles and generates binary file    "
	@echo "    tests    - Compiles with cmocka and run tests binary file"
	@echo "    valgrind - Runs binary file using valgrind tool          "
	@echo "    clean    - Removing object files                         "
	@echo "    fclean   - Removing object files and binary              "
	@echo "    help     - Prints a help message with target rules       "

# Rule for link and generate the binary file
all: make_libs $(BINARYS)
all: make_libs $(BINARYS)

re: fclean all

$(BINARYS): $(OBJECTS) $(BINDIR)/main.o
	@echo -en "$(BROWN)LD $(END_COLOR)";
	$(CC) -o $(BINARYS) $+ $(DEBUG)  $(CFLAGS) $(LIBS)
	@ln -f $(BINARYS) $(PROJECT_PATH)

# Rule for object binaries compilation
$(BINDIR)/%.o: $(SRCDIR)/%.c
	@$(DIR_DUP)
	@echo -en "$(BROWN)CREATED $(END_COLOR)";
	$(CC) -c $^ -o $@ $(DEBUG) $(INCLUDE) $(CFLAGS)

# Rule for cleaning the project
clean:
	@$(CLEANER) $(LOGDIR) $(BINDIR)

# Rule for cleaning the project
fclean: clean fclean_libs
	@$(CLEANER) $(BINDIR) $(BINARY)

# Rule for run valgrind tool
valgrind:
	mkdir -p $(LOGDIR)
	valgrind \
		--track-origins=yes \
		--leak-check=full \
		--leak-resolution=high \
		--log-file=$(LOGDIR)/$@.log \
		$(BINARYS)
	@echo -en "\nCheck the log file: $(LOGDIR)/$@.log\n"

# Compile tests and run the test binary
tests: make_libs $(OBJECTS)
	@echo -en "$(BROWN)CC $(END_COLOR)";
	$(CC) -c $(TESTDIR)/main.c -o $(BINDIR)/main.o $(DEBUG) $(INCLUDE) $(CFLAGS) $(LIBS)
	$(CC) -o $(BINDIR)/$(TEST_BINARY) $(OBJECTS) $(BINDIR)/main.o $(DEBUG)  $(CFLAGS) $(LIBS)
	@which ldconfig && ldconfig -C /tmp/ld.so.cache || true # caching the library linking
	@echo -en "$(BROWN) Running tests: $(END_COLOR)";
	./$(BINDIR)/$(TEST_BINARY)

#
# LIBS RULES
#

make_libs:
	@make -C $(LIBDIR)/dlst
	@make -C $(LIBDIR)/libft
	@make -C $(LIBDIR)/wrappers

clean_libs:
	@make -C $(LIBDIR)/dlst clean
	@make -C $(LIBDIR)/libft clean
	@make -C $(LIBDIR)/wrappers clean

fclean_libs:
	@make -C $(LIBDIR)/dlst fclean
	@make -C $(LIBDIR)/libft fclean
	@make -C $(LIBDIR)/wrappers fclean
