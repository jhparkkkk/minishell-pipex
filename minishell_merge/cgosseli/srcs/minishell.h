/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:12:15 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/19 15:32:07 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../libft/libft.h"


typedef struct s_attr {
	char 	**list;
	int		nb_elem;
}	t_attr;

typedef struct s_proc {
	char 	*command;
	t_attr 	*attributes;
	int		idx;
	int		nb_forks;
}	t_proc;

int 	count_forks(char *s);
t_proc	**init_procs(char *s, int forks);
t_proc	*init_command(char *s, int i, int forks);
void	*get_tokens(char *s, t_attr *tokens);
void 	free_t_proc_tab(t_proc **splitted);
void	free_attr(t_attr *tokens);
void	free_splitted_line(char **splitted_line, int count);

int 	next_simple_quote(char *s, int i);
int 	next_double_quote(char *s, int i);
char	**split_w_quote(char *s, char c);

/***** DEBUGGING *****/
void	print_forks(t_proc proc);

#endif
