#include "../../includes/minishell.h"

char	*my_getenv(char **env_copy, char *var)
{
	int	i;
	int	len;

	i = 0;
	len = strlen(var);
	while (env_copy[i])
	{
		if (strncmp(env_copy[i], var, len) == 0 && env_copy[i][len] == '=')
			return (env_copy[i] + len + 1);
		i++;
	}
	return (NULL);
}

void	expand_variable(t_token **token, char **env_copy)
{
	t_token	*curr;
	char	*expand_variable;
	char	*expand_content;

	curr = *token;
	while (curr)
	{
		if (curr->content[0] == '$')
		{
			expand_variable = my_getenv(env_copy, curr->content + 1);
			if (expand_variable)
				expand_content = ft_strdup(expand_variable);
			free (curr->content); // eu preciso liberar memória antes de readicionar memória na nó do token
			curr->content = expand_content;
		}
		curr = curr->next;
	}
}
