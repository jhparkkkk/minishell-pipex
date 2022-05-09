CC		= 	gcc

RM 		= 	rm -f

CFLAGS	=	-Wall -Wextra -Werror

SRC 	=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_atol.c \
			ft_strcmp.c \
			get_next_line.c \

SRC_B	= 	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstnew_int.c \
			ft_lstadd_back_int.c \
			ft_lstlast_int.c \
			ft_lstadd_front_int.c \

LIB		= 	ar rc

NAME 	= 	libft.a

HEADER  = 	libft.h get_next_line.h

OBJ 	= 	$(SRC:.c=.o)

OBJ_B = 	$(SRC_B:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_B)
			$(LIB) $(NAME) $(OBJ) $(OBJ_B)
		
bonus:		$(OBJ) $(OBJ_B)
			$(LIB) $(NAME) $(OBJ) $(OBJ_B)

clean:
			$(RM) $(OBJ) $(OBJ_B)  

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
