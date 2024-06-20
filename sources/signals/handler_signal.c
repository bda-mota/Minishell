#include "../../includes/minishell.h"

void	initialize_signals(void)
{
	fprintf(stderr, "Inicializando sinais...\n");
	signal(SIGINT, signal_readline);
	signal(SIGQUIT, SIG_IGN);
	fprintf(stderr, "Sinais inicializados: SIGINT -> signal_readline, SIGQUIT -> SIG_IGN\n");
}

void	signal_readline(int signal)
{
	fprintf(stderr, "Entrou em signal_readline com sinal: %d\n", signal);
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_execution(int pid)
{
	if (pid == 0)
	{
		fprintf(stderr, "FILHO: configurando sinais para comportamento padrão.\n");
		fprintf(stderr, "FILHO: SIGINT configurado para SIG_DFL.\n");
		signal(SIGINT, SIG_DFL);
		fprintf(stderr, "FILHO: SIGQUIT configurado para SIG_DFL.\n");
		signal(SIGQUIT, SIG_DFL);
	}
	else
	{
		fprintf(stderr, "PAI: configurando sinais para comportamento padrão.\n");
		signal(SIGINT, signal_readline);
		signal(SIGQUIT, SIG_DFL);
	}
}

void	signal_heredoc(void)
{
    fprintf(stderr, "Sinais inicializados: SIGINT -> signal_heredoc, SIGQUIT -> SIG_IGN\n");
	signal(SIGINT, handler_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	handler_heredoc(int signal)
{
	fprintf(stderr, "HEREDOC: Entrou em handler_heredoc com sinal: %d\n", signal);
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
