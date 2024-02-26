NAME		=	Brain
CC			=	c++

ifdef DEBUG
CPPFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g
else
CPPFLAGS	=	-Wall -Wextra -Werror
endif

SRC_FILE	=	main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.cpp=.o))

HEADERS		=	Animal.hpp Cat.hpp Dog.hpp Brain.hpp

CYAN_B		=	\033[1;96m
CYAN		=	\033[0;96m
GREEN_B		=	\033[1;32m
DEFAULT		=	\033[0m

all				:	$(NAME)

$(NAME)			: $(OBJ)
					@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
					@echo	"$(CYAN_B) - Brain is compiled - $(DEFAULT)"

$(OBJ_DIR)%.o	: %.cpp $(HEADERS)
					@mkdir -p $(@D)
					@$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJF)			:
					@mkdir -p $(OBJ_DIR)

clean			:
					@rm -rf $(OBJ_DIR)
					@echo "$(CYAN)- Object files are cleaned - $(DEFAULT)"

fclean			: clean
					@rm -f $(NAME)
					@echo "$(CYAN)- Executable files are cleaned - $(DEFAULT)"

re				:	fclean all

.PHONY: all clean fclean re