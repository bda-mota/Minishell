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
	t_minishell	shell;

	shell.env_copy = copy_environ();
	init_shell(&shell);
	while (1)
	{
		init_structs(&shell);
		shell.input = readline(PURPLE"$BaByshell: "WHITE);
		add_history(shell.input);
		if (shell.input == NULL || !ft_strcmp(shell.input, "exit"))
		{
			rl_clear_history();
			free_minishell(&shell);
			return (NULL);
		}
		processor(&shell);
		free_execution(shell.tree, shell.input);
	}
	free_minishell(&shell);
	return (NULL);
}

void	processor(t_minishell *shell)
{
	tokenizer(shell);
	inspect_types(&shell->token);
	rearrange_tokens(&shell->token);
	build_tree(&shell->tree, &shell->token, LEFT);
	if (!shell->complete_path)
		find_path(shell);
	get_tree(shell->tree);
	direct_to_exec(shell->tree);
}
