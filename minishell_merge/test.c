#include "execution.h"

/* Les fonctions commenceant par _* sont des utilitaires (tests)*/

void	_print_pipes_tab(t_cmd *cmd)
{
	int i = 0;
	int j = 0;

	while( i < NB_BUILTIN - 1)
	{
		j = 0;
		while(j < 2)
		{
			printf("PIPE no. %d = %d ", i, cmd->pipes[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}


/* Je liste tous les chemins possibles avec split en ajoutant
"/" a la fin de chaque chemin. */

void get_path(t_cmd *cmd, char *envp)
{
     int i = 0;
    (void)cmd;
    
    cmd->path_from_envp = ft_split(envp,':');
    while(cmd->path_from_envp[i])
    {
        cmd->path_from_envp[i] = ft_strjoin(cmd->path_from_envp[i], "/");
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
int	get_cmd_path(t_cmd *cmd)
{
	int i;

	i = 0;

	while (cmd->path_from_envp[i])
	{
		cmd->path = ft_strjoin(cmd->path_from_envp[i], cmd->builtin_1);
		if (access(cmd->path, F_OK | X_OK) == 0)
			return(0);
		i++;
	}
	return (1);

}

void	execute_builtin(t_cmd *cmd, char **envp)
{
	char	*options[3] = {"echo", "-1", NULL}; // il faudra se referer au tab parsing 

	if (execve(cmd->path, options, envp) == 0)
	 	printf("EXECVE SUCCES !\n");
}

int	exec_one_builtin(t_cmd *cmd, char **envp)
{
	(void)cmd;
	(void)envp;

	int end[2];
	pid_t pid;
	//int reader;
	//char buf[10];
	int status;

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
		execute_builtin(cmd, envp);
		close(end[1]); // l'enfant a fini d'ecrire alors je ferme le bout ecriture 
		return (0);
	}
	else
	{
		// je suis dans le processus parent
		close(end[1]); // le parent ne va rien ecrire alors je ferme le bout lecture
		waitpid(pid, &status, 0); // le parent attend son fils
		if (WIFEXITED(status))
            printf("Pere : Il a termine normalement, code sortie %d\n", WEXITSTATUS(status));
        else
            printf("Pere : Il a ete interrompu...\n");
	}
	return (0);
}

int **destroy_pipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
	return (NULL);
}

// void	redirection(t_cmd *cmd)
// {

// }

/* Je modifie les sorties et les entrees standard
pour chaque pipe */ 
void	redirection_pipes(t_cmd *cmd)
{
	int i = 0;
	while(i < NB_BUILTIN - 1)
	{
		if (i != 0)
			dup2(cmd->pipes[i][0], STDIN_FILENO);
		if (i != NB_BUILTIN -1)
			dup2(cmd->pipes[i][1], STDOUT_FILENO);
		i++;
	}
}

/* J'initialise le tableau de pipes afin de permettre la
communication entre les processus */ 
int	init_pipes(t_cmd *cmd)
{
	int i;

	cmd->pipes = malloc(sizeof(int *) * (NB_BUILTIN - 1));
	if (!cmd->pipes)
		return (PIPE_ERROR);
	i = 0;
	while(i < NB_BUILTIN - 1)
	{
		cmd->pipes[i] = malloc(sizeof(int) * 2);
		if (!cmd->pipes[i])
			return(destroy_pipes(cmd->pipes), PIPE_ERROR);
		if (pipe(cmd->pipes[i]) == -1)
			return(PIPE_ERROR);
		cmd->pipes[i][0] = 0;
		cmd->pipes[i][1] = 1;
		i++;
	}
	return(0);
}

/* Je cree les processus */
int	create_child(t_cmd *cmd, char **envp)
{
	pid_t child[NB_BUILTIN];
	int i = 0;
	int status; 
	while (i < NB_BUILTIN)
	{
		child[i] = fork();
		if (child[i] == -1)
			return (FORK_ERROR);
		if (child[i] == 0)
		{
			printf("Je suis le fils no. %d", i);
			execute_builtin(cmd, envp);
			//je suis le 1er fils
		}
		else if (child[i] > 0)
		{
			// je suis le pere
			close(cmd->pipes[i][0]); // le parent ne va rien ecrire alors je ferme le bout lecture
			waitpid(child[i], &status, 0); // le parent attend son fils
			if (WIFEXITED(status))
            	printf("Pere : Il a termine normalement, code sortie %d\n", WEXITSTATUS(status));
        	else
            	printf("Pere : Il a ete interrompu...\n");
		}
		i++;
	}
	return (0);
}

void builtin_echo(t_cmd *cmd)
{
	
}

int main(int ac, char **av, char **envp)
{
    t_cmd	cmd;
	cmd.nb_builtin = 3;
	
	if (ac > 1)
	{
		cmd.builtin_1 = av[1];
	}
	cmd.path = NULL;
	locate_path(&cmd, envp);
	get_cmd_path(&cmd);
	printf("PATH FOR %s IS : %s\n", av[1], cmd.path);
	if (init_pipes(&cmd) == PIPE_ERROR)
		return (write(2, "pipe error\n", 11), 0);
	redirection_pipes(&cmd);
	exec_one_builtin(&cmd, envp);
	//if (create_child(&cmd) == FORK_ERROR)
	//	return (write(2, "fork error\n", 11), 0);
    return (0);
}