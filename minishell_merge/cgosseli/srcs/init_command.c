/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:26:40 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/19 15:41:26 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_word(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
	{
		i++;
		j++;
	}
	while (s[j] && !((s[j] >= 9 && s[j] <= 13) || (s[j] && s[j] == 32)))
	{
		if (s[j] == '"')
			j = next_double_quote(s, j);
		if (s[j] && s[j] == 39)
			j = next_simple_quote(s, j);
		j++;
	}
	return (j - i);
}

static char *get_command(char *s)
{
	int	i;
	int	j;
	char *command;

	command = malloc(sizeof(char) * (len_word(s) + 1));
	if (!command)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
	{
		command[j] = s[i];
		if (s[i] == '"')
		{
			i++;
			j++;
			while (s[i] && s[i] != '"')
			{
				command[j] = s[i];
				i++;
				j++;
			}
			command[j] = s[i];
		}
		if (s[i] && s[i] == 39)
		{
			i++;
			while (s[i] && s[i] != 39)
			{
				command[j] = s[i];
				i++;
				j++;
			}
			command[j] = s[i];
		}
		i++;
		j++;
	}
	command[j] = 0;
	return (command);
}

t_proc	*init_command(char *s, int i, int forks)
{
	t_proc *proc;

	proc = malloc(sizeof(t_proc));
	if (!proc)
		return (NULL);
	proc->nb_forks = forks;
	proc->idx = i;
	proc->command = NULL;
	proc->attributes = malloc(sizeof(t_attr));
	if(!get_tokens(s, proc->attributes))
		return (NULL);
	proc->command = get_command(s);
	if (!proc->command)
	{
		free(proc->command);
		free_attr(proc->attributes);
		return (NULL);
	}
	return (proc);
}