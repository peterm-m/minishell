NAME        := minishell

SRC_DIR     := .
OBJ_DIR     := .build

SRC_MAIN := $(SRC_MAIN:%=$(SRC_DIR)/%)
OBJS_MAIN := $(SRC_MAIN:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS        := \
	minishell.c \
	lexer/lexer.c \
	lexer/tokenize.c \
	lexer/get_tokens1.c \
	lexer/get_tokens2.c \
	lexer/tokenize_utils.c \
	lexer/lexer_utils.c \
	\
	grammar/utils.c \
	grammar/syntax.c \
	grammar/rules1.c \
	grammar/rules2.c \
	grammar/rules3.c \
	grammar/rules4.c \
	grammar/tables.c \
	\
	grammar/semantics/command.c \
	grammar/semantics/cmd_group.c \
	grammar/semantics/cmd_simple.c \
	grammar/semantics/cmd_subshell.c \
	grammar/semantics/element.c \
	grammar/semantics/word.c \
	grammar/semantics/redirections.c \
	grammar/semantics/cmd_conection.c \
	\
	executer/executer.c \
	\
	expansion/expander.c \
	\
	subsystem/subsystem.c \
	subsystem/get_env.c \
	subsystem/env_list_utils.c

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -g

RM          := rm -rf
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

EXTERN_LIB := -lreadline

INTERN_LIB_DIR := ./utils

FT := $(INTERN_LIB_DIR)/libft
RULE_FT := $(FT)/libft.a
I_FT := -I$(FT)
L_FT := -L$(FT)
LIB_FT := -lft

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

INCLUDES    := -I../include $(I_DLIST) $(I_WRAP) $(I_FT)

LFLAGS    := $(L_DLIST) $(L_WRAP) $(L_FT)

LIBS := $(EXTERN_LIB) $(LIB_DLIST) $(LIB_FT) $(LIB_WRAP)

all: LIBS+=-lwrappers
all: $(RULE_WRAP) $(RULE_DLIST) $(RULE_FT) $(OBJS) $(OBJS_MAIN)
all: OBJS+=$(OBJS_MAIN)
all: $(NAME)

debug: CFLAGS+=-DDEBUG
debug: $(NAME)

test:
	@$(MAKE) -C .test run

$(NAME):
	@$(CC) $(OBJS) -o $(NAME) $(LFLAGS) $(INCLUDES) $(LIBS)
	@$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	@$(info CREATED $@)

$(RULE_WRAP):
	@$(MAKE) -C $(WRAP)

$(RULE_DLIST):
	@$(MAKE) -C $(DLIST)

$(RULE_FT):
	@$(MAKE) -C $(FT)

clean:
	@$(MAKE) -C $(FT) clean
	@$(MAKE) -C $(DLIST) clean
	@$(MAKE) -C $(WRAP) clean
	@$(MAKE) -C .test clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(FT) fclean
	@$(MAKE) -C $(DLIST) fclean
	@$(MAKE) -C $(WRAP) fclean
	@$(MAKE) -C .test fclean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re test 