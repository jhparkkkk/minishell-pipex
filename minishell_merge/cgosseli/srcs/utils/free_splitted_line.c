/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:42:26 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/18 13:42:46 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_splitted_line(char **splitted_line, int count)
{
	int	i;

	if (!splitted_line)
		return ;
	i = 0;
	while (i < count)
	{
		free(splitted_line[i]);
		i++;
	}
	free(splitted_line);
}