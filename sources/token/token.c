#include "../../includes/minishell.h"

int	catalog_inputs(char c)
{
	if (ft_isspace(c) == 1)
		return (SSPACE);
	else if (ft_strcmp(&c, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(&c, "<") == 0)
		return (INPUT);
	else if (ft_strcmp(&c, ">") == 0)
		return (OUTPUT);
	else
		return (WORD);
}

void	course_inputs(t_token **token_h, char *input)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (input[i] && (i != ft_strlen(input)))
	{
		size = ft_handle_quote(input, i);
		if (size != 0)
			handle_word(token_h, input, &i);
		//criar função para criar a substr e malocar a palavra
		//mandar o resultado para insert_token
		//serão vários if, para cada if faz uma ação e volta o loop
		//retirar as vírgulas
		i++;
	}
}

/*
if (input[i] == ' ' || input[i] == '\0')
		{
			token = ft_substr(input, (i - size), size);
			insert_token(token_h, token);
			free(token);
			size = 0;
			i++;
		}
*/
