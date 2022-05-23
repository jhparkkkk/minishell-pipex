/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_proc_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:37:18 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/18 13:42:26 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void free_t_proc_tab(t_proc **proc_tab)
{
	int	i;
	int	forks;

	if (!proc_tab)
		return ;
	i = 0;
	forks = proc_tab[i]->nb_forks;
	while (i < forks)
	{
		free(proc_tab[i]->command);
		if (proc_tab[i]->attributes)
			free_attr(proc_tab[i]->attributes);
		free(proc_tab[i]);
		i++;
	}
	free(proc_tab);
}