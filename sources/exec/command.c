#include "../../includes/minishell.h"

void	check_command(t_tree *tree)
{
	char	*command;

	command = tree->command_child[0];
	if (access(command, X_OK) == 0)
		return ;
	find_command(tree, command);
	if (tree->executable == NULL)
	{
		display_error_exec("command not found", command);
		get_status(127);
		free_simple_child(tree->command_child, NULL);
	}
}

void	find_command(t_tree *tree, char *cmd)
{
	int		i;
	char	**paths;

	i = 0;
	paths = get_paths(NULL);
	while (paths[i])
	{
		tree->executable = ft_strjoin(paths[i], cmd);
		if (access(tree->executable, X_OK) == 0)
			return ;
		free(tree->executable);
		i++;
	}
	tree->executable = cmd;
}
