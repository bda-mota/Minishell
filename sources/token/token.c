#include "../../includes/minishell.h"

int	catalog_inputs(char *c, size_t *i)
{
	if (ft_isspace(c[*i]) == 1)
		return (SSPACE);
	else if (ft_strnchr(&c[*i], '|', 1) == 1)
		return (PIPE);
	else if (ft_strnchr(&c[*i], '"', 1) == 1)
		return (DOUBLE);
	// else if (c == '<')
	// 	return (INPUT);
	// else if (c == '>')
	// 	return (OUTPUT);
	else
		return (WORD);
}

void	course_inputs(t_token **token_h, char *input)
{
	size_t	i;
	size_t	size;

	i = 0;
	while (input[i] && (i != ft_strlen(input)))
	{
		size = ft_handle_quote(input, &i);
		if (size != 0)
			handle_quote(token_h, input, &i, size);
		else if (catalog_inputs(input, &i) == WORD)
			handle_word(token_h, input, &i);
		else if (catalog_inputs(input, &i) == PIPE)
			handle_inputs(token_h, input, &i);
		else if (catalog_inputs(input, &i) == INPUT)
			handle_inputs(token_h, input, &i);
		else if (catalog_inputs(input, &i) == OUTPUT)
			handle_inputs(token_h, input, &i);
		else if (catalog_inputs(input, &i) == SSPACE)
			continue ;
		i++;
	}
}