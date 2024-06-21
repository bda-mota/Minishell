/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 16:41:16 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	executor(t_tree *tree)
{
	if (tree->type == PIPE)
		return (pipe_execution(tree->left, tree->right));
	if (the_branch_is_redir(tree))
		return (redirs_execution(tree));
	else
	{
		if (is_builtin(tree->content))
			return (execute_builtins(tree));
		else
			return (execute(tree, tree->content));
	}
}

int	execute(t_tree *tree, char *command)
{
	int	pid;
	int	status;

	status = 0;
	check_command(tree, command);
	pid = fork();
	if (pid == -1)
		fork_error();
	signal_execution(pid);
	if (pid == 0)
	{
		rl_clear_history();
		execve(tree->executable, tree->command_child, *get_env_copy(NULL));
		treat_errors(tree, &status);
	}
	waitpid(pid, &status, 0);
	free_simple_child(tree->command_child, tree->executable);
	set_status(status);
	return (WEXITSTATUS(status));
}

void	set_status(int status)
{
	if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == SIGQUIT)
		{
			signal(SIGPIPE, SIG_IGN);
			get_status(131);
		}
		else if (status == SIGINT)
			get_status(130);
	}
	else if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		get_status(status);
	}
	else
		get_status(0);
}
