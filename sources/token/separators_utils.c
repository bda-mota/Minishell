#include "../../includes/minishell.h"

void	handle_hp(t_token **token_h, char *input, size_t *i)
{
	size_t	j;
	char	*token;

	j = 0;
	token = ft_calloc(sizeof(char), 3);
	if (!token)
		return ;
	while (input[*i] && j < 2)
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token);
}
