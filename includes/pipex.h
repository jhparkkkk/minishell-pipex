#ifndef PIPEX_H
 #define PIPEX_H
#include <unistd.h>
// wait waitpid
#include <sys/wait.h>
#include "libft.h"

typedef struct s_cmd 
{
    char *commande;
    char **path;
}   t_cmd;

#endif