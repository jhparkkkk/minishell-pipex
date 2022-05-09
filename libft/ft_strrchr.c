/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:12:25 by jeepark           #+#    #+#             */
/*   Updated: 2021/11/27 22:41:56 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = (int)ft_strlen(str) + 1;
	while (i--)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
	}
	return (NULL);
}
