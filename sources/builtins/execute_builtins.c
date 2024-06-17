#include "../../includes/minishell.h"

void free_split_command(char **cmd_args)
{
    int i;
	
	i = 0;
    while (cmd_args[i] != NULL)
    {
        free(cmd_args[i]);
        i++;
    }
    free(cmd_args);
}


int	is_builtin(char *content)
{
	char	*command;
	size_t	len;

	len = ft_strcspn(content, " ");
	if (len == 0)
		return (0);
	command = ft_strndup(content, len);
	if (ft_strcmp(command, "echo") == 0 || ft_strcmp(command, "pwd") == 0
		|| ft_strcmp(command, "export") == 0 || ft_strcmp(command, "env") == 0
		|| ft_strcmp(command, "unset") == 0 || ft_strcmp(command, "cd") == 0
		|| ft_strcmp(command, "exit") == 0)
	{
		free(command);
		return (1);
	}
	free(command);
	return (0);
}

char	**split_command(char *content)
{
	char	**result;
	char	*space;

	result = ft_calloc(sizeof(char *), 3);
	if (!result)
		return (NULL);
	space = ft_strchr(content, ' ');
	if (space)
	{
		result[0] = ft_strndup(content, space - content);
		result[1] = ft_strdup(space + 1);
		result[2] = NULL;
	}
	else
	{
		result[0] = ft_strdup(content);
		result[1] = NULL;
	}
	return (result);
}

void	execute_builtins(t_tree *tree)
{
	t_minishell	*shell_ptr;
	char		**old_cmd_args;
	char		**environ;
	char		*command;
	char		*args;

	shell_ptr = get_minishell(NULL);
	environ = *get_env_copy(NULL);
	old_cmd_args = shell_ptr->cmd_args;
	shell_ptr->cmd_args = split_command(tree->content);
	command = shell_ptr->cmd_args[0];
	args = shell_ptr->cmd_args[1];
	if (ft_strcmp("echo", command) == 0)
		ft_echo(args);
	else if (ft_strcmp("pwd", command) == 0)
		ft_pwd();
	else if (ft_strcmp("export", command) == 0)
		ft_export(environ, args);
	else if (ft_strcmp("env", command) == 0)
		ft_env(environ);
	else if (ft_strcmp("unset", command) == 0)
		ft_unset(environ, args);
	else if (ft_strcmp("cd", command) == 0)
		ft_cd(args);
	else if (ft_strcmp("exit", command) == 0)
		ft_exit(args);
	free_split_command(shell_ptr->cmd_args);
	shell_ptr->cmd_args = old_cmd_args;
}
