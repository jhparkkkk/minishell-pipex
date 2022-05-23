/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:03:11 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/18 13:37:03 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_forks(t_proc proc)
{
	int	i;

	i = 0;
	printf("command %d : %s\n", proc.idx, proc.command);
	while (proc.attributes->nb_elem > i)
	{
    	printf("attribute %d : %s\n", i, proc.attributes->list[i]);
		i++;
	}
	printf("\n");
}

