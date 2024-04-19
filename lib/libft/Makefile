# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 18:04:07 by adiaz-uf          #+#    #+#              #
#    Updated: 2024/04/19 18:11:36 by pedromar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR := .

SRCS = \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strmapi.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strnjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_striteri.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstlast.c \
	ft_lstsize.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstclear.c \
	ft_lstmap.c 

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
