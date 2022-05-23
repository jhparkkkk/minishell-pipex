# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 10:55:01 by cgosseli          #+#    #+#              #
#    Updated: 2022/05/19 14:27:19 by cgosseli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
RM = rm -rf
FILES = minishell.c\
		count_forks.c\
		init_procs.c\
		init_command.c\
		get_tokens.c\
		utils/free_attr.c\
		utils/free_splitted_line.c\
		utils/free_t_proc_tab.c\
		utils/next_simple_quote.c\
		utils/next_double_quote.c\
		utils/split_w_quote.c\
		print_forks.c
LIBFT = ./libft/libft.a
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
OBJS = $(addprefix $(OBJS_PATH), $(FILES:.c=.o))
LFLAGS = -lft -L ./libft/ -lreadline -g

all : $(NAME)

$(OBJS_PATH)%.o : 	$(SRCS_PATH)%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION)		

$(NAME) : $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LFLAGS) $(OUTPUT_OPTION)

$(LIBFT) : 
		$(MAKE) -C $(@D) $(@F)

clean :
		$(RM) $(OBJS_PATH)

fclean : clean
		$(RM) $(NAME)
		$(MAKE) -C $(dir $(LIBFT)) $@

re : fclean all

.PHONY : clean fclean all bonus