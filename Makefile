NAME := minishell

TEST := testing

SOURCE := src

RM          := rm -rf

all: $(NAME)

test: $(TEST)
	@$(MAKE) -C $(SOURCE) test

$(NAME):
	@$(MAKE) -C $(SOURCE)
	ln -s $(SOURCE)/$(NAME) $(NAME)

$(TEST):
	@$(MAKE) -C $(SOURCE) test
	ln -s $(SOURCE)/$(TEST) $(TEST)

clean:
	@$(MAKE) -C $(SOURCE) clean

fclean:
	@$(MAKE) -C $(SOURCE) fclean
	@$(RM) $(NAME)
	@$(RM) $(TEST)

re:
	@$(MAKE) fclean
	@$(MAKE) all

