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
	else
		return (WORD);
}

void	tokenizer(t_minishell *shell)
{
	size_t	i;
	int		type;

	i = 0;
	if (!check_sintax(shell->input))
		return ;
	while (shell->input[i] && (i != ft_strlen(shell->input)))
	{
		type = catalog_inputs(shell->input, &i);
		if (type == WORD || type == DOUBLE || type == SIMPLE)
			handle_word(&shell->token, shell->input, &i);
		else if (type == PIPE || type == INPUT || type == OUTPUT)
			handle_one(&shell->token, shell->input, &i);
		else if (type == HEREDOC || type == APPEND)
			handle_two(&shell->token, shell->input, &i);
		i++;
	}
}
