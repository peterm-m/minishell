
NAME_CD = cd
NAME_ECHO = echo
NAME_ENV = env
NAME_EXIT = exit
NAME_EXPORT = export
NAME_PWD = pwd
NAME_UNSET = unset

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBDIR := ../lib

INCLUDES := -I$(LIBDIR)/libft -I$(LIBDIR)/wrappers
LIBS := $(INCLUDES) \
	-lft       -L$(LIBDIR)/libft    \

all: $(NAME_CD) $(NAME_ECHO) $(NAME_ENV) $(NAME_EXIT) $(NAME_EXPORT) $(NAME_PWD) $(NAME_UNSET)

$(NAME_CD): $(NAME_CD).o
	$(CC) -o $(NAME_CD) $+ $(DEBUG) $(CFLAGS) $(LIBS)

$(NAME_ECHO): $(NAME_ECHO).o
	$(CC) -o $(NAME_ECHO) $+ $(DEBUG) $(CFLAGS) $(LIBS)

$(NAME_ENV): $(NAME_ENV).o
	$(CC) -o $(NAME_ENV) $+ $(DEBUG) $(CFLAGS) $(LIBS)

$(NAME_EXIT): $(NAME_EXIT).o
	$(CC) -o $(NAME_EXIT) $+ $(DEBUG) $(CFLAGS) $(LIBS)

$(NAME_EXPORT): $(NAME_EXPORT).o
	$(CC) -o $(NAME_EXPORT) $+ $(DEBUG) $(CFLAGS) $(LIBS)

$(NAME_PWD): $(NAME_PWD).o
	$(CC) -o $(NAME_PWD) $+ $(DEBUG) $(CFLAGS) $(LIBS)

$(NAME_UNSET): $(NAME_UNSET).o
	$(CC) -o $(NAME_UNSET) $+ $(DEBUG) $(CFLAGS) $(LIBS)

$(NAME_CD).o: $(NAME_CD).c
	$(CC) -c $^ -o $@ $(LIBS) $(CFLAGS)

$(NAME_ECHO).o: $(NAME_ECHO).c
	$(CC) -c $^ -o $@ $(LIBS) $(CFLAGS)

$(NAME_ENV).o: $(NAME_ENV).c
	$(CC) -c $^ -o $@ $(LIBS) $(CFLAGS)

$(NAME_EXIT).o: $(NAME_EXIT).c
	$(CC) -c $^ -o $@ $(LIBS) $(CFLAGS)

$(NAME_EXPORT).o: $(NAME_EXPORT).c
	$(CC) -c $^ -o $@ $(LIBS) $(CFLAGS)

$(NAME_PWD).o: $(NAME_PWD).c
	$(CC) -c $^ -o $@ $(LIBS) $(CFLAGS)

$(NAME_UNSET).o: $(NAME_UNSET).c
	$(CC) -c $^ -o $@ $(LIBS) $(CFLAGS)


clean:
	$(RM) $(NAME_CD).o $(NAME_ECHO).o $(NAME_ENV).o $(NAME_EXIT).o $(NAME_EXPORT).o $(NAME_PWD).o $(NAME_UNSET).o

fclean: clean
	$(RM)  $(NAME_CD) $(NAME_ECHO) $(NAME_ENV) $(NAME_EXIT) $(NAME_EXPORT) $(NAME_PWD) $(NAME_UNSET)

re: fclean all

.PHONY: all fclean re bonus
