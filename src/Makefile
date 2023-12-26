NAME        := minishell

SRC_DIR     := .
OBJ_DIR     := .build

SRCS        := \
	minishell.c \
	executer/executer.c \
	parser/lexer/lexer.c \
	parser/lexer/tokenize.c \
	parser/lexer/get_tokens.c \
	parser/lexer/tokenize_utils.c \
	parser/lexer/lexer_utils.c \
	parser/syntax/syntax.c \
	subsystem/subsystem.c

TEST      := test

SRCS_TEST := \
	.test/test.c \
	executer/executer.c \
	parser/lexer/lexer.c \
	parser/lexer/tokenize.c \
	parser/lexer/get_tokens.c \
	parser/lexer/tokenize_utils.c \
	parser/lexer/lexer_utils.c \
	parser/syntax/tree.c \
	parser/syntax/syntax.c \
	subsystem/subsystem.c

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_TEST   := $(SRCS_TEST:%=$(SRC_DIR)/%)
OBJS_TEST   := $(SRCS_TEST:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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

INCLUDES    := -I../include $(I_DLIST) $(I_WRAP)  $(I_FT)

LFLAGS    := $(L_DLIST)  $(L_WRAP) $(L_FT)

LIBS = $(EXTERN_LIB) $(LIB_DLIST) $(LIB_WRAP) $(LIB_FT)

all: $(NAME)

test: $(TEST)

$(NAME): $(RULE_DLIST) $(RULE_WRAP) $(RULE_FT) $(OBJS)
	@$(CC) $(LFLAGS) $(LIBS) $(INCLUDES)  $(OBJS) -o $(NAME)
	@$(info CREATED $(NAME))

$(TEST): $(RULE_DLIST) $(RULE_WRAP) $(OBJS_TEST)
	@$(CC) $(LFLAGS) $(LIBS) $(INCLUDES)  $(OBJS_TEST) -o $(TEST)
	@$(info CREATED $(TEST))

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

run: $(TEST)
	./$(TEST)

mem_test: $(TEST)
	valgrind valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TEST)

clean:
	@$(MAKE) -C $(FT) clean
	@$(MAKE) -C $(DLIST) clean
	@$(MAKE) -C $(WRAP) clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(FT) fclean
	@$(MAKE) -C $(DLIST) fclean
	@$(MAKE) -C $(WRAP) fclean
	@$(RM) $(TEST)
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: clean fclean re
