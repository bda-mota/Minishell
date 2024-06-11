#include "../../includes/minishell.h"

int	check_command(t_tree *tree, char *command)
{
	char	*first_command;

	tree->command_child = ft_split(command, ' ');
	if (tree->command_child == NULL)
	{
		printf("Error ao dar split\n");
		return (0);
	}
	first_command = tree->command_child[0];
	if (access(first_command, X_OK) == 0)
	{
		tree->executable = ft_strdup(first_command);
		return (1);
	}
	find_command(tree, first_command);
	if (tree->executable == NULL)
	{
		display_error_exec("command not found", command);
		free_simple_child(tree->command_child, NULL);
		return (0);
	}
	return (1);
}

void	find_command(t_tree *tree, char *cmd)
{
	int		i;
	char	**paths;

	i = 0;
	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0)
	{
		tree->executable = ft_strdup(cmd);
		return ;
	}
	paths = get_paths(NULL);
	while (paths[i])
	{
		tree->executable = ft_strjoin(paths[i], cmd);
		if (access(tree->executable, X_OK) == 0)
			return ;
		free(tree->executable);
		i++;
	}
	tree->executable = NULL;
}
