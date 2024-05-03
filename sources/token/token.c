#include "../../includes/minishell.h"

int	catalog_inputs(char *c, size_t *i)
{
	if (ft_isspace(c[*i]) == 1)
		return (SSPACE);
	else if (!ft_strnchr(&c[*i], '<', 3) || !ft_strnchr(&c[*i], '>', 3)
		|| !ft_strnchr(&c[*i], '|', 3) || !ft_strnchr(&c[*i], '|', 2)
		|| !ft_strnchr(&c[*i], '&', 2))
		return (ERROR);
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
	else if (!ft_strnchr(&c[*i], '(', 1) || !ft_strnchr(&c[*i], ')', 1))
		return (BLOCK);
	else
		return (WORD);
}

void	course_inputs(t_token **token_tail, t_token **token_h, char *input)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (check_sintax(input, token_tail, token_h) == 1)
		return ;
	while (input[i] && (i != ft_strlen(input)))
	{
		size = count_quote(input, &i);
		if (size != 0)
			handle_quote(token_h, input, &i, size);
		else if (catalog_inputs(input, &i) == WORD)
			handle_word(token_h, input, &i);
		else if (catalog_inputs(input, &i) == PIPE)
			handle_pipe(token_h, input, &i);
		else if (catalog_inputs(input, &i) == INPUT)
			handle_input(token_h, input, &i);
		else if (catalog_inputs(input, &i) == OUTPUT)
			handle_output(token_h, input, &i);
		else if (catalog_inputs(input, &i) == HEREDOC)
			handle_heredoc(token_h, input, &i);
		else if (catalog_inputs(input, &i) == APPEND)
			handle_append(token_h, input, &i);
		else if (catalog_inputs(input, &i) == ERROR)
		{
			found_sintaxe(input, token_tail, token_h);
			return ;
		}
		i++;
	}
}
