#include "../../includes/minishell.h"

char	*my_getenv(char **env_copy, char *var)
{
	int status;
	char *status_str;
	int	i;
	int	len;

	i = 0;
	status = 0;
	len = ft_strlen(var);
	if (ft_strcmp(var, "?") == 0)
	{
    	status = get_status(-1);
		status_str = ft_itoa(status);
    	return (status_str);
	}
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], var, len) == 0 && env_copy[i][len] == '=')
			return (env_copy[i] + len + 1);
		i++;
	}
	return (NULL);
}

void	expand_variable(t_token **token, char **env_copy)
{
	t_token		*curr;
	char		*expanded_content;

	curr = *token;
	while (curr)
	{
		expanded_content = aux_expand_variable(curr->content, env_copy);
		free(curr->content);
		curr->content = expanded_content;
		curr = curr->next;
	}
}

char	*aux_expand_variable(char *content, char **env_copy)
{
	char	*data_var;
	char	*temp;
	char	*new_data_var;
	int		i;

	data_var = ft_strdup("");
	i = 0;
	while (content[i])
	{
		if (content[i] == '$')
			data_var = find_variable(content, &i, env_copy, data_var);
		else
		{
			temp = ft_strndup(&content[i], 1);
			new_data_var = ft_strjoin(data_var, temp);
			free(temp);
			free(data_var);
			data_var = new_data_var;
		}
		i++;
	}
	return (data_var);
}

char	*find_variable(char *content, int *i, char **env_copy, char *data_var)
{
	char	*var_name;
	char	*expand_variable;
	char	*tmp;
	int		start;
	int		end;

	start = (*i) + 1;
	end = start;
	while (content[end] && content[end] != ' ' && content[end] != '$')
		end++;
	var_name = ft_strndup(content + start, end - start);
	expand_variable = my_getenv(env_copy, var_name);
	if (expand_variable)
	{
		tmp = data_var;
		data_var = ft_strjoin(data_var, expand_variable);
		free(tmp);
	 	if (ft_strcmp(var_name, "?") == 0)
            free(expand_variable);
	}
	free(var_name);
	*i = end - 1;
	return (data_var);
}
