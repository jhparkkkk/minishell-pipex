/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:13:53 by jeepark           #+#    #+#             */
/*   Updated: 2021/12/08 15:11:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*new_s_init(char const *s1, char const *s2)
{
	unsigned long	len;
	char			*new_s;

	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	new_s = malloc(sizeof(char) * len);
	if (!new_s)
		return (NULL);
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				j;
	char			*new_s;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	new_s = new_s_init(s1, s2);
	if (!new_s)
		return (NULL);
	while (s1[j])
	{
		new_s[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		new_s[i++] = s2[j++];
	}
	new_s[i] = '\0';
	return (new_s);
}
