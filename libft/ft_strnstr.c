/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:17:52 by jeepark           #+#    #+#             */
/*   Updated: 2021/11/27 15:17:58 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *key, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*key)
		return ((char *)str);
	while (i < len && str[i])
	{
		j = 0;
		if (str[i] == key[j])
		{
			k = i;
			while (key[j] && str[k] == key[j] && k < len)
			{
				k++;
				j++;
			}
			if (!key[j])
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
