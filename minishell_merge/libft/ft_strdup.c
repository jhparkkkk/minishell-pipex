/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:42:23 by jeepark           #+#    #+#             */
/*   Updated: 2021/12/07 17:40:10 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;

	s_copy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s_copy)
		return (NULL);
	ft_strlcpy(s_copy, s, (ft_strlen(s) + 1));
	return (s_copy);
}
