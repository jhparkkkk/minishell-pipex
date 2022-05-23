/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:41:01 by jeepark           #+#    #+#             */
/*   Updated: 2022/05/19 15:43:50 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
int **destroy_pipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
	return (NULL);
}