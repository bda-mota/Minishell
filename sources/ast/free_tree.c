#include "../../includes/minishell.h"

void    free_leaves(t_tree *root)
{
    if (root == NULL)
        return ;
    if (root->left == NULL && root->right == NULL)
    {
        free(root->content);
        free(root);
        return ;
    }
    free_leaves(root->left);
    free_leaves(root->right);
    root->left = NULL;
    root->right = NULL;
}

void    free_tree(t_tree *root)
{
    if (!root)
        return ;
    free_leaves(root);
    free(root);
}
