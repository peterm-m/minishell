
NAME = libdlst.a

SRC_DIR := .

SRCS = \
	ft_dlstclear.c\
	ft_dlstnew.c \
	ft_dlstadd.c \
	ft_dlstlast.c \
	ft_dlstiter.c\
	ft_dlstdelone.c \
	ft_dlstsize.c

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
	@$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
