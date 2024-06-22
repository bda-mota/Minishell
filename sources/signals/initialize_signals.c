/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:15 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 21:14:49 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	initialize_signals(void)
{
	signal(SIGINT, signal_readline);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_execution(int pid)
{
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGPIPE, SIG_DFL);
	}
	else
	{
		signal(SIGINT, signal_readline_in_execution);
		signal(SIGQUIT, signal_readline_in_execution);
	}
}

void	signal_heredoc(void)
{
	signal(SIGINT, handler_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
