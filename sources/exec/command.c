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
		free_simple_child(tree->command_child, NULL);
	}
}

void	find_command(t_tree *tree, char *cmd)
{
	int		i;
	char	**take_first;
	char	**paths;

	i = 0;
	paths = get_paths(NULL);
	take_first = ft_split(cmd, ' ');
	if (take_first == NULL)
		printf("error\n");
	while (paths[i])
	{
		tree->executable = ft_strjoin(paths[i], take_first[0]);
		if (access(tree->executable, X_OK) == 0)
		{
			ft_free_matrix(take_first);
			return ;
		}
		free(tree->executable);
		i++;
	}
	tree->executable = NULL;
	ft_free_matrix(take_first);
}
