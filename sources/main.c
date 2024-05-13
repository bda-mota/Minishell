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
			ft_printf_fd("\n", 1);
			return (EXIT_SUCCESS);
		}
		pause();
	}
	return (EXIT_SUCCESS);
}

static char	*prompt(void)
{
	t_token	*token;
	char	*input;
	t_tree	*root;

	root = NULL;
	while (1)
	{
		token = NULL;
		input = readline(PURPLE"$BaByshell: "WHITE);
		add_history(input);
		if (input == NULL || !ft_strcmp(input, "exit"))
		{
			free(input);
			rl_clear_history();
			deallocate_lst(&token);
			return (NULL);
		}
		course_inputs(&token, input);
		if (significant_tokens(token) > 0)
		{
			build_tree(&root, &token, LEFT);
			down_tree(root);
		}
		else
			deallocate_lst(&token);
		//print_list(&token);
		free(input);
	}
	return (NULL);
}
