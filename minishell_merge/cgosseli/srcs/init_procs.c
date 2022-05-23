/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_procs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:19:53 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/19 15:31:26 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/* inits the commands tab in which each element is separated by pipes. Each */
/* elements has a char * for its main command and a t_attr * for its attributes.*/
/* The t_attr struct has a string tab with all the options + an int with the nb */
/* of options */

t_proc	**init_procs(char *s, int forks)
{
	t_proc 	**commands_tab;
	char 	**splitted_line;
	int		i;

	i = 0;
	commands_tab = malloc(sizeof(t_proc *) * forks);
	if (!commands_tab)
	{
		printf("Error at malloc\n");
		return (NULL);
	}
	splitted_line = split_w_quote(s, '|');
	while (forks > i)
	{
		commands_tab[i] = init_command(splitted_line[i], i, forks);
		if (!commands_tab[i])
		{
			free_t_proc_tab(commands_tab);
			free_splitted_line(splitted_line, forks);
			return (NULL);
		}
		i++;
	}
	free_splitted_line(splitted_line, forks);
	return (commands_tab);
}