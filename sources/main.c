#include "../includes/minishell.h"

int	main(void)
{
	t_token	*token;
	char	*retorno;

	token = NULL;
	while (1)
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
		printf("%s\n", retorno);
		free(retorno);
	}
	deallocate_lst(&token);
	exit(1);
}
