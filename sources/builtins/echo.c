#include "../../includes/minishell.h"

void	echo(char *args)
{
	int	i;
	int	flag;
	int	simple_quote;
	int	double_quote;

	i = 0;
	flag = 0;
	simple_quote = 0;
	double_quote = 0;
	while (args[i] == ' ')
		i++;
	if (ft_strncmp(args + i, "-n", 2) == 0
		&& (args[i + 2] == ' ' || args[i + 2] == '\0'))
	{
		flag = 1;
		i += 2;
		while (args[i] == ' ')
			i++;
	}
	while (args[i])
	{
		if (args[i] == '"')
		{
			if (!simple_quote)
			{
				double_quote = 1;
				i++;
			}
		}
		if (args[i] == '\'')
		{
			if (!double_quote)
			{
				simple_quote = 1;
				i++;
			}
		}
		ft_printf_fd("%c", args[i]);
		i++;
	}
	if (!flag)
		ft_printf_fd("\n");
}

// void	echo(char *args)
// {
// 	int	i;
// 	int	flag;

// 	i = 0;
// 	flag = 0;
// 	while (args[i] == ' ')
// 		i++;
// 	if (ft_strncmp(args + i, "-n", 2) == 0
// 		&& (args[i + 2] == ' ' || args[i + 2] == '\0'))
// 	{
// 		flag = 1;
// 		i += 2;
// 		while (args[i] == ' ')
// 			i++;
// 	}
// 	while (args[i])
// 	{
// 		if (args[i] == ' ' && args[i + 1] == ' ')
// 			i++;
// 		ft_printf_fd("%c", args[i]);
// 		i++;
// 	}
// 	if (!flag)
// 		ft_printf_fd("\n");
// }
