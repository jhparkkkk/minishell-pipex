/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:02:21 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/16 16:53:38 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned long	row_count(char const *s, char c)
{
	int				i;
	unsigned long	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (word);
}

static size_t	col_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_split(char **s_tab)
{
	int	i;

	i = 0;
	while (s_tab[i])
	{
		free(s_tab[i]);
		i++;
	}
	free(s_tab);
	return (NULL);
}

static char	**tab_init(char const *s, char c)
{
	char	**s_tab;

	if (!s)
		return (NULL);
	s_tab = malloc(sizeof(char *) * (row_count(s, c) + 1));
	if (!s_tab)
	{
		free(s_tab);
		return (NULL);
	}
	return (s_tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	k;
	char	**s_tab;

	j = 0;
	s_tab = tab_init(s, c);
	if (!s_tab || !s)
		return (NULL);
	while (*s)
	{
		k = 0;
		if (*s == c)
			s++;
		else
		{
			s_tab[j] = malloc(sizeof(char) * (col_count(s, c) + 1));
			if (!s_tab[j])
				return (free_split(s_tab), NULL);
			while (*s != c && *s)
				s_tab[j][k++] = *s++;
			s_tab[j][k] = 0;
			j++;
		}
	}
	return (s_tab[j] = 0, s_tab);
}
