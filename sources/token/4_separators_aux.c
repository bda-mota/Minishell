#include "../../includes/minishell.h"

int	check_sintax(char *input, t_token **token_tail, t_token **token_h)
{
	size_t size_simple;
	size_t	size_double;

	size_simple = 
	if (!check_blocks(input, token_tail, token_h))
		return (1);
	if (!check_double_quotes(input, token_tail, token_h))
		return (1);
	return (0);
}
