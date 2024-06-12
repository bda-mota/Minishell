#include "../../includes/minishell.h"

int	check_command(t_tree *tree, char *command)
{
	char	*first_command;

	tree->command_child = ft_special_split(command);
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
		display_error_exec("command not found", first_command);
		free_simple_child(tree->command_child, NULL);
		return (0);
	}
	return (1);
}

void	find_command(t_tree *tree, char *cmd)
{
	int		i;
	char	**paths;
	char	*old;

	i = 0;
	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0)
	{
		tree->executable = ft_strdup(cmd);
		return ;
	}
	paths = get_paths(NULL);
	old = cmd;
	remove_quotes_cmd(&cmd);
	while (paths[i])
	{
		tree->executable = ft_strjoin(paths[i], cmd);
		if (access(tree->executable, X_OK) == 0)
		{
			if (old != cmd)
				free(cmd);
			return ;
		}
		free(tree->executable);
		i++;
	}
	if (old != cmd)
		free(cmd);
	tree->executable = NULL;
}

void	remove_quotes_cmd(char **cmd)
{
	int		i;
	int		len;
	char	*new_content;

	len = ft_strlen(*cmd);
	i = 0;
	if ((*cmd)[0] == '\'' || (*cmd)[0] == '"')
	{
		new_content = ft_calloc(sizeof(char), len -1);
		while (i < len - 2)
		{
			new_content[i] = (*cmd)[i + 1];
			i++;
		}
		*cmd = new_content;
	}
}