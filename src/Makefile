NAME        := minishell
NAME_DBG    := minishell_dbg

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
RULE_WRAP_DBG := $(WRAP)/libwrappers_dbg.a
I_WRAP := -I$(WRAP)
L_WRAP := -L$(WRAP)

INCLUDES    := -I../include $(I_DLIST) $(I_WRAP) $(I_FT)

LFLAGS    := $(L_DLIST) $(L_WRAP) $(L_FT)

LIBS := $(EXTERN_LIB) $(LIB_DLIST) $(LIB_FT)

all: LIBS+=-lwrappers
all: $(RULE_WRAP) $(RULE_DLIST) $(RULE_FT) $(OBJS) $(OBJS_MAIN)
all: OBJS+=$(OBJS_MAIN)
all: $(NAME)

test: fclean
test: $(RULE_WRAP) $(RULE_DLIST) $(RULE_FT) $(OBJS) $(OBJS_TEST)
test: OBJS+=$(OBJS_TEST)
test: $(NAME)

debug: CFLAGS+=-DDEBUG
debug: LIBS+=-lwrappers_dbg
debug: $(RULE_WRAP_DBG) $(RULE_DLIST) $(RULE_FT) $(OBJS) $(OBJS_MAIN)
debug: OBJS+=$(OBJS_MAIN)
debug: $(NAME_DBG)

$(NAME):
	@$(CC) $(OBJS) -o $(NAME) $(LFLAGS) $(INCLUDES) $(LIBS)
	@$(info CREATED $(NAME))

$(NAME_DBG):
	@$(CC)  $(OBJS) -o $(NAME_DBG) $(LFLAGS) $(INCLUDES) $(LIBS)
	@$(info CREATED $(NAME_DBG))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	@$(info CREATED $@)

$(RULE_WRAP): 
	@$(MAKE) -C $(WRAP)

$(RULE_WRAP_DBG): 
	$(MAKE) -C $(WRAP) debug

$(RULE_DLIST):
	@$(MAKE) -C $(DLIST)

$(RULE_FT):
	@$(MAKE) -C $(FT)

run: test
	./test

mem_test: test
	valgrind valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

clean:
	@$(MAKE) -C $(FT) clean
	@$(MAKE) -C $(DLIST) clean
	@$(MAKE) -C $(WRAP) clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(FT) fclean
	@$(MAKE) -C $(DLIST) fclean
	@$(MAKE) -C $(WRAP) fclean
	@$(RM) test
	@$(RM) $(NAME_DBG)
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re mem_test run test debug