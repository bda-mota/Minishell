#include "../../includes/minishell.h"

int	catalog_inputs(char *c)
{
	if (ft_isspace(*c) == 1)
		return (SSPACE);
	else if (ft_strnchr(c, '|', 1) == 1)
		return (PIPE);
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
		size = ft_handle_quote(input);
		if (size != 0)
			handle_quote(token_h, input, &i, size);
		else if (catalog_inputs(input) == WORD)
			handle_word(token_h, input, &i);
		else if (catalog_inputs(*input) == PIPE)
			handle_inputs(token_h, input, &i);
		else if (catalog_inputs(*input) == INPUT)
			handle_inputs(token_h, input, &i);
		else if (catalog_inputs(*input) == OUTPUT)
			handle_inputs(token_h, input, &i);
		else if (catalog_inputs(*input) == SSPACE)
			continue ;
		i++;
	}
}
