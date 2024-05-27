#include "../../includes/minishell.h"

void	echo(char *args)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
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
		ft_printf_fd("%c", args[i]);
		i++;
	}
	if (!flag)
		ft_printf_fd("\n");
}
