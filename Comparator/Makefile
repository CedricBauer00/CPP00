NAME = compare

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17

SRC =	compare.cpp

OBJ_DIR = obj
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

RM = rm -f

vpath %.cpp	src

RED = \033[31m
B_RED = \033[1;31m
GREEN = \033[32m
B_GREEN = \033[1;32m
YELLOW = \033[33m
B_YELLOW = \033[1;33m
BLUE = \033[34m
B_BLUE = \033[1;34m
MAGENTA = \033[35m
B_MAGENTA = \033[1;35m
CYAN = \033[36m
B_CYAN = \033[1;36m
DEFAULT = \033[0m

# all: $(NAME)

SPINNER = '⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏'

all:
	@mkdir -p $(OBJ_DIR); \
	total=$$(echo $(SRC) | wc -w); \
	count=0; \
	i=0; \
	for src in $(SRC); do \
		obj=$(OBJ_DIR)/$${src%.cpp}.o; \
		$(CC) $(CFLAGS) -c $$src -o $$obj; \
		count=$$((count + 1)); \
		spin=$$(echo $(SPINNER) | cut -c $$(( (i % 4) + 1 ))); \
		if [ $$count -lt $$total ]; then \
			printf "\r$(B_YELLOW)Compiling... $(DEFAULT)$$spin ($(B_YELLOW)%d$(DEFAULT)/$(B_GREEN)%d$(DEFAULT))" $$count $$total; \
		else \
			printf "\r$(B_GREEN)Compiling finished$(DEFAULT) ($(B_GREEN)%d$(DEFAULT)/$(B_GREEN)%d$(DEFAULT))\n" $$count $$total; \
		fi; \
		i=$$((i + 1)); \
	done; \
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)Cleaned Objects$(DEFAULT)"

fclean:
	@$(RM) $(OBJ)
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(B_RED)Program cleaned all up$(DEFAULT)"

re: fclean all

.PHONY: all, clean, fclean, re