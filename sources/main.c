#include "../includes/minishell.h"

static void	read_line(t_token **token_t, t_token **token_h);

int	main(void)
{
	t_token	*token_t;
	t_token	*token_h;


	init_token(&token_t, &token_h);
	read_line(&token_t, &token_h);
	print_list(&token_t);
	deallocate_lst(&token_t, &token_h);
	exit(1);
}

static void	read_line(t_token **token_t, t_token **token_h)
{
	char	*input;

	(void)token_t;
	while (1)
	{
		input = readline("$minishell: ");
		if (input == NULL)
		{
			printf("Erro ao ler a linha\n");
			continue ;
		}
		if (ft_strcmp(input, "exit") == 0)
		{
			free(input);
			return ;
		}
		insert_token(token_h, input);
		free(input);
	}
}
