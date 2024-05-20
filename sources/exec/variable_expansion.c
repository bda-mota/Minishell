#include "../../includes/minishell.h"

// Reorganizar para procurar na cópia da lista de variáveis, para que a getenv
// aponte para esta lista não para as variáveis de ambiente __environ
// implementar diferenças de variável passada entre '' e ""

char	*get_expand_variable(t_token **token)
{
	t_token	*curr;
	char	*expand_variable;

	curr = *token;
	while (curr)
	{
		expand_variable = getenv(curr->content + 1);
		if(expand_variable)
			ft_printf_fd("%s\n", expand_variable);
		curr = curr->next;
	}
	return (0);
}
