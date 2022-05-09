/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:25:24 by jeepark           #+#    #+#             */
/*   Updated: 2021/12/04 19:50:39 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	find_len(long new_nb)
{
	unsigned long	len;

	len = 1;
	if (new_nb < 0)
	{
		new_nb *= -1;
		len += 1;
	}
	while (new_nb >= 10)
	{
		new_nb = new_nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	unsigned long	len;
	long			new_nb;
	char			*s_nb;

	new_nb = (long)nb;
	len = find_len(new_nb);
	s_nb = malloc(sizeof(char) * (len + 1));
	if (!s_nb)
		return (NULL);
	s_nb[len] = 0;
	if (new_nb < 0)
	{
		new_nb *= -1;
		s_nb[0] = '-';
	}
	if (new_nb == 0)
		return (s_nb[0] = '0', s_nb);
	len--;
	while (new_nb >= 10)
	{
		s_nb[len] = (new_nb % 10) + 48;
		new_nb = new_nb / 10;
		len--;
	}
	return (s_nb[len] = (new_nb % 10) + 48, s_nb);
}
