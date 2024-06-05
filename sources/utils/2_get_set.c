#include "../../includes/minishell.h"

int	get_status(int status)
{
	static int	new_status;

	if (status != -1)
		new_status = status;
	return (new_status);
}
