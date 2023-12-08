NAME := minishell

SRC_DIR	 := ./
OBJ_DIR	 := .build
PARSE_DIR = parseR/

SRCS := \
	minishell.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC := gcc
CFLAG := -Wall -Wextra -Werror  #-g3 -fsanitize=address
RFLAG := -lreadline
INCLUDE := -I../include/

RM := rm -f
MAKEFLAG += --no-print-directory
DIR_DUP = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAG) $(RFLAG) -o $(NAME)
	$(info CREATED $(NAME))
	$(MAKE) -C $(PARSE_DIR)

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