#include "../../includes/minishell.h"

static int	count_len_block(char *input, size_t i);

static int	count_len_block(char *input, size_t i)
{
	size_t	block;
	size_t	len;

	block = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == '(')
			block++;
		if (input[i] == ')')
			block--;
		i++;
		len++;
		if (block == 0)
			break ;
	}
	return (len);
}

void	handle_block(t_token **token, char *input, size_t *i)
{
	size_t	j;
	size_t	len;
	char	*content;

	j = 0;
	len = count_len_block(input, *i);
	content = ft_calloc(sizeof(char), len + 1);
	if (!content)
		return ;
	while (input[*i] && j < len)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, BLOCK));
}
