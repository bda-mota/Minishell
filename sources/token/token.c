#include "../../includes/minishell.h"

int	catalog_inputs(char c)
{
	if (ft_isspace(c) == 1)
		return (SSPACE);
	else if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (INPUT);
	else if (c == '>')
		return (OUTPUT);
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
		size = ft_handle_quote(input, i);
		if (size != 0)
			handle_word(token_h, input, &i, size);
		else if (catalog_inputs(input[i]) == WORD)
			handle_word(token_h, input, &i, size);
		else if (catalog_inputs(input[i]) == PIPE)
			handle_inputs(token_h, input, &i);
		else if (catalog_inputs(input[i]) == INPUT)
			handle_inputs(token_h, input, &i);
		else if (catalog_inputs(input[i]) == OUTPUT)
			handle_inputs(token_h, input, &i);
		//serão vários if, para cada if faz uma ação e volta o loop
		i++;
	}
}

/*
if (input[i] == ' ' || input[i] == '\0')
		{
			token = ft_substr(input, (i - size), size);
			insert_token(token_h, token);
			free(token);
			size = 0;
			i++;
		}
*/
