#include "pipex.h"


/* Je liste tous les chemins possibles avec split en ajoutant
"/" a la fin de chaque chemin. */

void get_path(t_cmd *cmd, char *envp)
{
     int i = 0;
    (void)cmd;
    
    cmd->path = ft_split(envp,':');
    while(cmd->path[i])
    {
        // printf("%s\n", cmd->path[i]);
        cmd->path[i] = ft_strjoin(cmd->path[i], "/");
        // printf("%s\n", cmd->path[i]);

        i++;
    }

}

/* la variable PATH montre tous les chemins possibles vers les *.o
des programmes dont les commandes shell. Ici, je cherche la ligne
commencant par "PATH=" */

void	locate_path(t_cmd *cmd, char **envp)
{
	int i = 0;
	int j= 0;

	 while(envp[i++])
    {
        if (envp[i][0] == 'P' && ft_strncmp(&envp[i][j], "PATH=", 5) == 0)
        {
			get_path(cmd, &envp[i][j + 5]);
            break ;
        }
    }
}

/* Je parcours la liste des chemins pour trouver celui qui correspond a
ma commande. */
char	*get_cmd_path(t_cmd *cmd, char *cmd_path)
{
	int i;

	i = 0;

	while (cmd->path[i])
	{
		cmd_path = ft_strjoin(cmd->path[i], cmd->commande);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return(cmd_path);
		i++;
	}
	return (NULL);

}

int main(int ac, char **av, char **envp)
{
	char *options[3] = {"ls", "-la", NULL};
    t_cmd cmd;
    pid_t pid;
	char *cmd_path;

	if (ac > 1)
	{
		cmd.commande = av[1];
		printf("%s\n", cmd.commande);
	}
	cmd_path = NULL;
    pid = fork();
    if (pid == -1)
		return (1);
	locate_path(&cmd, envp);
	cmd_path = get_cmd_path(&cmd, cmd_path);
	printf("PATH FOR LS IS : %s\n", cmd_path);
    if (execve(cmd_path, &options[0], envp) == 0)
		printf("EXECVE SUCCES !\n");
    return (0);
}