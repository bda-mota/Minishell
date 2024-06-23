/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:49:18 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:49:19 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	valid_name(char *var_name);
static char	*handle_valid_variable(char *data_var, char **env_copy, char *var_name);
static char *extract_var_name(char *content, int *i);
static char	*concatenate_invalid_variable(char *data_var, char *var_name);

char *find_variable(char *content, int *i, char **env_copy, char *data_var)
{
    char *var_name;

    var_name = extract_var_name(content, i);
    if (var_name == NULL)
        return (data_var);
    if (valid_name(var_name) == 0)
        data_var = handle_valid_variable(data_var, env_copy, var_name);
    else
        data_var = concatenate_invalid_variable(data_var, var_name);
    free(var_name);
    return (data_var);
}

static char *extract_var_name(char *content, int *i)
{
    int start;
    int end;
    char *var_name;

    start = *i + 1;
    end = start;
    while (content[end] && content[end] != ' ' && content[end] != '$' && content[end] != '"' && content[end] != '\'')
        end++;
    var_name = ft_strndup(content + start, end - start);
    if (var_name == NULL)
        return (NULL);
    *i = end - 1;
    return (var_name);
}

static int	valid_name(char *var_name)
{
	int	i;

	if (var_name[0] == '?' && var_name[1] == '\0')
		return (0);
	i = 0;
	if (var_name[i] != '_' && !ft_isalpha(var_name[i]))
		return (1);
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

static char	*handle_valid_variable(char *data_var, char **env_copy, char *var_name)
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
	else
		data_var = concatenate_invalid_variable(data_var, var_name);
	return (data_var);
}

static char *concatenate_invalid_variable(char *data_var, char *var_name)
{
    char *tmp;
    char *new_data_var;

    new_data_var = ft_strjoin(data_var, "$");
    free(data_var);
    tmp = new_data_var;
    new_data_var = ft_strjoin(new_data_var, var_name);
    free(tmp);
    return (new_data_var);
}
