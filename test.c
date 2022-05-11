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
        cmd->path[i] = ft_strjoin(cmd->path[i], "/");
        i++;
    }

}

/* la variable PATH montre tous les chemins possibles vers les *.o
des programmes dont les commandes shell. Ici, je cherche la ligne
commencant par "PATH=" */

void	locate_path(t_cmd *cmd, char **envp)
{
	int i;
	int j;

	i = 0;
	j = 0;

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

void	execute_builtin(char *cmd_path, char **envp)
{
	char	*options[3] = {"ls", "-la", NULL};

	if (execve(cmd_path, options, envp) == 0)
	 	printf("EXECVE SUCCES !\n");
}

int	create_pipes(t_cmd *cmd, char *cmd_path, char **envp)
{
	(void)cmd;
	(void)cmd_path;
	(void)envp;

	int end[2];
	pid_t pid;
	int reader;
	char buf[10];


	if (pipe(end) < 0)
		return (1);
	//je cree processus fils
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		// je suis dans le processus fils
		close(end[0]); // l'enfant ne va rien lire alors je ferme le bout lecture
		write(end[1], "coucou\n", 7);
		close(end[1]); // l'enfant a fini d'ecrire alors je ferme le bout ecriture 
		return (0);
	}
	else
	{
		// je suis dans le processus parent
		close(end[1]); // le parent ne va rien ecrire alors je ferme le bout lecture
		waitpid(pid, NULL, 0); // le parent attend son fils
		reader = read(end[0], buf, 10);
		if (reader < 0)
			return (3);
		close(end[0]); // le parent a fini de lire alors je ferme le bout lecture
		buf[reader] = '\0';
		printf("%s\n", buf);
	}
	return (0);
}


int main(int ac, char **av, char **envp)
{
    t_cmd	cmd;
	char	*cmd_path;

	cmd.nb_builtin = 3;
	
	if (ac > 1)
	{
		cmd.commande = av[1];
	}
	cmd_path = NULL;
	locate_path(&cmd, envp);
	cmd_path = get_cmd_path(&cmd, cmd_path);
	printf("PATH FOR LS IS : %s\n", cmd_path);
	printf("%d\n", create_pipes(&cmd, cmd_path, envp));
	// if (cmd.nb_builtin == 1)
	// 	execute_builtin(cmd_path, envp);

    return (0);
}