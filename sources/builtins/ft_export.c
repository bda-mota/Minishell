#include "../../includes/minishell.h"

static char	*extract_string(char *input)
{
	char	*substring;
	int		i;

	i = 0;
	substring = NULL;
	while (input[i] != '\0' && input[i] != '|'
		&& input[i] != '<' && input[i] != '>'
		&& !(input[i] == '<' && input[i + 1] == '<')
		&& !(input[i] == '>' && input[i + 1] == '>'))
	{
		i++;
	}
	while (i > 0 && input[i - 1] == ' ')
		i--;
	substring = ft_calloc(i + 1, 1);
	if (!substring)
		return (NULL);
	ft_strncpy(substring, input, i);
	return (substring);
}

void	ft_export(char **env_copy, char *new_variable)
{
	char	*extracted;

	extracted = extract_string(new_variable);
	if (extracted == NULL)
		return ;
	if (ft_strcmp(extracted, "export") == 0)
		print_variables(env_copy);
	else
		change_variables(extracted);
	free(extracted);
}

void	change_variables(char *new_variable)
{
	int		args;
	int		start;
	char	**environ;
	int		simple_quote;
	int		double_quote;

	args = 0;
	start = 0;
	environ = NULL;
	simple_quote = 0;
	double_quote = 0;
	if (ft_strncmp(new_variable, "export ", 7) == 0)
		args += 7;
	while (new_variable[args])
	{
		environ = *get_env_copy(NULL);
		start = args;
		while (new_variable[args]
			&& (new_variable[args] != ' ' || simple_quote || double_quote))
		{
			quotes(new_variable[args], &simple_quote, &double_quote);
			args++;
		}
		if (start != args)
			processed_var(environ, new_variable, start, args);
		if (new_variable[args] != '\0')
			args++;
	}
}

void	print_variables(char	**env_copy)
{
	int		i;
	char	*signal;

	i = 0;
	order_env(env_copy);
	while (env_copy[i])
	{
		signal = ft_strchr(env_copy[i], '=');
		if (signal)
		{
			printf("declare -x %.*s", (int)(signal - env_copy[i]), env_copy[i]);
			printf("=\"%s\"\n", signal + 1);
		}
		else
			printf("declare -x %s\n", env_copy[i]);
		i++;
	}
}

void	order_env(char **env_copy)
{
	int	i;
	int	j;

	i = 0;
	while (env_copy[i])
	{
		j = i + 1;
		while (env_copy[j])
		{
			if (ft_strncmp(env_copy[i],
					env_copy[j], ft_strlen(env_copy[i])) > 0)
				swap_strings(&env_copy[i], &env_copy[j]);
			j++;
		}
		i++;
	}
}

void	swap_strings(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}
