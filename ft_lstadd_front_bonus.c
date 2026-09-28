#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list *perv;

    perv = *lst;
    new -> next = perv;

    *lst = new;

}
