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

void	course_inputs(t_token **token, char *input)
{
	size_t	i;

	i = 0;
	if (check_sintax(input) == 1)
		return ;
	while (input[i] && (i != ft_strlen(input)))
	{
		handle_quotes(token, input, &i);
		if (catalog_inputs(input, &i) == WORD)
			handle_word(token, input, &i);
		else if (catalog_inputs(input, &i) == PIPE)
			handle_pipe(token, input, &i);
		else if (catalog_inputs(input, &i) == INPUT)
			handle_input(token, input, &i);
		else if (catalog_inputs(input, &i) == OUTPUT)
			handle_output(token, input, &i);
		else if (catalog_inputs(input, &i) == HEREDOC)
			handle_heredoc(token, input, &i);
		else if (catalog_inputs(input, &i) == APPEND)
			handle_append(token, input, &i);
		else if (catalog_inputs(input, &i) == BLOCK)
			handle_block(token, input, &i);
		i++;
	}
}

int	significant_tokens(t_token *tokens)
{
	int		count;
	t_token	*curr;

	count = 0;
	curr = tokens;
	while (curr != NULL)
	{
		if (curr->type != WORD && curr->type != SIMPLE
			&& curr->type != DOUBLE && curr->type != BLOCK)
			count++;
		curr = curr->next;
	}
	return (count);
}
