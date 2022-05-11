#ifndef PIPEX_H
 #define PIPEX_H
#include <unistd.h>
// wait waitpid
#include <sys/wait.h>
#include "libft.h"

#define FORK_ERROR 1

typedef struct s_cmd 
{
    char    *commande;
    char    **path;
    int     *fd;
    int     nb_builtin;   
}       t_cmd;

#endif