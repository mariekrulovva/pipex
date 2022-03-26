NAME	=	pipex

SRCS	=	basic/pipex.c basic/utils.c

HEADER	=	includes/pipex.h

OBJS	= $(SRCS:%.c=%.o)

CC		=	gcc

LIBFT	=	-L lib -lft

INC		=	-I includes -I lib

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

GREEN = \033[0;32m
RESET = \033[0m

all		: 	$(NAME)

$(NAME)	: 	$(OBJS) $(HEADER)
				@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(OBJS) -o $(NAME)
				@echo "\n$(NAME): $(GREEN)Successful success!\n$(RESET)"
				@echo "───────────⣾⣿⣿⣦⡀─────────"
				@echo "─────────⣠⣼⣿⣿⣿⣿⣿⣆────────"
				@echo "─────────⢰⣿⣿⣿⣿⣿⣿⣿⣿⣦──────"
				@echo "──────────⠻⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀────"
				@echo "─────────⣀⣀⡈⠛⢿⣿⣿⣿⣿⣿⣿⣧────"
				@echo "───⢀⣤⣶⣛⣩⣭⣥⣍⡓⠦⣿⣿⣿⣿⣿⣿⣿⣇────"
				@echo "──⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣮⣽⣿⣿⣿⣿⣿⣿⡆──"
				@echo "─⢀⣸⣿⣿⣿⣿⠿⠛⠛⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀─" 
				@echo "─⢰⣿⣿⣿⣿⡉      ⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇"
				@echo "⠸⣿⣿⣿⣿⣷        ⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇"
				@echo "─⢻⣿⣿⣿⣿⣷⣤⣀⣀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿──"
				@echo "─⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇──"
				@echo "──⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟───"
				@echo "────⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟────"
				@echo "──────⠈⠙⠻⠿⣿⣿⣿⣿⣿⣿⠿⠟⠋──────\n"

%.o : %.c 	$(HEADER)
				@$(CC) $(CFLAGS) -c $< -o $@

clean 	:
				@rm -f $(OBJS) $(OBJS_B)

fclean	: 	clean
				@rm -f $(NAME)

re		: 	fclean all
			@rm -f $(OBJS) $(OBJS_B)

.PHONY	:	all clean fclean re bonus