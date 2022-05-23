/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:55:53 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/19 15:32:07 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_word_count(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ((s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32)))
			i++;
		while (s[i] && !((s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32)))
		{
			count++;
			while (s[i] && !((s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32)))
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

static int	len_word(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !((s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32)))
	{
		if (s[i] == '"')
			i = next_double_quote(s, i);
		if (s[i] && s[i] == 39)
			i = next_simple_quote(s, i);
		i++;
	}
	return (i);
}

static char	*ft_sdupword(char *s)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (len_word(s) + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !((s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32)))
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

void	*get_tokens(char *s, t_attr *tokens)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	while (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	tokens->nb_elem = ft_word_count(s + i);
	tokens->list = malloc(sizeof(char *) * (tokens->nb_elem + 1));
	if (!tokens->list)
		return (NULL);
	while (s[i])
	{
		while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			i++;
		if (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		{
			tokens->list[j++] = ft_sdupword(s + i);
			while (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			{
				if (s[i] == '"')
					i = next_double_quote(s, i);
				if (s[i] && s[i] == 39)
					i = next_simple_quote(s, i);
				i++;
			}
		}
	}
	tokens->list[j] = 0;
	return (tokens);
}
