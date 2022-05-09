/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:09:03 by jeepark           #+#    #+#             */
/*   Updated: 2021/12/07 19:19:29 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_b;
	size_t			i;

	new_b = (unsigned char *)b;
	i = 0;
	if (!new_b)
		new_b[len] = '\0';
	while (i < len)
	{
		new_b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
