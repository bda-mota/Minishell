#include "../includes/minishell.h"

static void	read_line(t_token **token_h);

static void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
		return ;
}

int	main(void)
{
	t_token	*token_t;
	t_token	*token_h;

	init_token(&token_t, &token_h);
	read_line(&token_h);
	print_list(&token_t);
	deallocate_lst(&token_t, &token_h);
	exit(1);
}

static void	read_line(t_token **token_h)
{
	char				*input;
	struct sigaction	siga;

	siga = (struct sigaction){0};
	siga.sa_handler = signal_handler;
	sigaction(SIGINT, &siga, NULL);
	sigaction(SIGQUIT, &(struct sigaction){.sa_handler = SIG_IGN}, NULL);
	while (1)
	{
		input = readline("$minishell: ");
		add_history(input);
		if (input == NULL || (ft_strcmp(input, "exit") == 0))
		{
			free(input);
			return ;
		}
		course_inputs(token_h, input);
		free(input);
	}
	while (1)
		pause();
}
