NAME := liblist.a

DLST = dlst
DLST_DIR = ./dlst
DLST_RULE = $(DLST_DIR)/lib$(DLST).a
LIB_DLST = $(DLST_DIR)/lib$(DLST).a

WRAP = wrappers
WRAP_DIR = ./wrappers
WRAP_RULE = $(WRAP_DIR)/lib$(WRAP).a
LIB_WRAP = $(WRAP_DIR)/lib$(WRAP).a

LIBS = $(LIB_DLST) $(LIB_WRAP) 

AR := ar
ARFLAGS  := -r -c -T

RM := rm -f

all: $(NAME)

$(NAME): $(LST_RULE) $(DLST_RULE) $(WRAP_RULE) 
	$(AR) $(ARFLAGS) $(NAME) $(LIBS)
	$(info CREATED $(NAME))

$(DLST_RULE):
	echo make $(DLST_RULE)
	@$(MAKE) -C $(DLST_DIR)
	$(info CREATED $@)

$(WRAP_RULE):
	echo make $(WRAP_RULE)
	@$(MAKE) -C $(WRAP_DIR)
	$(info CREATED $@)

	

clean:
	@$(MAKE) -C $(DLST_DIR) clean
	@$(MAKE) -C $(WRAP_DIR) clean

fclean:
	@$(MAKE) -C $(DLST_DIR) fclean
	@$(MAKE) -C $(WRAP_DIR) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

