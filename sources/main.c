#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	t_token	*token;
	t_token	*curr;
	int		i;

	i = 1;
	(void)argc;
	token = NULL;
	while (argv[i])
	{
		insert_token(&token, argv[i]);
		i++;
	}
	curr = token;
	while (curr)
	{
		printf("arg: %s \n", curr->content);
		curr = curr->next;
	}
	return (0);
}
