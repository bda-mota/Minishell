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
	while (1)
	{
		shell.exec = NULL;
		shell.token = NULL;
		shell.tree = NULL;
		shell.input = readline(PURPLE"$BaByshell: "WHITE);
		add_history(shell.input);
		if (shell.input == NULL || !ft_strcmp(shell.input, "exit"))
		{
			free(shell.input);
			rl_clear_history();
			return (NULL);
		}
		manipulate_tokens(&shell);
		free(shell.input);
	}
	return (NULL);
}

void	manipulate_tokens(t_minishell *shell)
{
	course_inputs(shell);
	//build_path(shell);
	//find_builtins(&shell->token, &shell->exec);
	inspect_types(&shell->token);
	rearrange_tokens(&shell->token);
	build_tree(&shell->tree, &shell->token, LEFT);
	//print_tree(shell->tree);
	//find_path(&(*shell)->exec);
	//direct_to_exec(&(*shell)->tree, &(*shell)->exec);
	down_tree(&(shell->tree));
	shell->tree = NULL;
}
