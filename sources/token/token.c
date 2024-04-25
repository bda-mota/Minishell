#include "../../includes/minishell.h"

// static void	catalog_inputs(t_token **token_h, char c)
// {
// 	t_token	*curr;

// 	curr = *token_h;

// 	if (ft_isspace(c) == 1)
// 		(*token_h)->type = SPACE;
// 	else if (c == '|')
// 		(*token_h)->type = PIPE;
// 	else if (c == '<')
// 		(*token_h)->type = INPUT;
// 	else if (c == '>')
// 		(*token_h)->type = OUTPUT;
// 	else
// 		(*token_h)->type = WORD;
// }

void	course_inputs(t_token **token_h, char *input)
{
	t_token	*curr;
	char	*token;
	int		i;
	int		size;

	i = 0;
	size = 0;
	curr = *token_h;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\0')
		{
			token = ft_substr(input, (i - size), size);
			insert_token(token_h, token);
			free(token);
			size = 0;
			i++;
		}
		i++;
		size++;
	}
	if (size > 0)
	{
		token = strndup(input + i - size, size);
		insert_token(token_h, token);
		free(token);
	}
}
