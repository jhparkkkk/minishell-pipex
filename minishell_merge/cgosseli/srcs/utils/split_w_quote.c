/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_w_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:19:09 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/17 16:56:12 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_word_count(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		while (s[i] && !(s[i] == c))
		{
			count++;
			while (s[i] && !(s[i] == c))
			{
				if (s[i] == '"')
					i = next_double_quote(s, i);
				if (s[i] && s[i] == 39)
            		i = next_simple_quote(s, i);
				i++;
			}
		}
	}
	return (count);
}

static int	len_word(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == c))
	{
		if (s[i] == '"')
			i = next_double_quote(s, i);
		if (s[i] && s[i] == 39)
			i = next_simple_quote(s, i);
		i++;
	}
	return (i);
}

static char	*ft_sdupword(char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (len_word(s, c) + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !(s[i] == c))
	{
		word[i] = s[i];
		if (s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
			{
				word[i] = s[i];
				i++;
			}
			word[i] = s[i];
		}
		if (s[i] && s[i] == 39)
		{
			i++;
			while (s[i] && s[i] != 39)
			{
				word[i] = s[i];
				i++;
			}
			word[i] = s[i];
		}
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**split_w_quote(char *s, char c)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!dest)
		return (NULL);
	while (s[j])
	{
		while (s[j] && (s[j] == c))
			j++;
		if (s[j] && !(s[j] == c))
		{
			dest[i++] = ft_sdupword(s + j, c);
			while (s[j] && !(s[j] == c))
			{
				if (s[j] == '"')
					j = next_double_quote(s, j);
				if (s[j] && s[j] == 39)
					j = next_simple_quote(s, j);
				j++;
			}
		}
	}
	dest[i] = 0;
	return (dest);
}
