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

/* je verifie le statut de tous mes processus */ 
int	get_processus_status(t_cmd *cmd, pid_t pid[], int *curr_process)
{
	pid_t		res = 0;
	int			status = 0;
	if (*curr_process == cmd->nb_process)
	{
		printf("DONE\n");
	}
	res = waitpid(pid[*curr_process], &status, 0);
	if (WIFEXITED(status))
		printf("MY 1st CHILD ENDED HIS PROCESS CORRECTLY\n");
	else
		printf("MY 1st CHILD GOT INTERRUPTED...\n");
	if (*curr_process < cmd->nb_process)
	{
		*curr_process = *curr_process + 1;
		get_processus_status(cmd, pid, curr_process);
	}
	return (0);
}



/* Je cree mes processus enfant a l'aide de fork() en fonction du nb de
commandes invoquees */

int	create_processus(t_cmd *cmd, int *curr_process)
{
	pid_t		pid[cmd->nb_process];
	int			pipe_fd[2];

	/* je ne sais pas si c'est utile
	if (pid[*curr_process] == 0 && *curr_process == cmd->nb_process)
	{
		*curr_process = 0;
		//get_processus_status(cmd, &pid[cmd->nb_process], curr_process);
	}*/
	// si je me trouve dans le processus child, je peux effectuer mes redirections
	// de l'entree et de la sortie si celui ci a un frere 
	if (pid[*curr_process] == 0)
	{
		//fonction de redirection a faire 
		//close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		dup2(pipe_fd[0], STDIN_FILENO);
	}
	// je genere un processus child avec l'appel fork
	pid[*curr_process] = fork();

	//je verifie si la naissance s'est bien deroulee 
	if (pid[*curr_process] < 1)
		return (perror("Fork: "));

	// je suis dans le processus parent et je verifie si j'ai d'autres processus child a generer 
	else if (pid[*curr_process] > 0 && *curr_process < cmd->nb_process - 1) 
	{
		*curr_process = *curr_process + 1;
		create_processus(cmd, curr_process);
	}
	return (0);


}
int main(int ac, char **av, char **envp)
{
	char *options[3] = {"ls", "-la", NULL};
    t_cmd	cmd;
	char	*cmd_path;
	int fork_res;
	int curr_process = 0;
	cmd.nb_process = 2;
	if (ac > 1)
	{
		cmd.commande = av[1];
	}
	cmd_path = NULL;
	locate_path(&cmd, envp);
	cmd_path = get_cmd_path(&cmd, cmd_path);
	printf("PATH FOR LS IS : %s\n", cmd_path);
	if (cmd.nb_process > 0)
		fork_res = create_processus(&cmd, &curr_process);

    if (execve(cmd_path, options, envp) == 0)
	 	printf("EXECVE SUCCES !\n");
    return (0);
}