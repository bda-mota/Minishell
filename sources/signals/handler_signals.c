/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:10 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/24 11:12:15 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_readline_in_execution(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		get_status(130);
	}
	else if (signal == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
		get_status(131);
		rl_on_new_line();
		rl_replace_line("", 0);
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
