/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:58:14 by jeepark           #+#    #+#             */
/*   Updated: 2021/12/04 15:51:36 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char	const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	if ((!s) || (!f))
		return (NULL);
	i = 0;
	new_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
