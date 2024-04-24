#include "../includes/minishell.h"

int	main(void)
{
	t_token	*token_t;
	t_token	*token_h;

	init_token(&token_t, &token_h);
	insert_token(&token_t, "bia");
	insert_token(&token_t, "B1");
	insert_token(&token_t, "B2");
	print_list(&token_h);
	deallocate_lst(&token_t, &token_h);
	exit(1);
}

	//char	*retorno;

	/*while (1)
	{
		retorno = readline("$minishell: ");
		if (retorno == NULL)
		{
			printf("Erro ao ler a linha\n");
			continue ;
		}
		if (ft_strcmp(retorno, "exit") == 0)
			break ;
		insert_token(&token, retorno);
		printf("token: %s\n", retorno);
		free(retorno);
	}*/
