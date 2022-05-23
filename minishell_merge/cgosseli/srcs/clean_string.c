/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:29:57 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/10 15:59:56 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *clean_string(char *s)
{
    int i;
    char *new_s;

    i = 0;
    while ((s[i] && s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32))
        i++;
    if (i) 
    {
        new_s = ft_substr(s, i, ft_strlen(s) - i);
        free(s);
        return (new_s);
    }
    return (s);
}