#include "../../includes/minishell.h"

int	catalog_inputs(char *c, size_t *i)
{
	if (ft_isspace(c[*i]) == 1)
		return (SSPACE);
	else if (!ft_strnchr(&c[*i], '<', 2))
		return (HEREDOC);
	else if (!ft_strnchr(&c[*i], '>', 2))
		return (APPEND);
	else if (!ft_strnchr(&c[*i], '<', 1))
		return (INPUT);
	else if (!ft_strnchr(&c[*i], '>', 1))
		return (OUTPUT);
	else if (!ft_strnchr(&c[*i], '|', 1))
		return (PIPE);
	else if (!ft_strnchr(&c[*i], '"', 1))
		return (DOUBLE);
	else if (!ft_strnchr(&c[*i], '\'', 1))
		return (SIMPLE);
	else if (!ft_strnchr(&c[*i], '(', 1))
		return (BLOCK);
	else
		return (WORD);
}

void	handle_quotes(t_token **token, char *input, size_t *i)
{
	size_t	size_double;
	size_t	size_simple;

	size_double = count_double_quote(input, &(*i));
	if (size_double != 0)
		handle_double(token, input, &(*i), size_double);
	size_simple = count_simple_quote(input, &(*i));
	if (size_simple != 0)
		handle_simple(token, input, &(*i), size_simple);
}

void	tokenizer(t_minishell *shell)
{
	size_t	i;

	i = 0;
	if (check_sintax(shell->input) == 1)
		return ;
	while (shell->input[i] && (i != ft_strlen(shell->input)))
	{
		handle_quotes(&shell->token, shell->input, &i);
		if (catalog_inputs(shell->input, &i) == WORD)
			handle_word(&shell->token, shell->input, &i);
		else if (catalog_inputs(shell->input, &i) == PIPE)
			handle_pipe(&shell->token, shell->input, &i);
		else if (catalog_inputs(shell->input, &i) == INPUT)
			handle_input(&shell->token, shell->input, &i);
		else if (catalog_inputs(shell->input, &i) == OUTPUT)
			handle_output(&shell->token, shell->input, &i);
		else if (catalog_inputs(shell->input, &i) == HEREDOC)
			handle_heredoc(&shell->token, shell->input, &i);
		else if (catalog_inputs(shell->input, &i) == APPEND)
			handle_append(&shell->token, shell->input, &i);
		else if (catalog_inputs(shell->input, &i) == BLOCK)
			handle_block(&shell->token, shell->input, &i);
		i++;
	}
}
