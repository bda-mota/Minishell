#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

void	find_path(t_exec **execution);
void	build_path(t_exec **execution);
char	*add_command_to_path(t_exec **execution, char *cmd);
char	*get_expand_variable(t_token **token);

#endif
