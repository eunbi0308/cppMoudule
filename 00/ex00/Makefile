NAME		=	megaphone
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_FILE	=	megaphone.cpp

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.cpp=.o))
OBJF		=	.cache_exists

CYAN_B		=	\033[1;96m
CYAN		=	\033[0;96m
GREEN_B		=	\033[1;32m
DEFAULT		=	\033[0m

all				:	$(NAME)

$(NAME)			: $(OBJ) $(OBJF)
					@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
					@echo	"$(CYAN_B) - ex00 is compiled - $(DEFAULT)"

$(OBJ_DIR)%.o	: %.cpp | $(OBJF)
					@mkdir -p $(@D)
					@$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJF)			:
					@mkdir -p $(OBJ_DIR)
					@touch $(OBJF)

clean			:
					@rm -rf $(OBJ_DIR)
					@rm	-rf	$(OBJF)
					@echo "$(CYAN)- Object files are cleaned - $(DEFAULT)"

fclean			: clean
					@rm -f $(NAME)
					@echo "$(CYAN)- Executable files are cleaned - $(DEFAULT)"

re				:	fclean all

test			: $(NAME)
					./megaphone "shhhhh... I think the students are asleep..."
					./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
					./megaphone

.PHONY: all clean fclean re