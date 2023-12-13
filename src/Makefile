NAME        := minishell

SRC_DIR     := .
OBJ_DIR     := .build
SRCS        := \
    minishell.c \
    executer/executer.c \
    parser/lexer/lexer.c \
    parser/syntax/syntax.c \
    subsystem/subsystem.c

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

EXTERN_LIB := -l readline

INTERN_LIB_DIR := ./utils

DLIST := $(INTERN_LIB_DIR)/dlst
RULE_DLIST := $(DLIST)/libdlst.a
I_DLIST := -I$(DLIST)
L_DLIST := -L$(DLIST)
LIB_DLIST := -ldlst

WRAP := $(INTERN_LIB_DIR)/wrappers
RULE_WRAP := $(WRAP)/libwrappers.a
I_WRAP := -I$(WRAP)
L_WRAP := -L$(WRAP)
LIB_WRAP := -lwrappers

INCLUDES    := -I../include $(I_DLIST) $(I_WRAP)

LFLAGS    := $(L_DLIST)  $(L_WRAP)

LIBS = $(EXTERN_LIB) $(LIB_DLIST) $(LIB_WRAP)

all: $(NAME)

$(NAME): $(RULE_DLIST) $(RULE_WRAP) $(OBJS)
	$(CC) $(LFLAGS) $(LIBS) $(INCLUDES)  $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(LFLAGS) $(LIBS) $(INCLUDES) -c -o $@ $<
	$(info CREATED $@)

$(RULE_WRAP):
	$(MAKE) -C $(WRAP)

$(RULE_DLIST):
	$(MAKE) -C $(DLIST)

clean:
	$(MAKE) -C $(DLIST) clean
	$(MAKE) -C $(WRAP) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(DLIST) fclean
	$(MAKE) -C $(WRAP) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
