#include "../../includes/minishell.h"

int	quotes(char c, int *simple_quote, int *double_quote)
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
	if (args[*i] == '-')
	{
		(*i)++;
		while (args[*i] == 'n')
			(*i)++;
		if (args[*i] == ' ' || args[*i] == '\0')
		{
			while (args[*i] == ' ')
				(*i)++;
			return (1);
		}
		else
		{
			*i = 0;
			return (0);
		}
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
		ft_printf_fd(STDOUT_FILENO, "%c", args[i]);
		i++;
	}
	if (!flag)
		ft_printf_fd(STDOUT_FILENO, "\n");
}
