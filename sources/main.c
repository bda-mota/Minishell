#include "../includes/minishell.h"

<<<<<<< HEAD
static void	read_line(t_token **token_h, t_token **token_t);
=======
static void	read_line(t_token **token_t, t_token **token_h);
>>>>>>> 6f5adc1dcd5db01bd8c6348aacdfc0a7434c1ac6

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
<<<<<<< HEAD
	//remover primeiro nó na lista 
	read_line(&token_h, &token_t);
=======
	read_line(&token_t, &token_h);
>>>>>>> 6f5adc1dcd5db01bd8c6348aacdfc0a7434c1ac6
	print_list(&token_t);
	deallocate_lst(&token_t, &token_h);
	exit(1);
}

<<<<<<< HEAD
static void	read_line(t_token **token_h, t_token **token_t)
=======
static void	read_line(t_token **token_t, t_token **token_h)
>>>>>>> 6f5adc1dcd5db01bd8c6348aacdfc0a7434c1ac6
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
			rl_clear_history();
			return ;
		}
<<<<<<< HEAD
		course_inputs(token_h, token_t, input);
=======
		course_inputs(token_h, input);
		remove_first(token_t);
>>>>>>> 6f5adc1dcd5db01bd8c6348aacdfc0a7434c1ac6
		free(input);
	}
	while (1)
		pause();
}
