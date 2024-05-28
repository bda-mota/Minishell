#include "../../includes/minishell.h"

char	*check_command(t_tree *tree)
{
	char	*command;
	char	*complete_command;

	command = tree->command_child[0];
	if (access(command, X_OK) == 0)
		return (command);
	complete_command = find_command(tree, command);
	if (complete_command == NULL)
		display_error_exec("command not found", command);
	return (complete_command);
}

char	*find_command(t_tree *tree, char *cmd)
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
		tree->command = ft_strjoin(paths[i], take_first[0]);
		if (access(tree->command, X_OK) == 0)
		{
			ft_free_matrix(take_first);
			return (tree->command);
		}
		free(tree->command);
		i++;
	}
	tree->command = NULL;
	ft_free_matrix(take_first);
	return (NULL);
}
