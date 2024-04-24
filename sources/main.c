#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	t_token	*token;
	int		i;

	i = 1;
	(void)argc;
	token = NULL;
	while (argv[i])
	{
		insert_token(&token, argv[i]);
		i++;
	}
	deallocate_lst(&token);
	return (0);
}
