#include "../../includes/minishell.h"

extern char **environ;

char    **count_size_environ()
{
    char    **env;
    char    **environ_copy;
    int     num_vars;

    env = environ;
    environ_copy = NULL;
    num_vars = 0;
    while (*env)
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
    char    **env;
    char    **environ_copy;
    int     i;

    env = environ;
    environ_copy = count_size_environ();
    i = 0;
    while (env[i])
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
    new_environ[num_vars] = ft_strdup(new_var);
    if (!new_environ[num_vars])
    {
        free(new_environ);
        return (NULL);
    }
    free(environ_copy);
    return(new_environ);
}

void    free_environ(char **environ)
{
    int i;

    i = 0;
    while (environ[i]) 
    {
        free(environ[i]);
        i++;
    }
    free(environ);
}
