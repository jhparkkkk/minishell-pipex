/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:25:07 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/02 11:55:47 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*box;

	if (!lst)
		return ;
	while (*lst)
	{
		box = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = box;
	}
	*lst = NULL;
}

void	ft_lstclear_int(t_list_int **lst)
{
	t_list_int	*box;

	if (!lst)
		return ;
	while (*lst)
	{
		box = (*lst)->next;
		if (box)
			free(box);
		*lst = box;
	}
	*lst = NULL;
}
