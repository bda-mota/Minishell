#include "../../includes/minishell.h"

static void	compare_variable(char *old, char *cmd);
static int	check_executable(char *executable, char *cmd, char *old);

void	check_command(t_tree *tree, char *command)
{
	char	*first_command;

	tree->command_child = ft_special_split(command);
	if (tree->command_child == NULL)
		printf("Error ao dar split\n");
	first_command = tree->command_child[0];
	if (access(first_command, X_OK) == 0)
		tree->executable = first_command;
	find_command(tree, first_command);
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
		if (!check_executable(tree->executable, cmd, old))
			return ;
		free(tree->executable);
		i++;
	}
	compare_variable(old, cmd);
	tree->executable = ft_strdup(old);
	get_status(127);
}

static int	check_executable(char *executable, char *cmd, char *old)
{
	if (access(executable, X_OK) == 0)
	{
		compare_variable(old, cmd);
		return (0);
	}
	return (1);
}

static void	compare_variable(char *old, char *cmd)
{
	if (old != cmd)
		free(cmd);
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
		new_content = ft_calloc(sizeof(char), len - 1);
		while (i < len - 2)
		{
			new_content[i] = (*cmd)[i + 1];
			i++;
		}
		*cmd = new_content;
	}
}

