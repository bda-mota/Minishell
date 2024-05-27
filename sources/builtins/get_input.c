#include "../../includes/minishell.h"

int	is_builtin(char *command)
{
	if (ft_strcmp(command, "echo") == 0 || ft_strcmp(command, "pwd") == 0
		|| ft_strcmp(command, "export") == 0 || ft_strcmp(command, "env") == 0
		|| ft_strcmp(command, "unset") == 0 || ft_strcmp(command, "cd") == 0
		|| ft_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}

char	**split_command(char *content)
{
	char	**result;
	char	*space;

	result = malloc(2 * sizeof(char *));
	space = ft_strchr(content, ' ');
	if (space)
	{
		result[0] = ft_strndup(content, space - content);
		result[1] = ft_strdup(space + 1);
	}
	else
	{
		result[0] = ft_strdup(content);
		result[1] = NULL;
	}
	return (result);
}

void	find_builtins(t_minishell *shell, t_tree *tree)
{
	char	**cmd_args;
	char	*command;
	char	*args;

	cmd_args = split_command(tree->content);
	command = cmd_args[0];
	args = cmd_args[1];

	if (is_bultin(command))
	{
		if (ft_strcmp("echo", command) == 0)
			echo(args);
		else if (ft_strcmp("pwd", command) == 0)
			pwd();
		else if (ft_strcmp("export", command) == 0)
			export(shell, args);
		else if (ft_strcmp("env", command) == 0)
			env(shell);
		else if (ft_strcmp("unset", command) == 0)
			unset(shell, args);
		else if (ft_strcmp("cd", command) == 0)
			cd(args);
	}
}
