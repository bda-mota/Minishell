/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:44:20 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 21:23:53 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*prompt(void);

int	main(void)
{
	char	*input;

	while (1)
	{
		input = prompt();
		if (input == NULL)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

static char	*prompt(void)
{
	t_minishell	shell;

	shell.env_copy = copy_environ();
	init_shell(&shell);
	get_minishell(&shell);
	get_status(0);
	while (1)
	{
		init_structs(&shell);
		initialize_signals();
		shell.input = readline(PURPLE"$BaByshell: "WHITE);
		add_history(shell.input);
		if (shell.input == NULL)
		{
			rl_clear_history();
			printf("exit\n");
			free_minishell(&shell);
			return (NULL);
		}
		processor(&shell);
		free_execution();
	}
	free_minishell(&shell);
	return (NULL);
}

void	processor(t_minishell *shell)
{
	tokenizer(shell);
	if (!shell->token || !check_grammar(&shell->token))
		return ;
	inspect_types(&shell->token);
	rearrange_tokens(&shell->token);
	expand_variable(&shell->token, *get_env_copy(NULL));
	if (shell->token && shell->token->next == NULL
		&& shell->token->content[0] == '\0')
	{
		deallocate_lst(&shell->token);
		ft_printf_fd(STDOUT_FILENO, "\n");
		return ;
	}
	if (!has_heredoc(shell->token))
		if (heredoc(&shell->token) == 1)
			return ;
	build_tree(&shell->tree, &shell->token);
	executor(shell->tree);
	down_tree(&shell->tree);
}
