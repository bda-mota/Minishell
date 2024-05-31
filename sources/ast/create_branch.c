#include "../../includes/minishell.h"

t_tree  *create_branch(t_token **token_list, int type)
{
    t_tree  *new_branch;

    new_branch = ft_calloc(sizeof(t_tree), 1);
    if(!new_branch)
        return (NULL);
    new_branch->type = type;
    new_branch->content = ft_strdup(token_list[1]->content);
    if (type == REDIRECT)
    {
        new_branch->right = ft_calloc(1, sizeof(t_tree));
        if (!new_branch->right)
        {
            free(new_branch->content);
            free(new_branch);
            return (NULL);
        }
        new_branch->right->type = ARCHIVE;
        new_branch->right->content = ft_strdup(token_list[2]->content);
    }
    return (new_branch);
}