/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:47:28 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/02 11:55:06 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_int	*ft_lstnew_int(int content)
{
	t_list_int	*house;

	house = (t_list_int *)malloc(sizeof(*house));
	if (!house)
		return (NULL);
	house->content = content;
	house->next = NULL;
	return (house);
}
