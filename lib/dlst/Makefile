
NAME = libdlst.a

SRC_DIR := .

SRCS = \
	ft_dlstclear.c\
	ft_dlstnew.c \
	ft_dlstadd.c \
	ft_dlstlast.c \
	ft_dlstiter.c\
	ft_dlstdelone.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR := .build

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

CC = gcc
DIR_DUP = mkdir -p $(@D)
CLEANER = rm -rf

AR := ar
ARFLAGS  := -r -c -s

CCFLAGS = -Wall -Werror -Wextra

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

all: $(NAME)

$(NAME): $(OBJS)
	@echo -en "$(BROWN)AR $(END_COLOR)";
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo -en "$(BROWN)CREATED $(END_COLOR)";
	@$(DIR_DUP)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(CLEANER) $(BUILD_DIR)

fclean: clean 
	@$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
