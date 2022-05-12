#ifndef PIPEX_H
 #define PIPEX_H
#include <unistd.h>
// wait waitpid
#include <sys/wait.h>
#include "libft.h"

#define FORK_ERROR 1
#define PIPE_ERROR 2
#define NB_BUILTIN 3
typedef struct s_cmd 
{
    char    *commande;
    char    **path_from_envp;
    char    *path;
    int     *fd;
    int     nb_builtin;
    int     **pipes;
}       t_cmd;

#endif