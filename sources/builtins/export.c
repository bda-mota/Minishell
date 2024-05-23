#include "../../includes/minishell.h"

/*
1. Antes de encerrar o programa ainda há a necessidade de liberar a matriz com as variáveis de ambiente
do nosso BabyShell -> usar estrutura do main;
2. Esta é apenas a estrutura da criação de novas variáveis -> ela precisa ser ajustada assim como
as outras builtins.
*/

void	export(char *new_variable, t_exec **env)
{
	char	**original_environ;
	int		i;

	i = 0;
	original_environ = copy_environ();
	(*env)->env_copy = add_variable_to_environ(original_environ, new_variable);
	if (!(*env)->env_copy)
	{
		ft_free_matrix(original_environ);
		return ;
	}
}
