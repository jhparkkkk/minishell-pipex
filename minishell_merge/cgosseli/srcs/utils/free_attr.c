/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:02:00 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/18 13:43:01 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_attr(t_attr *tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens->nb_elem > i)
	{
		free(tokens->list[i]);
		i++;
	}
	free(tokens->list);
	free(tokens);
}