
NAME := libwrappers.a
NAME_DBG := libwrappers_dbg.a
SRC_DIR := .

SRCS = \
	ft_close.c\
	ft_dup2.c\
	ft_error.c\
	ft_fstat.c\
	ft_kill.c\
	ft_malloc.c\
	ft_open.c\
	ft_read.c\
	ft_sigaddset.c\
	ft_sigemptyset.c\
	ft_signal.c\
	ft_stat.c\
	ft_stdlib.c\
	ft_unistd.c\
	ft_wait.c\
	ft_waitpid.c\
	ft_write.c\
	ft_execve.c\
	tf_fork.c\
	ft_lstat.c\

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

all: $(NAME)

debug: fclean
debug: NAME = $(NAME_DBG)
debug: CCFLAGS += -DDEBUG
debug: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CCFLAGS) -c $< -o $@
	$(info CREATED $@)

clean:
	@$(CLEANER) $(BUILD_DIR)

fclean: clean
	@$(CLEANER) $(NAME_DBG)
	@$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
