/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:23:39 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/18 18:03:09 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int next_double_quote(char *s, int i)
// {
//     i++;
//     while (s[i])
//     {
//         if (s[i] == '"')
//             return (i);
//         i++;
//     }
//     return (i);
// }

// static int next_simple_quote(char *s, int i)
// {
//     i++;
//     while (s[i])
//     {
//         if (s[i] == 39)
//             return (i);
//         i++;
//     }
//     return (i);
// }

static int check_empty_pipe(char *s, int i)
{
    if ((s[i + 1] && s[i + 1] == '|'))
    {
        printf("bash: syntax error near unexpected token `|'\n");
        return (0);
    }
    i++;
    while ((s[i] && s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32))
        i++;
    if (s[i] == '|')
    {
        printf("bash: syntax error near unexpected token `|'\n");
        return (0);
    }
    return (1);
}

int count_forks(char *s)
{
    int i;
    int j;

    i = 0;
    j = 1;
    if (!s || s[0] == '\0' || s[0] == '\n') //////// a check si return 0 quand \n
        return (0);
    while ((s[i] && s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32))
        i++;
    if (s[i] == '|')
    {
        printf("bash: syntax error near unexpected token `|'\n");
        return (0);
    }
    while (s[i])
    {
        if (s[i] == '"')
            i = next_double_quote(s, i);
        if (s[i] && s[i] == 39)
            i = next_simple_quote(s, i);
        if (s[i] && s[i] == '|')
        {
            if (!check_empty_pipe(s, i))
                return (0);
            j++;
        }
        i++;
    }
    return (j);
}