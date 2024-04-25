#include "../../includes/minishell.h"

// static int	catalog_inputs(char c)
// {
// 	if (ft_isspace(c) == 1)
// 		return (SSPACE);
// 	else if (c == '|')
// 		return (PIPE);
// 	else if (c == '<')
// 		return (INPUT);
// 	else if (c == '>')
// 		return (OUTPUT);
// 	else
// 		return (WORD);
// }

void	course_inputs(t_token **token_h, char *input)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (input[i] && (i != ft_strlen(input)))
	{
		size = ft_handle_quote(input, &i);
		if (size > 0)
			insert_token(token_h, input);
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
