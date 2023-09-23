NAME	=	megaphone

SRC	=	megaphone.cpp
OBJ	=	$(SRC:.cpp=.o)

cpp	=	clang++
RM	=	rm -f
CPP_FLAGS	=	-Wall -Wextra -Werror -I.

all	: $(NAME)

$(NAME)	: $(OBJ)
			$(CPP) $(CPP_FLAGS) -o $(NAME) $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re 		:	fclean $(NAME)

test:	$(NAME)
			./megaphone "shhhhh... I think the students are asleep..."
			./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
			./megaphone

.PHONY	:	all clean fclean re test	