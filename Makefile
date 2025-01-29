NAME = Klass
SRC_FILES = main.cpp
CPPC = c++
STD ?= 
CPPFLAGS = -Wall -Wextra -Werror $(STD)
RM = rm -rf

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): main.cpp
	$(CPPC) $(CPPFLAGS) $(SRC_FILES) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
