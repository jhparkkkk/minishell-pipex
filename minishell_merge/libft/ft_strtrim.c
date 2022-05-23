/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:05:37 by jeepark           #+#    #+#             */
/*   Updated: 2022/01/27 17:16:14 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned long	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (i < j && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	if ((int)j - (int)i < 0)
		return (ft_substr("", 0, 1));
	return (ft_substr(s1, i, j - i));
}
