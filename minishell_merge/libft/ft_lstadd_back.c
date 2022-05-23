/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:09:24 by jeepark           #+#    #+#             */
/*   Updated: 2021/12/10 18:07:50 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tempo;

	if (!new || !alst)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tempo = ft_lstlast(*alst);
	tempo->next = new;
}
