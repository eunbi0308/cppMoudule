NAME		=	btc
CC			=	c++

ifdef DEBUG
CPPFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g -std=c++20
else ifdef STRUCTOR
CPPFLAGS	=	-Wall -Wextra -Werror -g -D STRUCTOR -std=c++20
else
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++20
endif

SRC_FILE	=	main.cpp BitcoinExchange.cpp

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.cpp=.o))

HEADERS		=	BitcoinExchange.hpp

CYAN_B		=	\033[1;96m
CYAN		=	\033[0;96m
GREEN_B		=	\033[1;32m
DEFAULT		=	\033[0m

all				:	$(NAME)

$(NAME)			: $(OBJ) $(OBJF)
					@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
					@echo	"$(CYAN_B) - btc is compiled - $(DEFAULT)"

$(OBJ_DIR)%.o	: %.cpp $(HEADERS) | $(OBJF)
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