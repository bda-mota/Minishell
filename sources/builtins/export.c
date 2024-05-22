#include "../../includes/minishell.h"

/*
1. Antes de encerrar o programa ainda há a necessidade de liberar a matriz com as variáveis de ambiente
do nosso BabyShell -> usar estrutura do main;
2. Esta é apenas a estrutura da criação de novas variáveis -> ela precisa ser ajustada assim como
as outras builtins.
3. Ao final do arquivo há um main teste para verificar o funcionamento da export separadamente do BabyShell.
*/

char	**export(char *new_variable)
{
	char	**original_environ;
	char	**new_environ;

	original_environ = copy_environ();
	new_environ = add_variable_to_environ(original_environ, new_variable);
	if (!new_environ)
	{
		ft_free_matrix(original_environ);
		return (NULL);
	}
	return (new_environ);
}
