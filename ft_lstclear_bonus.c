#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *perv;

    while(*lst != NULL)
    {
        perv = (*lst )-> next;
        del((*lst) -> content);
        free((*lst));
        *lst = perv;
    }

}