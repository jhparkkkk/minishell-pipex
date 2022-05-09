NAME 		= 	pipex

CC			= 	cc

RM 			= 	rm -f

INC			=	-I includes -I libft

CFLAGS		=	-Wall -Wextra -Werror 

LFLAGS		=	-I./libft -lft -L./libft -I./pipex -L./pipex

LIBFT		=	./libft/libft.a

SRCS		=	test.c \

OBJS		= 	$(SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION) $(INC)

$(LIBFT):
			$(MAKE) -C $(@D) $(@F)

$(NAME):	$(LIBFT) $(OBJS) 
			$(CC) $(OBJS) $(LFLAGS) $(OUTPUT_OPTION) 

clean:
			$(RM) $(OBJS)
			$(RM) ./libft/*.o 
		
fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re 