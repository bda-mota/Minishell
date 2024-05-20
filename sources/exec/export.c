#include "../../includes/minishell.h"

/*
1. environ não sera utilizada, apenas foi implementada aqui pois no meu Ubuntu 
ela não aparece como uma macro de ambiente na 42 ela aparece e deve ser modificada.
2. Antes de encerrar o programa a matriz new_environ precisa ser liberada para não causar leaks
3. Esta é apenas a estrutura da criação de novas variáveis -> ela precisa ser ajustada assim como
as outras builtins.
*/ 

extern char **environ;

char    **count_size_environ()
{
    int num_vars;
    char    **environ_copy;
    char    **env;

    num_vars = 0;
    environ_copy = NULL;
    env = environ;
    while (*env != NULL)
    {
        num_vars++;
        env++;
    }
    environ_copy = ft_calloc(num_vars + 1, sizeof(char *));
    if (!environ_copy)
        return (NULL);
    return (environ_copy);
}

char    **copy_environ()
{
    char    **environ_copy;
    char    **env;
    int     i;
    int     j;

    environ_copy = count_size_environ();
    env = environ;
    i = 0;
    if (!environ_copy)
        return (NULL);
    while (env[i] != NULL)
    {
        environ_copy[i] = ft_strdup(env[i]);
        if (!environ_copy[i])
        {
            while (i--)
                free(environ_copy[i]);
            free(environ_copy);
            return NULL;
        }
        i++;
    }
    return (environ_copy);
}

char    **create_new_environ(char **environ_copy, int num_vars)
{
    char    **new_environ;
    int i;

    i = 0;
    new_environ = ft_calloc(num_vars + 2, sizeof(char *));
    if (!new_environ)
        return (NULL);
    while (i < num_vars)
    {
        new_environ[i] = environ_copy[i];
        i++;
    }
    return (new_environ);
}

char    **add_variable_to_environ(char **environ_copy, char *new_var)
{
    char    **new_environ;  
    int     num_vars;

    num_vars = 0;
    while (environ_copy[num_vars])
        num_vars++;
    new_environ = create_new_environ(environ_copy, num_vars);
    if (!new_environ)
        return (NULL);
    new_environ[num_vars] = ft_strdup(new_var);
    if (!new_environ[num_vars])
    {
        free(new_environ);
        return (NULL);
    }
    free(environ_copy);
    return(new_environ);
}
