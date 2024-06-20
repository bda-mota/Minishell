#include "../../includes/minishell.h"

static void	remove_quotes_matrix(char **cmd_args);
static void	remove_quotes_cmd(char **cmd);

void	check_command(t_tree *tree, char *command)
{
	char	*first_command;

	tree->command_child = ft_special_split(command);
	if (tree->command_child == NULL)
		printf("Error ao dar split\n");
	remove_quotes_matrix(tree->command_child);
	first_command = tree->command_child[0];
	if (access(first_command, X_OK) == 0)
		tree->executable = first_command;
	find_command(tree, first_command);
}

void	find_command(t_tree *tree, char *cmd)
{
	int		i;
	char	**paths;

	i = 0;
	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0)
	{
		tree->executable = ft_strdup(cmd);
		get_status(127);
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
	tree->executable = ft_strdup(cmd);
	get_status(127);
}

static void	remove_quotes_matrix(char **cmd_args)
{
	int	i;

	i = 0;
	while (cmd_args[i])
	{
		remove_quotes_cmd(&cmd_args[i]);
		i++;
	}
}

static void	remove_quotes_cmd(char **cmd)
{
	int		i;
	int		len;
	char	*new_content;

	len = ft_strlen(*cmd);
	i = 0;
	if ((*cmd)[0] == '\'' || (*cmd)[0] == '"')
	{
		new_content = ft_calloc(sizeof(char), len + 1);
		while ((*cmd)[i + 1] && cmd[0][i + 1] != '\'' && cmd[0][i + 1] != '"')
		{
			new_content[i] = (*cmd)[i + 1];
			i++;
		}
		free(*cmd);
		*cmd = new_content;
	}
}
