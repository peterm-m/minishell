NAME = cdprogram
CC = gcc

CFLAGS = -Wall -Wextra -Werror 

LIBDIR := ../../lib
#CD = cd.c \
ECHO =echo.c \
ENV = env.c \
EXIT = exit.c \
EXPORT = export.c \
PWD = pwd.c \
UNSET =	unset .c \
\#
INCLUDE := -I$(LIBDIR)/libft -I$(LIBDIR)/wrappers

LIBS := \
	-lft       -L$(LIBDIR)/libft    \
	-lwrappers -L$(LIBDIR)/wrappers \
	\

SRC = cd.c echo.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
