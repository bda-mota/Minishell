#include "../../includes/minishell.h"

int	ft_strlen_without_quotes(const char *str)
{
	int		len;
	int		simple_quote;
	int		double_quote;

	len = 0;
	simple_quote = 0;
	double_quote = 0;
	while (*str)
	{
		if (quotes(*str, &simple_quote, &double_quote))
		{
			str++;
			continue ;
		}
		len++;
		str++;
	}
	return (len);
}

void	ft_strcpy_without_quotes(char *dest, const char *src)
{
	while (*src)
	{
		if (*src != '"' && *src != '\'')
		{
			*dest = *src;
			dest++;
		}
		src++;
	}
	*dest = '\0';
}

char	**create_new_environ(char **environ_copy, int num_vars)
{
	int		i;
	char	**new_environ;

	i = 0;
	new_environ = ft_calloc(num_vars + 2, sizeof(char *));
	if (!new_environ)
		return (NULL);
	while (i < num_vars)
	{
		new_environ[i] = environ_copy[i];
		i++;
	}
	return (new_environ);
}
