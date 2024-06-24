/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:49:18 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/24 09:01:50 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*aux_expand_variable(char *content, char **env_copy)
{
	char	*data_var;
	char	quote;
	int		i;

	data_var = ft_strdup("");
	i = 0;
	quote = 0;
	while (content[i])
	{
		if (content[i] == '\'' || content[i] == '"')
			data_var = handle_quote(content, data_var, &quote, i);
		else if (content[i] == '$' && (quote != '\'' || quote == '"'))
		{
			if (content[i + 1] == '\0' || content[i + 1] == ' '
				|| content[i + 1] == quote)
				data_var = concatened_content(content, data_var, i);
			else
				data_var = find_variable(content, &i, env_copy, data_var);
		}
		else
			data_var = concatened_content(content, data_var, i);
		i++;
	}
	return (data_var);
}

char	*find_variable(char *content, int *i, char **env_copy, char *data_var)
{
	char	*var_name;
	int		start;
	int		end;

	start = (*i) + 1;
	end = find_variable_end(content, start);
	var_name = ft_strndup(content + start, end - start);
	if (syntax_name_in_expansion(var_name) != 0)
	{
		data_var = handle_syntax_error(data_var, var_name);
		*i = end - 1;
		return (data_var);
	}
	data_var = expand_variable_data(data_var, env_copy, var_name);
	free(var_name);
	*i = end - 1;
	return (data_var);
}

int	find_variable_end(char *content, int start)
{
	int	end;

	end = start;
	while (content[end] && content[end] != ' '
		&& content[end] != '$' && content[end] != '"' && content[end] != '\'')
		end++;
	return (end);
}

char	*handle_syntax_error(char *data_var, char *var_name)
{
	char	*tmp;

	tmp = data_var;
	data_var = ft_strjoin(data_var, "$");
	free(tmp);
	tmp = data_var;
	data_var = ft_strjoin(data_var, var_name);
	free(tmp);
	free(var_name);
	return (data_var);
}

char	*expand_variable_data(char *data_var, char **env_copy, char *var_name)
{
	char	*expand_variable;
	char	*tmp;

	expand_variable = ft_getenv(env_copy, var_name);
	if (expand_variable)
	{
		tmp = data_var;
		data_var = ft_strjoin(data_var, expand_variable);
		free(tmp);
		if (var_name[0] == '?')
			free(expand_variable);
	}
	return (data_var);
}
