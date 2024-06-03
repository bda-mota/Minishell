#include "../../includes/minishell.h"

static int	quotes(char c, int *simple_quote, int *double_quote)
{
	if (c == '"')
	{
		if (!(*simple_quote))
		{
			*double_quote = !(*double_quote);
			return (1);
		}
	}
	if (c == '\'')
	{
		if (!(*double_quote))
		{
			*simple_quote = !(*simple_quote);
			return (1);
		}
	}
	return (0);
}

static int	check_n_flag(char *args, int *i)
{
	if (ft_strncmp(args + *i, "-n", 2) == 0
		&& (args[*i + 2] == ' ' || args[*i + 2] == '\0'))
	{
		*i += 2;
		while (args[*i] == ' ')
			(*i)++;
		return (1);
	}
	return (0);
}

void	ft_echo(char *args)
{
	int	i;
	int	flag;
	int	simple_quote;
	int	double_quote;

	i = 0;
	flag = check_n_flag(args, &i);
	simple_quote = 0;
	double_quote = 0;
	while (args[i])
	{
		if (quotes(args[i], &simple_quote, &double_quote))
		{
			i++;
			continue ;
		}
		ft_printf_fd("%c", args[i]);
		i++;
	}
	if (!flag)
		ft_printf_fd("\n");
}
