#include "../../includes/minishell.h"

/*
1. environ não sera utilizada, apenas foi implementada aqui pois no meu Ubuntu 
ela não aparece como uma macro de ambiente na 42 ela aparece e deve ser modificada.
2. Antes de encerrar o programa ainda há a necessidade de liberar a matriz com as variáveis de ambiente
do nosso BabyShell -> usar estrutura do main;
3. Esta é apenas a estrutura da criação de novas variáveis -> ela precisa ser ajustada assim como
as outras builtins.
*/

char    **export(char *new_variable)
{
    char **original_environ;
    char **new_environ;

    original_environ = copy_environ();
    new_environ = add_variable_to_environ(original_environ, new_variable);
    if (!new_environ)
    {
        free_environ(original_environ);
        return (NULL);
    }
    return (new_environ);
}
/*
int main() 
{

    char    **env;
    char    **tmp;

    env = export("NEW_VALUE=42");
    tmp = env;
    while (*tmp) 
    {
        printf("%s\n", *tmp);
        tmp++;
    }
    free_environ(env);
    return 0;
}
*/