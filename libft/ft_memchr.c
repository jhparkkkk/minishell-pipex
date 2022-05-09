/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:45:12 by jeepark           #+#    #+#             */
/*   Updated: 2021/12/07 17:38:14 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	size_t			i;

	new_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == (unsigned char)c)
			return ((void *)new_s + i);
		i++;
	}
	return (NULL);
}
