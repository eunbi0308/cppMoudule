NAME		=	Intern
CC			=	c++

ifdef DEBUG
CPPFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g
else
CPPFLAGS	=	-Wall -Wextra -Werror
endif

SRC_FILE	=	main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.cpp=.o))

HEADERS		=	Bureaucrat.hpp \
				AForm.hpp \
				ShrubberyCreationForm.hpp \
				RobotomyRequestForm.hpp \
				PresidentialPardonForm.hpp \
				Intern.hpp

CYAN_B		=	\033[1;96m
CYAN		=	\033[0;96m
GREEN_B		=	\033[1;32m
DEFAULT		=	\033[0m

all				:	$(NAME)

$(NAME)			: $(OBJ) $(OBJF)
					@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
					@echo	"$(CYAN_B) - Intern is compiled - $(DEFAULT)"

$(OBJ_DIR)%.o	: %.cpp $(HEADERS) | $(OBJF)
					@mkdir -p $(@D)
					@$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJF)			:
					@mkdir -p $(OBJ_DIR)

clean			:
					@rm -rf $(OBJ_DIR)
					@rm *_shrubbery
					@echo "$(CYAN)- Object files are cleaned - $(DEFAULT)"

fclean			: clean
					@rm -f $(NAME)
					@echo "$(CYAN)- Executable files are cleaned - $(DEFAULT)"
					@rm -f *_shrubbery

re				:	fclean all

.PHONY: all clean fclean re