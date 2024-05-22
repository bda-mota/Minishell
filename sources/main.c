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
		manipulate_tokens(&token, &root, input);
		free(input);
	}
	return (NULL);
}

void	manipulate_tokens(t_token **token, t_tree **root, char *input)
{
	t_exec	*execution;

	execution = ft_calloc(sizeof(t_exec), 1);
	if (!execution)
		return ;
	course_inputs(token, input);
	get_expand_variable(token);
	inspect_types(token);
	rearrange_tokens(token);
	build_tree(root, token, LEFT);
	find_path(&execution);
	direct_to_exec(root, &execution);
	down_tree(root);
	root = NULL;
}

	// curr = traverse_tree(root);
	// while (curr)
	// {
	// 	implement(&execution, curr->content);
	// 	curr = traverse_tree(root);
	// }
