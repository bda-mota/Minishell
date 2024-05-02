#include "../includes/minishell.h"

static char	*prompt(void);

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
	char	*input;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		input = prompt();
		if (input == NULL)
		{
			ft_putstr_fd("exit\n", 1);
			return (EXIT_SUCCESS);
		}
		pause();
	}
	return (EXIT_SUCCESS);
}

static char	*prompt(void)
{
	t_token	*token_tail;
	t_token	*token_h;
	char	*input;

	while (1)
	{
		init_token(&token_tail, &token_h);
		input = readline("$minishell: ");
		if (input == NULL || !ft_strcmp(input, "exit"))
		{
			free(input);
			rl_clear_history();
			deallocate_lst(&token_tail, &token_h);
			return (NULL);
		}
		add_history(input);
		course_inputs(&token_tail, &token_h, input);
		remove_first(&token_tail);
		free(input);
		print_list(&token_tail);
		deallocate_lst(&token_tail, &token_h);
	}
	return (NULL);
}
