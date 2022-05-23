/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:06:25 by cgosseli          #+#    #+#             */
/*   Updated: 2022/05/19 15:32:07 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  starts_with_pipe(char *s)
{
    int i;

    i = 0;
    if (!s || s[0] == '\0')
        return (0);
    while ((s[i] && s[i] >= 9 && s[i] <= 13) || (s[i] && s[i] == 32))
        i++;
    if (s[i] == '|')
        return (1);
    return (0);
}

static int  ends_with_pipe(char *s)
{
    int len;

    if (!s || s[0] == '\0')
        return (0);
    len = ft_strlen(s) - 1;
    while ((s[len] && s[len] >= 9 && s[len] <= 13) || (s[len] && s[len] == 32))
    {
        len--;
        if (len < 0)
            break ;
    }
    if (len > 0 && s[len] == '|')
        return (1);
    return (0);
}

int main()
{
    char    *line;
    t_proc **commands_tab;
    int forks;
    int     i;

    line = NULL;
    commands_tab = NULL;
    while (1)
    {
        i = 0;
        line = readline("> ");
        if (starts_with_pipe(line))
            printf("bash: syntax error near unexpected token `|'\n");
        else
        {
            while (ends_with_pipe(line))
                line = ft_strjoin(line, readline("> "));
            forks = count_forks(line);
            if (forks)
            {
                commands_tab = init_procs(line, forks);
                if (!commands_tab)
                {
                    free(line);
                    return (0);
                }
            }
            while (forks-- > 0)
            {
                print_forks(*commands_tab[i]);
                i++;
            }
            free_t_proc_tab(commands_tab);
        }
    }
    free(line);
}

/* LEAKS ===> readline fct (osef) */

/* TRUCS CHIANTS ===> tab fait un ls */

/* cat > file ===> écrit dans le file */
/* cat <<FIN file ===> écrit dans le file, arrête d'écrire quand on écrit FIN */
/* cat >> file ===> comme cat > file mais en append */
/* cat file1 >> file2 ===> append file1 to file2 */