NAME := liblist.a

DLST = dlst
DLST_DIR = ./dlst
DLST_RULE = $(DLST_DIR)/lib$(DLST).a
LIB_DLST = $(DLST_DIR)/lib$(DLST).a

LIBS = $(LIB_DLST)

AR := ar
ARFLAGS  := -r -c -T

RM := rm -f

all: $(NAME)

$(NAME): $(LST_RULE) $(DLST_RULE)
	$(AR) $(ARFLAGS) $(NAME) $(LIBS)
	$(info CREATED $(NAME))

$(DLST_RULE):
	echo make $(DLST_RULE)
	@$(MAKE) -C $(DLST_DIR)
	$(info CREATED $@)
clean:
	@$(MAKE) -C $(DLST_DIR) clean

fclean:
	@$(MAKE) -C $(DLST_DIR) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

