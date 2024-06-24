/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:21 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/24 10:13:03 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		tree->executable = ft_strdup(first_command);
		return ;
	}
	find_command(tree, first_command);
}

void	find_command(t_tree *tree, char *cmd)
{
	int			i;
	t_minishell	*shell;

	i = 0;
	shell = get_minishell(NULL);
	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0)
	{
		tree->executable = ft_strdup(cmd);
		get_status(127);
		return ;
	}
	find_path(shell);
	if (shell->complete_path != NULL)
	{
		while (shell->paths[i])
		{
			tree->executable = ft_strjoin(shell->paths[i], cmd);
			if (access(tree->executable, X_OK) == 0)
				return ;
			free(tree->executable);
			i++;
		}
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
	char	c;
	char	*new_content;

	i = 0;
	len = ft_strlen(*cmd);
	c = '\0';
	if ((*cmd)[0] == '\'' || (*cmd)[0] == '"')
	{
		c = (*cmd)[0];
		new_content = ft_calloc(sizeof(char), len + 1);
		while ((*cmd)[i + 1] && cmd[0][i + 1] != c)
		{
			new_content[i] = (*cmd)[i + 1];
			i++;
		}
		free(*cmd);
		*cmd = new_content;
	}
}
