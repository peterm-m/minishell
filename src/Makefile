NAME := minishell

SRC_DIR	 := ./src
OBJ_DIR	 := .build

SRCS := \
	minishell.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC := gcc
CFLAG := -Wall -Wextra -Werror #-g3 -fsanitize=address

INCLUDE := -I../include/minishell.h

RM := rm -f
MAKEFLAG += --no-print-directory
DIR_DUP = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAG) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(INCLUDE) $(CFLAG) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all