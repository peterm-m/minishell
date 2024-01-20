NAME        := minishell

SRC_DIR     := .
OBJ_DIR     := .build

SRC_MAIN := minishell.c \

SRC_MAIN := $(SRC_MAIN:%=$(SRC_DIR)/%)
OBJS_MAIN := $(SRC_MAIN:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_TEST := .test/test.c \
	.test/test_syntax.c \

SRC_TEST := $(SRC_TEST:%=$(SRC_DIR)/%)
OBJS_TEST := $(SRC_TEST:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS        := \
	executer/executer.c \
	executer/expander.c \
	parser/lexer/lexer.c \
	parser/lexer/tokenize.c \
	parser/lexer/get_tokens.c \
	parser/lexer/tokenize_utils.c \
	parser/lexer/lexer_utils.c \
	\
	parser/syntax/utils.c \
	parser/syntax/syntax.c \
	parser/syntax/rules1.c \
	parser/syntax/rules2.c \
	parser/syntax/rules3.c \
	parser/syntax/tables.c \
	\
	parser/syntax/semantics/command.c \
	parser/syntax/semantics/cmd_group.c \
	parser/syntax/semantics/cmd_simple.c \
	parser/syntax/semantics/cmd_subshell.c \
	parser/syntax/semantics/element.c \
	parser/syntax/semantics/redirections.c \
	parser/syntax/semantics/cmd_conection.c \
	\
	subsystem/subsystem.c

TEST      := test

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -g 

RM          := rm -rf
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

EXTERN_LIB := -lreadline

INTERN_LIB_DIR := ./utils

#DBG := $(INTERN_LIB_DIR)/debug
#RULE_DBG := $(DBG)/libdbg.a
#I_DBG := -I$(DBG)
#L_DBG := -L$(DBG)
#LIB_DBG := -ldbg

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

LIBS := $(EXTERN_LIB) $(LIB_DLIST) $(LIB_WRAP) $(LIB_FT)

all: $(RULE_DLIST) $(RULE_WRAP) $(RULE_FT) $(OBJS) $(OBJS_MAIN)
all: OBJS+=$(OBJS_MAIN)
all: $(NAME)

test: fclean
test: $(RULE_DLIST) $(RULE_WRAP) $(RULE_FT) $(OBJS) $(OBJS_TEST)
test: OBJS+=$(OBJS_TEST)
test: $(NAME)

$(NAME):
	@$(CC)  $(OBJS) -o $(NAME) $(LFLAGS) $(INCLUDES) $(LIBS)
	@$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	@$(info CREATED $@)

$(RULE_WRAP):
	@$(MAKE) -C $(WRAP)

$(RULE_DLIST):
	@$(MAKE) -C $(DLIST)

$(RULE_FT):
	@$(MAKE) -C $(FT)

#$(RULE_DBG):
#	@$(MAKE) -C $(DBG)

run: test
	./test

mem_test: test
	valgrind valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

clean:
	@$(MAKE) -C $(FT) clean
	@$(MAKE) -C $(DLIST) clean
	@$(MAKE) -C $(WRAP) clean
	#@$(MAKE) -C $(DBG) clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(FT) fclean
	@$(MAKE) -C $(DLIST) fclean
	@$(MAKE) -C $(WRAP) fclean
	#@$(MAKE) -C $(DBG) fclean
	@$(RM) test
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re mem_test run test debug