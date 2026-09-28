#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int count_lst;
    t_list  *current;

    count_lst = 0;
    current = lst;
    while(current != NULL)
    {
        count_lst++;
        current = current -> next;
    }
    return(count_lst);
}
