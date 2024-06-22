/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:10 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/22 13:51:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_readline_in_execution(int signal)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	(void)shell;
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		get_status(130);
	}
	else if (signal == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
		get_status(131);
		rl_clear_history();
		//free_pipe_child(); -> se tirar isso n da leak no cat 
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		get_status(131);
	}
}

// aqui tem que liberar memória -> essa função foi chamada logo após abrir um fork na função pipe_execution
void	signal_readline_in_pipe(int signal)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	(void)shell;
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		get_status(130);
	}
	else if (signal == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
		get_status(131);
		rl_clear_history();
		//free_pipe_child(); -> se tirar isso n da leak no cat 
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		get_status(131);
	}
}

void	handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		close(0);
		get_status(130);
	}
}

void	signal_readline(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		get_status(130);
	}
}
