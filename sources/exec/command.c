#include "../../includes/minishell.h"

char	*check_command(t_tree *tree)
{
	char	*command;
	char	*complete_command;

	command = tree->command_child[0];
	if (access(command, X_OK) == 0)
		return (command);
	copy_path_to_exec(tree);
	complete_command = find_command(tree, command);
	if (complete_command == NULL)
	{
		ft_free_matrix(tree->path_cmd);
		ft_free_matrix(tree->command_child);
	}
	return (complete_command);
}

char	*find_command(t_tree *tree, char *cmd)
{
	int		i;
	char	*aux_cmd;
	char	**take_first;

	i = 0;
	take_first = ft_split(cmd, ' ');
	if (take_first == NULL)
		printf("error\n");
	while (tree->path_cmd[i])
	{
		aux_cmd = ft_strjoin(tree->path_cmd[i], take_first[0]);
		if (access(aux_cmd, X_OK) == 0)
		{
			ft_free_matrix(take_first);
			return (aux_cmd);
		}
		free(aux_cmd);
		i++;
	}
	get_paths_cmd(tree->path_cmd);
	ft_free_matrix(take_first);
	display_error_exec("command not found", cmd);
	return (NULL);
}
