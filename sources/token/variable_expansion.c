/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:49:12 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:49:14 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*concatened_content(char *content, char *data_var, int i)
{
	char	*temp;
	char	*new_data_var;

	temp = ft_strndup(&content[i], 1);
	new_data_var = ft_strjoin(data_var, temp);
	free(temp);
	free(data_var);
	data_var = new_data_var;
	return (new_data_var);
}

char	*handle_quote(char *content, char *data_var, char *quote, int i)
{
	if (*quote == 0)
		*quote = content[i];
	else if (*quote == content[i])
		*quote = 0;
	return (concatened_content(content, data_var, i));
}
