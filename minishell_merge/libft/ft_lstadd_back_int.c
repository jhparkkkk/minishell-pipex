/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:09:24 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/09 20:56:09 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_int(t_list_int **alst, t_list_int *new)
{
	t_list_int	*tempo;

	if (!new || !alst)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tempo = ft_lstlast_int(*alst);
	tempo->next = new;
}
