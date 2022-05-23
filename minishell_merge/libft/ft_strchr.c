/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:15:35 by jeepark           #+#    #+#             */
/*   Updated: 2021/12/07 17:40:59 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)str + ft_strlen(str));
	if (!(char)c)
		return ((char *)(str));
	while (str[i])
	{
		if ((char)c == str[i])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
