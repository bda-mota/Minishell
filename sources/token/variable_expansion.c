#include "../../includes/minishell.h"

char	*ft_getenv(char **env_copy, char *var)
{
	int		status;
	char	*status_str;
	char	*result;
	int		i;
	int		len;

	i = 0;
	status = 0;
	len = ft_strlen(var);
	if (var[0] == '?')
	{
		status = get_status(-1);
		status_str = ft_itoa(status);
		result = ft_strjoin(status_str, var + 1);
		free(status_str);
		return (result);
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

char	*process_character(char *content, int i, char *data_var, char quote)
{
	char	*temp;
	char	*new_data_var;

	if (content[i] == '"' && quote == '"')
		return (data_var);
	temp = ft_strndup(&content[i], 1);
	new_data_var = ft_strjoin(data_var, temp);
	free(temp);
	free(data_var);
	return (new_data_var);
}

// char	*aux_expand_variable(char *content, char **env_copy)
// {
// 	char	*data_var;
// 	int		i;
// 	char	quote;

// 	data_var = ft_strdup("");
// 	i = 0;
// 	quote = 0;
// 	while (content[i])
// 	{
// 		if (content[i] == '\'')
// 		{
// 			if (quote == 0)
// 				quote = content[i];
// 			else if (quote == content[i])
// 				quote = 0;
// 		}
// 		else if (content[i] == '$' && content[i + 1] != '\0' && quote != '\'')
// 			data_var = find_variable(content, &i, env_copy, data_var);
// 		else
// 			data_var = process_character(content, i, data_var, quote);
// 		i++;
// 	}
// 	return (data_var);
// }

char	*aux_expand_variable(char *content, char **env_copy)
{
	char	*data_var;
	char	*tmp;
	int		i;
	char	quote;

	data_var = ft_strdup("");
	i = 0;
	quote = 0;
	while (content[i])
	{
		if (content[i] == '\'')
		{
			if (quote == 0)
				quote = content[i];
			else if (quote == content[i])
				quote = 0;
		}
		else if (content[i] == '"')
		{
			if (quote == 0)
				quote = content[i];
			else if (quote == content[i])
				quote = 0;
		}
		else if (content[i] == '$' && quote != '\'')
		{
			if (content[i + 1] == '"'
				|| content[i + 1] == '\0' || content[i + 1] == ' ')
			{
				tmp = data_var;
				data_var = ft_strjoin(data_var, "$");
				free(tmp);
			}
			else
				data_var = find_variable(content, &i, env_copy, data_var);
		}
		else
			data_var = process_character(content, i, data_var, quote);
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
	while (content[end] && content[end] != ' '
		&& content[end] != '$' && content[end] != '"')
		end++;
	var_name = ft_strndup(content + start, end - start);
	expand_variable = ft_getenv(env_copy, var_name);
	if (expand_variable)
	{
		tmp = data_var;
		data_var = ft_strjoin(data_var, expand_variable);
		free(tmp);
		if (var_name[0] == '?')
			free(expand_variable);
	}
	free(var_name);
	*i = end - 1;
	return (data_var);
}

