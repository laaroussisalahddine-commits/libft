#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    void *new_content;
    t_list *new_node;
    t_list *new_list = NULL;


    if(lst == NULL)
        return(NULL);
    while(lst != NULL)
    {
        new_content = f(lst -> content);
        if(new_content == NULL)
        {
            ft_lstclear(&new_list,del);
            return(NULL);
        }
        new_node = ft_lstnew(new_content); 
        if(new_node == NULL)
        {
            del(new_content);
            ft_lstclear(&new_list,del);
            return(NULL);
        }

        ft_lstadd_back(&new_list,new_node);
        lst = lst -> next;
    }

    return(new_list);
}
