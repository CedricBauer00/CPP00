NAME = phonebook
SRC = Phonebook.cpp \
		main.cpp \
		Contact.cpp
CXX = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re