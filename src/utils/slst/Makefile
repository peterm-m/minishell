
NAME = liblst.a

SRC_DIR := .

SRCS = \
	ft_lstadd.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR   := .build
TEST = .test

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
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CCFLAGS) -c $< -o $@
	$(info CREATED $@)

make_test:
	$(MAKE) -C $(TEST)

test: $(NAME) make_test
	$(MAKE) -C $(TEST) run

clean:
	$(MAKE) -C $(TEST) clean
	$(CLEANER) $(BUILD_DIR)

fclean: clean 
	$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
